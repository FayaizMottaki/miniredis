
#include "database.hpp"

void Database::set(const std::string& key,
                   const std::string& value) {
    store[key] = value;
}

std::optional<std::string> Database::get(
    const std::string& key) const {
    auto it = store.find(key);

    if (it == store.end()) {
        return std::nullopt;
    }

    return it->second;
}

bool Database::del(const std::string& key) {
    return store.erase(key) > 0;
}

bool Database::exists(const std::string& key) const {
    return store.find(key) != store.end();
}
