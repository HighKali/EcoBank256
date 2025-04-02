#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "address.h"

char* generate_address(Account* acc) {
    // Converte la chiave pubblica in una stringa e genera un hash SHA-256
    BIO* bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(bio, acc->public_key);
    char* pub_key_str;
    long len = BIO_get_mem_data(bio, &pub_key_str);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)pub_key_str, len, hash);

    // Converte l’hash in una stringa esadecimale (indirizzo)
    char* address = malloc(65);  // 64 caratteri + terminatore
    for (int i = 0; i < 32; i++) {
        sprintf(address + i * 2, "%02x", hash[i]);
    }
    address[64] = '\0';

    BIO_free(bio);
    return address;
}
