#include <stdio.h>
#include <stdlib.h>
#include <boost/asio.hpp>
#include "network.h"

Network* network_init(short port) {
    Network* net = malloc(sizeof(Network));
    if (!net) return NULL;

    net->io_context = new boost::asio::io_context();
    net->acceptor = new boost::asio::ip::tcp::acceptor(*net->io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
    net->socket = new boost::asio::ip::tcp::socket(*net->io_context);
    net->port = port;

    printf("Nodo in ascolto sulla porta %d\n", port);
    return net;
}

void network_broadcast_transaction(Network* net, Transaction* tx) {
    boost::asio::ip::tcp::resolver resolver(*net->io_context);
    auto endpoints = resolver.resolve("127.0.0.1", "12346");  // Esempio: altro nodo
    boost::asio::connect(*net->socket, endpoints);

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "TX:%s:%s:%.2f", tx->sender, tx->receiver, tx->amount);
    boost::asio::write(*net->socket, boost::asio::buffer(buffer));
    printf("Transazione trasmessa: %s\n", buffer);
}

void network_sync_blockchain(Network* net, Blockchain* bc) {
    printf("Sincronizzazione blockchain con la rete (non implementata)\n");
    // TODO: Implementare la sincronizzazione reale
}

void network_free(Network* net) {
    delete net->socket;
    delete net->acceptor;
    delete net->io_context;
    free(net);
}
