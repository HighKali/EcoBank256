#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <openssl/rsa.h>
#include <openssl/pem.h>

typedef struct Account {
    char* username;
    RSA* private_key;  // Chiave privata RSA
    RSA* public_key;   // Chiave pubblica RSA
    int logged_in;     // Stato di login
} Account;

Account* account_sign_up(const char* username);
int account_sign_in(Account* acc, const char* username);
void account_free(Account* acc);

#endif
