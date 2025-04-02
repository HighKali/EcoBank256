#ifndef WALLET_H
#define WALLET_H

typedef struct Wallet {
    char* address;
    double balance;
} Wallet;

Wallet* wallet_create(const char* owner);
void wallet_free(Wallet* wallet);

#endif
