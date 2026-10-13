
#include "database.hpp"

#include <iostream>

int main() {
    Database db;

    db.set("language", "C++");

    auto result = db.get("language");

    if (result.has_value()) {
        std::cout << *result << '\n';
    }

    std::cout << std::boolalpha;
    std::cout << db.exists("language") << '\n';
    std::cout << db.del("language") << '\n';
    std::cout << db.exists("language") << '\n';

    return 0;
}
