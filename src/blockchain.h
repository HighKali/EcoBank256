#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "wallet.h"  // Necessario per definire Wallet

typedef struct Transaction {
    char* sender;
    char* receiver;
    double amount;
    unsigned char* encrypted_data;
    size_t encrypted_len;
} Transaction;

typedef struct Blockchain {
    Transaction** transactions;
    size_t count;
    double interest_rate;
} Blockchain;

Blockchain* blockchain_init(void);
void blockchain_add_transaction(Blockchain* bc, Transaction* tx);
void blockchain_free(Blockchain* bc);
Transaction* transaction_create(Wallet* sender, const char* receiver, double amount);

#endif
