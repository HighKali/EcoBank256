#include "Blockchain.h"
#include "DaemonCommandsHandler.h"
#include "Logger.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2 || std::string(argv[1]) != "--config-file=../ecobank256.ini") {
        std::cerr << "Usage: " << argv[0] << " --config-file=../ecobank256.ini\n";
        return 1;
    }

    try {
        CryptoNote::Logger::init("ecobank256.log");
        CryptoNote::Blockchain blockchain;
        blockchain.initialize(argv[1]);
        CryptoNote::DaemonCommandsHandler handler(blockchain);

        std::string command;
        std::cout << "EcoBank256 CLI (type 'exit' to quit)\n";
        std::cout << "To view the live attack map, open ui/map.html in a web browser.\n";
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, command);
            if (command == "exit") break;

            try {
                if (command == "balance") {
                    handler.balance("");
                } else if (command.substr(0, 4) == "send") {
                    handler.send(command.substr(5));
                } else if (command == "mix") {
                    handler.mix("");
                } else if (command == "interest") {
                    handler.interest("");
                } else if (command == "showchain") {
                    handler.showchain("");
                } else if (command == "reserve") {
                    handler.reserve("");
                } else if (command == "lockstatus") {
                    if (blockchain.isAccountLocked("addr123")) {
                        std::cout << "Account is locked due to a security breach. Unlock time: " << blockchain.getLockExpiration("addr123") << " (Unix timestamp)\n";
                    } else {
                        std::cout << "Account is not locked.\n";
                    }
                } else {
                    std::cout << "Unknown command. Available commands: balance, send <amount> <address>, mix, interest, showchain, reserve, lockstatus, exit\n";
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                CryptoNote::Logger::log("Error: " + std::string(e.what()));
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
