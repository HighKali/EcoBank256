#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include "blockchain.h"
#include "wallet.h"

Blockchain* blockchain_init(void) {
    Blockchain* bc = malloc(sizeof(Blockchain));
    if (!bc) return NULL;
    bc->transactions = NULL;
    bc->count = 0;
    bc->interest_rate = 0.05;
    return bc;
}

Transaction* transaction_create(Wallet* sender, const char* receiver, double amount) {
    Transaction* tx = malloc(sizeof(Transaction));
    if (!tx) return NULL;

    tx->sender = strdup(sender->address);
    tx->receiver = strdup(receiver);
    tx->amount = amount;

    const char* data = "Dati sensibili della transazione";
    AES_KEY aes_key;
    unsigned char key[32] = "chiave_di_prova_32_bytes_long!!";
    unsigned char iv[16] = {0};
    AES_set_encrypt_key(key, 256, &aes_key);

    size_t data_len = strlen(data) + 1;
    tx->encrypted_len = ((data_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    tx->encrypted_data = malloc(tx->encrypted_len);
    AES_cbc_encrypt((unsigned char*)data, tx->encrypted_data, data_len, &aes_key, iv, AES_ENCRYPT);

    return tx;
}

void blockchain_add_transaction(Blockchain* bc, Transaction* tx) {
    bc->transactions = realloc(bc->transactions, (bc->count + 1) * sizeof(Transaction*));
    bc->transactions[bc->count++] = tx;
    printf("Interessi maturati: %.2f EBK\n", tx->amount * bc->interest_rate);
}

void blockchain_free(Blockchain* bc) {
    for (size_t i = 0; i < bc->count; i++) {
        free(bc->transactions[i]->sender);
        free(bc->transactions[i]->receiver);
        free(bc->transactions[i]->encrypted_data);
        free(bc->transactions[i]);
    }
    free(bc->transactions);
    free(bc);
}

