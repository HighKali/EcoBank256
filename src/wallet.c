#include <stdlib.h>
#include <string.h>
#include "wallet.h"

Wallet* wallet_create(const char* owner) {
    Wallet* wallet = malloc(sizeof(Wallet));
    if (!wallet) return NULL;
    wallet->address = malloc(strlen(owner) + 10);
    sprintf(wallet->address, "%s_wallet", owner);
    wallet->balance = 100.0;
    return wallet;
}

void wallet_free(Wallet* wallet) {
    free(wallet->address);
    free(wallet);
}

