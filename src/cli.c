#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "mixing.h"
#include "mining.h"

void cli_run(Blockchain* bc, Wallet* wallet, Network* net) {
    char command[256];
    printf("EcoBank256 CLI - Digita 'help' per i comandi\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) break;
        else if (strcmp(command, "help") == 0) {
            printf("Comandi: balance, send <dest> <amount>, mine, sync, peers, status, exit\n");
        } else if (strcmp(command, "balance") == 0) {
            printf("Saldo di %s: %.2f EBK\n", wallet->address, wallet->balance);
        } else if (strncmp(command, "send ", 5) == 0) {
            char dest[256];
            double amount;
            if (sscanf(command + 5, "%s %lf", dest, &amount) == 2) {
                Transaction* tx = transaction_create(wallet, dest, amount);
                mix_transaction(tx);
                blockchain_add_transaction(bc, tx);
                network_broadcast_transaction(net, tx);
                wallet->balance -= amount;
                printf("Transazione inviata!\n");
            } else {
                printf("Errore: usa 'send <destinatario> <importo>'\n");
            }
        } else if (strcmp(command, "mine") == 0) {
            mine_block(bc, wallet);
        } else if (strcmp(command, "sync") == 0) {
            network_sync_blockchain(net, bc);
        } else if (strcmp(command, "peers") == 0) {
            printf("Lista peer non implementata\n");
        } else if (strcmp(command, "status") == 0) {
            printf("Transazioni: %zu, Saldo: %.2f EBK\n", bc->count, wallet->balance);
        } else {
            printf("Comando sconosciuto. Digita 'help' per aiuto.\n");
        }
    }
}
