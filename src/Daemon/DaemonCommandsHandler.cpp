#include "DaemonCommandsHandler.h"
#include "Mixing.h"
#include "Logger.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

namespace CryptoNote {

DaemonCommandsHandler::DaemonCommandsHandler(Blockchain& bc) : blockchain(bc), userAddress("addr123") {
    Logger::log("DaemonCommandsHandler initialized for address: " + userAddress);
}

void DaemonCommandsHandler::balance(const std::string& args) {
    if (blockchain.detectExternalAccess(userAddress)) {
        std::cout << "CRITICAL: Account has been locked due to a detected external access attempt!\n";
        return;
    }

    if (blockchain.isAccountLocked(userAddress)) {
        std::cout << "Account is locked due to a security breach. Unlock time: " << blockchain.getLockExpiration(userAddress) << " (Unix timestamp)\n";
        return;
    }

    uint64_t balance = blockchain.getBalance(userAddress);
    double balanceInFiat = blockchain.getBalanceInFiat(userAddress);
    double reserve = blockchain.getReserve();
    std::cout << "Balance: " << balance << " EBK (" << std::fixed << std::setprecision(2) << balanceInFiat << " EUR)\n";
    std::cout << "Current reserve: " << std::fixed << std::setprecision(2) << reserve << " EUR\n";
    Logger::log("Balance checked for " + userAddress + ": " + std::to_string(balance) + " EBK (" + std::to_string(balanceInFiat) + " EUR)");
}

void DaemonCommandsHandler::send(const std::string& args) {
    if (blockchain.isAccountLocked(userAddress)) {
        std::cout << "Cannot send: Account is locked due to a security breach. Unlock time: " << blockchain.getLockExpiration(userAddress) << " (Unix timestamp)\n";
        return;
    }

    std::istringstream iss(args);
    uint64_t amount;
    Address to;
    iss >> amount >> to;
    if (to.empty()) {
        throw std::runtime_error("Invalid address");
    }
    if (amount <= 0) {
        throw std::runtime_error("Amount must be positive");
    }

    uint64_t balance = blockchain.getBalance(userAddress);
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds");
    }

    TransactionDetails tx;
    tx.from = userAddress;
    tx.to = to;
    tx.amount = amount;
    tx.isMixed = false;

    std::vector<TransactionDetails> txPool = {tx};
    processTransactions(blockchain, txPool);
    double amountInFiat = amount * 0.40;
    std::cout << "Sent " << amount << " EBK (" << std::fixed << std::setprecision(2) << amountInFiat << " EUR) to " << to << "\n";
    Logger::log("Sent " + std::to_string(amount) + " EBK (" + std::to_string(amountInFiat) + " EUR) from " + userAddress + " to " + to);
}

void DaemonCommandsHandler::mix(const std::string& args) {
    if (blockchain.isAccountLocked(userAddress)) {
        std::cout << "Cannot mix: Account is locked due to a security breach. Unlock time: " << blockchain.getLockExpiration(userAddress) << " (Unix timestamp)\n";
        return;
    }
    std::cout << "Mixing activated for next transaction\n";
    Logger::log("Mixing activated for " + userAddress);
}

void DaemonCommandsHandler::interest(const std::string& args) {
    if (blockchain.isAccountLocked(userAddress)) {
        std::cout << "Cannot apply interest: Account is locked due to a security breach. Unlock time: " << blockchain.getLockExpiration(userAddress) << " (Unix timestamp)\n";
        return;
    }
    blockchain.applyInterest(userAddress);
    uint64_t balance = blockchain.getBalance(userAddress);
    double balanceInFiat = blockchain.getBalanceInFiat(userAddress);
    std::cout << "Interest applied. New balance: " << balance << " EBK (" << std::fixed << std::setprecision(2) << balanceInFiat << " EUR)\n";
    Logger::log("Interest applied for " + userAddress);
}

void DaemonCommandsHandler::showchain(const std::string& args) {
    const auto& chain = blockchain.getChain();
    std::cout << "Blockchain (Height: " << chain.size() << "):\n";
    for (size_t i = 0; i < chain.size(); ++i) {
        const auto& block = chain[i];
        std::cout << "Block #" << i << " (Hash: " << block.hash << ")\n";
        std::cout << "  Timestamp: " << block.timestamp << "\n";
        std::cout << "  Previous Hash: " << block.previousHash << "\n";
        std::cout << "  Nonce: " << block.nonce << "\n";
        std::cout << "  Reward: " << block.reward << " EBK (" << std::fixed << std::setprecision(2) << (block.reward * 0.40) << " EUR)\n";
        std::cout << "  Transactions: " << block.transactions.size() << "\n";
        for (const auto& tx : block.transactions) {
            std::cout << "    - " << tx.from << " -> " << tx.to << " (" << tx.amount << " EBK, " << std::fixed << std::setprecision(2) << (tx.amount * 0.40) << " EUR, Mixed: " << (tx.isMixed ? "Yes" : "No") << ")\n";
        }
    }
    Logger::log("Blockchain displayed for " + userAddress);
}

void DaemonCommandsHandler::reserve(const std::string& args) {
    double reserve = blockchain.getReserve();
    std::cout << "Reserve: " << std::fixed << std::setprecision(2) << reserve << " EUR\n";
    Logger::log("Reserve checked: " + std::to_string(reserve) + " EUR");
}

} // namespace CryptoNote
