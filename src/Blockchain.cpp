#include "Blockchain.h"
#include "Logger.h"
#include <openssl/sha.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace CryptoNote {

Blockchain::Blockchain() : difficultyTarget(60), blockReward(50000), rewardHalvingInterval(210000), totalCoins(1000000000), exchangeRate(0.40), reserveEur(0), circulatingSupply(0) {
    Logger::log("Blockchain initialized");
    Logger::log("WARNING: Keep your private key secure to prevent unauthorized access!");
}

void Blockchain::initialize(const std::string& configFile) {
    std::ifstream file(configFile);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file: " + configFile);
    }

    std::string line;
    while (std::getline(file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            if (key == "difficulty-target") difficultyTarget = std::stoull(value);
            else if (key == "genesis-block-reward") blockReward = std::stoull(value);
            else if (key == "reward-halving-interval") rewardHalvingInterval = std::stoull(value);
            else if (key == "total-coins") totalCoins = std::stoull(value);
            else if (key == "exchange-rate") exchangeRate = std::stod(value);
            else if (key == "reserve-initial-eur") reserveEur = std::stod(value);
        }
    }
    file.close();

    Block genesis;
    genesis.timestamp = time(nullptr);
    genesis.previousHash = "0";
    genesis.nonce = 0;
    genesis.transactions = {};
    genesis.reward = blockReward;
    genesis.hash = calculateHash(genesis);
    chain.push_back(genesis);
    circulatingSupply += blockReward;
    Logger::log("Genesis block created with hash: " + genesis.hash);
    Logger::log("Exchange rate set to: 1 EBK = " + std::to_string(exchangeRate) + " EUR");
    Logger::log("Initial reserve set to: " + std::to_string(reserveEur) + " EUR");
}

bool Blockchain::addBlock(Block& block) {
    if (!validateBlock(block)) {
        Logger::log("Block validation failed: " + block.hash);
        return false;
    }

    for (const auto& tx : block.transactions) {
        if (isAccountLocked(tx.from) || isAccountLocked(tx.to)) {
            Logger::log("Transaction failed: Account " + (isAccountLocked(tx.from) ? tx.from : tx.to) + " is locked due to a security breach.");
            return false;
        }
        if (accounts.find(tx.from) == accounts.end()) {
            accounts[tx.from] = {0, time(nullptr), 0.001};
        }
        if (accounts.find(tx.to) == accounts.end()) {
            accounts[tx.to] = {0, time(nullptr), 0.001};
        }
        accounts[tx.from].balance -= tx.amount;
        accounts[tx.to].balance += tx.amount;
        Logger::log("Transaction processed: " + tx.from + " -> " + tx.to + " (" + std::to_string(tx.amount) + " EBK, " + std::to_string(tx.amount * exchangeRate) + " EUR)");
    }

    chain.push_back(block);
    circulatingSupply += blockReward;
    Logger::log("Block added to chain: " + block.hash);
    Logger::log("Circulating supply: " + std::to_string(circulatingSupply) + " EBK");

    adjustReward();
    return true;
}

void Blockchain::adjustReward() {
    double circulatingValueEur = circulatingSupply * exchangeRate;
    if (circulatingValueEur > reserveEur) {
        blockReward = blockReward * (reserveEur / circulatingValueEur);
        Logger::log("Reward adjusted to maintain peg: " + std::to_string(blockReward) + " EBK");
    }

    if (chain.size() % rewardHalvingInterval == 0) {
        blockReward /= 2;
        Logger::log("Block reward halved to: " + std::to_string(blockReward));
    }
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

Blockchain::Block Blockchain::mineBlock(const std::vector<TransactionDetails>& transactions) {
    Block block;
    block.timestamp = time(nullptr);
    block.previousHash = chain.back().hash;
    block.transactions = transactions;
    block.reward = blockReward;
    block.nonce = 0;

    std::string target(difficultyTarget, '0');
    do {
        block.nonce++;
        block.hash = calculateHash(block);
    } while (block.hash.substr(0, difficultyTarget) != target);

    Logger::log("Block mined with hash: " + block.hash + " (nonce: " + std::to_string(block.nonce) + ")");
    return block;
}

uint64_t Blockchain::getBalance(const Address& address) const {
    if (isAccountLocked(address)) {
        Logger::log("Cannot access balance: Account " + address + " is locked due to a security breach.");
        return 0;
    }
    auto it = accounts.find(address);
    if (it == accounts.end()) {
        return 0;
    }
    return it->second.balance;
}

double Blockchain::getBalanceInFiat(const Address& address) const {
    uint64_t balance = getBalance(address);
    return balance * exchangeRate;
}

double Blockchain::getReserve() const {
    return reserveEur;
}

void Blockchain::applyInterest(Address& address) {
    if (isAccountLocked(address)) {
        Logger::log("Cannot apply interest: Account " + address + " is locked due to a security breach.");
        return;
    }
    auto it = accounts.find(address);
    if (it == accounts.end()) {
        throw std::runtime_error("Account not found: " + address);
    }

    BankAccount& account = it->second;
    uint64_t now = time(nullptr);
    uint64_t daysElapsed = (now - account.lastInterestTimestamp) / (24 * 3600);
    if (daysElapsed > 0) {
        uint64_t interest = static_cast<uint64_t>(account.balance * account.interestRate * daysElapsed);
        account.balance += interest;
        account.lastInterestTimestamp = now;
        circulatingSupply += interest;
        Logger::log("Interest applied to " + address + ": new balance = " + std::to_string(account.balance) + " EBK (" + std::to_string(account.balance * exchangeRate) + " EUR)");
        Logger::log("Circulating supply updated: " + std::to_string(circulatingSupply) + " EBK");
        adjustReward();
    }
}

bool Blockchain::detectExternalAccess(const Address& address) {
    accessAttempts[address]++;
    Logger::log("External access attempt detected for address: " + address + " (Attempt #" + std::to_string(accessAttempts[address]) + ")");

    if (accessAttempts[address] >= 1) {
        lockAccount(address);
        return true;
    }
    return false;
}

void Blockchain::lockAccount(const Address& address) {
    uint64_t now = time(nullptr);
    uint64_t lockDuration = 48 * 3600;
    lockExpiration[address] = now + lockDuration;
    Logger::log("CRITICAL: Account " + address + " has been locked due to a security breach. Lock will expire at " + std::to_string(lockExpiration[address]) + " (Unix timestamp).");
    Logger::log("WARNING: Ensure your private key is secure to prevent further unauthorized access!");
}

bool Blockchain::isAccountLocked(const Address& address) const {
    auto it = lockExpiration.find(address);
    if (it == lockExpiration.end()) {
        return false;
    }
    uint64_t now = time(nullptr);
    if (now >= it->second) {
        lockExpiration.erase(address);
        Logger::log("Account " + address + " has been unlocked after the lock period.");
        return false;
    }
    return true;
}

uint64_t Blockchain::getLockExpiration(const Address& address) const {
    auto it = lockExpiration.find(address);
    if (it == lockExpiration.end()) {
        return 0;
    }
    return it->second;
}

std::string Blockchain::calculateHash(const Block& block) const {
    std::stringstream ss;
    ss << block.timestamp << block.previousHash << block.nonce;
    for (const auto& tx : block.transactions) {
        ss << tx.from << tx.to << tx.amount;
    }
    ss << block.reward;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)ss.str().c_str(), ss.str().length(), hash);

    std::stringstream hashStream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return hashStream.str();
}

bool Blockchain::validateBlock(const Block& block) const {
    if (block.previousHash != chain.back().hash) {
        return false;
    }

    std::string target(difficultyTarget, '0');
    if (block.hash.substr(0, difficultyTarget) != target) {
        return false;
    }

    std::string calculatedHash = calculateHash(block);
    return block.hash == calculatedHash;
}

} // namespace CryptoNote
