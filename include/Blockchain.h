#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include <cstdint>
#include "CryptoNote.h"
#include "BlockchainExplorerData.h"

namespace CryptoNote {

class Blockchain {
public:
    struct Block {
        uint64_t timestamp;
        std::string previousHash;
        std::string hash;
        uint64_t nonce;
        std::vector<TransactionDetails> transactions;
        uint64_t reward;
    };

    Blockchain();
    void initialize(const std::string& configFile);
    bool addBlock(Block& block);
    const std::vector<Block>& getChain() const;
    Block mineBlock(const std::vector<TransactionDetails>& transactions);
    uint64_t getBalance(const Address& address) const;
    double getBalanceInFiat(const Address& address) const;
    void applyInterest(Address& address);
    double getReserve() const;
    bool detectExternalAccess(const Address& address);
    bool isAccountLocked(const Address& address) const;
    uint64_t getLockExpiration(const Address& address) const;

private:
    std::vector<Block> chain;
    std::map<Address, BankAccount> accounts;
    uint64_t difficultyTarget;
    uint64_t blockReward;
    uint64_t rewardHalvingInterval;
    uint64_t totalCoins;
    double exchangeRate;
    double reserveEur;
    uint64_t circulatingSupply;
    std::map<Address, uint64_t> lockExpiration;
    std::map<Address, int> accessAttempts;

    std::string calculateHash(const Block& block) const;
    bool validateBlock(const Block& block) const;
    void adjustReward();
    void lockAccount(const Address& address);
};

} // namespace CryptoNote

#endif
