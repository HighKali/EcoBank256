#ifndef BLOCKCHAINEXPLORERDATA_H
#define BLOCKCHAINEXPLORERDATA_H

#include <vector>
#include <string>
#include "CryptoNote.h"

namespace CryptoNote {

struct BankAccount {
    uint64_t balance;
    uint64_t lastInterestTimestamp;
    float interestRate; // es. 0.001 per 0.1% giornaliero
};

struct TransactionDetails {
    // Campi esistenti...
    std::vector<uint8_t> encryptedData; // Dati criptati con AES-256
    BankAccount account; // Aggiunto per conti bancari
};

} // namespace CryptoNote

#endif
