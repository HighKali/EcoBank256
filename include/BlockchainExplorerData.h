#ifndef BLOCKCHAINEXPLORERDATA_H
#define BLOCKCHAINEXPLORERDATA_H

#include <vector>
#include <string>
#include "CryptoNote.h"

namespace CryptoNote {

struct BankAccount {
    uint64_t balance;
    uint64_t lastInterestTimestamp;
    float interestRate;
};

struct MixInput {
    std::string sourceAddress;
    uint64_t amount;
};

struct TransactionDetails {
    std::vector<uint8_t> encryptedData;
    BankAccount account;
    std::vector<MixInput> mixInputs; // Input mixati
    bool isMixed; // Flag per indicare se è una transazione mixata
};

} // namespace CryptoNote

#endif
