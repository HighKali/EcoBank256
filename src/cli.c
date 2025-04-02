#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cli.h"
#include "mixing.h"
#include "mining.h"
#include "address.h"

static void sanitize_input(char* input) {
    // Rimuove caratteri non alfanumerici o spazi per prevenire input malevoli
    for (int i = 0; input[i]; i++) {
        if (!isalnum(input[i]) && !isspace(input[i]) && input[i] != '.') {
            input[i] = '\0';
            break;
        }
    }
}

void cli_run(Blockchain* bc, Wallet* wallet, Network* net, Account* acc) {
    char command[256];
    printf("EcoBank256 CLI - Digita 'help' per i comandi\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;
        sanitize_input(command);  // Protezione base degli input

        if (strcmp(command, "exit") == 0) break;
        else if (strcmp(command, "help") == 0) {
            printf("Comandi: signup <user>, signin <user>, balance, send <dest> <amount>, mine, sync, peers, status, address, exit\n");
        } else if (strncmp(command, "signup ", 7) == 0) {
            char user[256];
            if (sscanf(command + 7, "%s", user) == 1) {
                if (acc->logged_in) {
                    printf("Errore: già loggato\n");
                } else {
                    account_free(acc);
                    acc = account_sign_up(user);
                    wallet->address = generate_address(acc);
                }
            } else {
                printf("Errore: usa 'signup <username>'\n");
            }
        } else if (strncmp(command, "signin ", 7) == 0) {
            char user[256];
            if (sscanf(command + 7, "%s", user) == 1) {
                account_sign_in(acc, user);
            } else {
                printf("Errore: usa 'signin <username>'\n");
            }
        } else if (strcmp(command, "balance") == 0) {
            if (acc->logged_in) {
                printf("Saldo di %s: %.2f EBK\n", wallet->address, wallet->balance);
            } else {
                printf("Effettua il login prima\n");
            }
        } else if (strncmp(command, "send ", 5) == 0) {
            if (!acc->logged_in) {
                printf("Effettua il login prima\n");
            } else {
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
            }
        } else if (strcmp(command, "mine") == 0) {
            if (acc->logged_in) {
                mine_block(bc, wallet);
            } else {
                printf("Effettua il login prima\n");
            }
        } else if (strcmp(command, "sync") == 0) {
            network_sync_blockchain(net, bc);
        } else if (strcmp(command, "peers") == 0) {
            printf("Lista peer non implementata\n");
        } else if (strcmp(command, "status") == 0) {
            printf("Transazioni: %zu, Saldo: %.2f EBK, Logged in: %d\n", bc->count, wallet->balance, acc->logged_in);
        } else if (strcmp(command, "address") == 0) {
            if (acc->logged_in) {
                printf("Indirizzo: %s\n", wallet->address);
            } else {
                printf("Effettua il login prima\n");
            }
        } else {
            printf("Comando sconosciuto. Digita 'help' per aiuto.\n");
        }
    }
}



