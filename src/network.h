#ifndef NETWORK_H
#define NETWORK_H

#include <boost/asio.hpp>
#include "blockchain.h"

typedef struct Network {
    boost::asio::io_context* io_context;
    boost::asio::ip::tcp::acceptor* acceptor;
    boost::asio::ip::tcp::socket* socket;
    short port;
} Network;

Network* network_init(short port);
void network_broadcast_transaction(Network* net, Transaction* tx);
void network_sync_blockchain(Network* net, Blockchain* bc);
void network_free(Network* net);

#endif
