#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "mixing.h"  // Corretto: include mixing.h

void cli_run(Blockchain* bc, Wallet* wallet) {
    char command[256];
    printf("EcoBank256 CLI - Digita 'help' per i comandi\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) break;
        else if (strcmp(command, "help") == 0) {
            printf("Comandi: balance, send <dest> <amount>, exit\n");
        } else if (strcmp(command, "balance") == 0) {
            printf("Saldo di %s: %.2f EBK\n", wallet->address, wallet->balance);
        } else if (strncmp(command, "send ", 5) == 0) {
            char dest[256];
            double amount;
            if (sscanf(command + 5, "%s %lf", dest, &amount) == 2) {
                Transaction* tx = transaction_create(wallet, dest, amount);
                mix_transaction(tx);
                blockchain_add_transaction(bc, tx);
                wallet->balance -= amount;
                printf("Transazione inviata!\n");
            } else {
                printf("Errore: usa 'send <destinatario> <importo>'\n");
            }
        } else {
            printf("Comando sconosciuto. Digita 'help' per aiuto.\n");
        }
    }
}
