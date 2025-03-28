#include <openssl/aes.h>
#include <string.h>
#include "BankCrypto.h"

namespace Crypto {

void encryptTransaction(uint8_t* data, size_t len, const uint8_t* key256) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key256, 256, &aesKey);
    for (size_t i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_encrypt(data + i, data + i, &aesKey);
    }
}

void decryptTransaction(uint8_t* data, size_t len, const uint8_t* key256) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key256, 256, &aesKey);
    for (size_t i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_decrypt(data + i, data + i, &aesKey);
    }
}

} // namespace Crypto
