#include <openssl/evp.h>
#include <stdio.h> // For fprintf, stderr

// ... inside the encrypt_transaction function ...

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error creating EVP_CIPHER_CTX\n");
        // Handle error: return error code, etc.
        return -1; // Or another error code
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        fprintf(stderr, "Error initializing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        // Handle error
        return -1;
    }

    int ciphertext_len;
    if (EVP_EncryptUpdate(ctx, tx->encrypted_data, &ciphertext_len, (unsigned char*)data, data_len) != 1) {
        fprintf(stderr, "Error during encryption update\n");
        EVP_CIPHER_CTX_free(ctx);
        // Handle error
        return -1;
    }
    int final_len;
    if (EVP_EncryptFinal_ex(ctx, tx->encrypted_data + ciphertext_len, &final_len) != 1) {
        fprintf(stderr, "Error during encryption finalization\n");
        EVP_CIPHER_CTX_free(ctx);
        // Handle error
        return -1;
    }

    EVP_CIPHER_CTX_free(ctx);
    ciphertext_len += final_len;

// ...
