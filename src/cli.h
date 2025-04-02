#ifndef CLI_H
#define CLI_H

#include "blockchain.h"
#include "wallet.h"
#include "network.h"

void cli_run(Blockchain* bc, Wallet* wallet, Network* net);

#endif
