#include <stdio.h>
#include <stdlib.h>
#include "blockchain.h"
#include "wallet.h"
#include "mixing.h"
#include "cli.h"

int main(void) {
    printf("EcoBank256 - Avvio del nodo\n");

    Blockchain* bc = blockchain_init();
    if (!bc) {
        fprintf(stderr, "Errore nell'inizializzazione della blockchain\n");
        return 1;
    }

    Wallet* wallet = wallet_create("HighKali");
    if (!wallet) {
        fprintf(stderr, "Errore nella creazione del wallet\n");
        blockchain_free(bc);
        return 1;
    }

    Transaction* tx = transaction_create(wallet, "Destinatario", 10.0);
    mix_transaction(tx);
    blockchain_add_transaction(bc, tx);

    cli_run(bc, wallet);

    wallet_free(wallet);
    blockchain_free(bc);
    return 0;
}
