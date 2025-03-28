#ifndef BANKCRYPTO_H
#define BANKCRYPTO_H

#include <stdint.h>
#include <stddef.h>

namespace Crypto {

void encryptTransaction(uint8_t* data, size_t len, const uint8_t* key256);
void decryptTransaction(uint8_t* data, size_t len, const uint8_t* key256);

} // namespace Crypto

#endif
