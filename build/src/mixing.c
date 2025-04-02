#include <stdio.h>
#include <string.h>
#include "mixing.h"

void mix_transaction(Transaction* tx) {
    char* original_sender = tx->sender;
    tx->sender = strdup("MixedAddress");
    free(original_sender);
    printf("Transazione mixata: %.2f EBK da %s a %s\n", tx->amount, tx->sender, tx->receiver);
}

