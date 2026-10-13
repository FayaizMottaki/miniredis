
#include "database.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main() {
    Database db;

    std::string line;

    std::cout << "MiniRedis v0.1.0\n";
    std::cout << "Type HELP for commands. Type EXIT to quit.\n\n";

    while (true) {
        std::cout << "miniredis> ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        std::istringstream input(line);

        std::string command;
        input >> command;

        if (command.empty()) {
            continue;
        }

        if (command == "SET") {
            std::string key;
            std::string value;

            if (!(input >> key)) {
                std::cout << "ERR missing key\n";
                continue;
            }

            std::getline(input >> std::ws, value);

            if (value.empty()) {
                std::cout << "ERR missing value\n";
                continue;
            }

            db.set(key, value);
            std::cout << "OK\n";
        }

        else if (command == "GET") {
            std::string key;

            if (!(input >> key)) {
                std::cout << "ERR missing key\n";
                continue;
            }

            auto result = db.get(key);

            if (result.has_value()) {
                std::cout << *result << '\n';
            } else {
                std::cout << "(nil)\n";
            }
        }

        else if (command == "DEL") {
            std::string key;

            if (!(input >> key)) {
                std::cout << "ERR missing key\n";
                continue;
            }

            std::cout << db.del(key) << '\n';
        }

        else if (command == "EXISTS") {
            std::string key;

            if (!(input >> key)) {
                std::cout << "ERR missing key\n";
                continue;
            }

            std::cout << db.exists(key) << '\n';
        }

        else if (command == "HELP") {
            std::cout
                << "Commands:\n"
                << "  SET <key> <value>\n"
                << "  GET <key>\n"
                << "  DEL <key>\n"
                << "  EXISTS <key>\n"
                << "  HELP\n"
                << "  EXIT\n";
        }

        else if (command == "EXIT") {
            std::cout << "Thanks for using my redis\n";
            break;
        }

        else {
            std::cout << "ERR unknown command\n";
        }
    }

    return 0;
}
