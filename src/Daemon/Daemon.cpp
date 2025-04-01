#include "Crypto/BankCrypto.h"
#include <time.h>

namespace CryptoNote {

void calculateInterest(BankAccount& account) {
    uint64_t now = time(nullptr);
    uint64_t daysElapsed = (now - account.lastInterestTimestamp) / (24 * 3600);
    if (daysElapsed > 0) {
        account.balance += account.balance * account.interestRate * daysElapsed;
        account.lastInterestTimestamp = now;
    }
}

} // namespace CryptoNote
