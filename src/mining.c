#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "mining.h"
#include "wallet.h"

void mine_block(Blockchain* bc, Wallet* miner_wallet) {
    char data[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned long nonce = 0;
    const char* target = "0000";  // Difficoltà semplice

    snprintf(data, sizeof(data), "%zu%.2f", bc->count, bc->interest_rate);

    do {
        snprintf(data + strlen(data), sizeof(data) - strlen(data), "%lu", nonce);
        SHA256((unsigned char*)data, strlen(data), hash);
        nonce++;
    } while (strncmp((char*)hash, target, 4) != 0);

    printf("Blocco minato! Nonce: %lu, Hash: %02x%02x%02x%02x...\n", nonce - 1, hash[0], hash[1], hash[2], hash[3]);
    miner_wallet->balance += 10.0;  // Ricompensa di mining
}
