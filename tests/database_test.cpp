#include "database.hpp"

#include <cassert>
#include <iostream>

int main() {
    Database db;

    // Test 1: A new key should not exist.
    assert(!db.exists("name"));

    // Test 2: Store and retrieve a value.
    db.set("name", "Fayaiz");

    auto result = db.get("name");

    assert(result.has_value());
    assert(*result == "Fayaiz");

    // Test 3: Updating a key replaces its value.
    db.set("name", "Student");

    result = db.get("name");

    assert(result.has_value());
    assert(*result == "Student");

    // Test 4: Delete an existing key.
    assert(db.del("name"));
    assert(!db.exists("name"));

    // Test 5: Deleting a missing key.
    assert(!db.del("missing"));

    // Test 6: A missing key returns no value.
    assert(!db.get("missing").has_value());
        // Test 7: An empty string is still a valid value.
    db.set("empty", "");

    auto emptyResult = db.get("empty");

    assert(db.exists("empty"));
    assert(emptyResult.has_value());
    assert(emptyResult->empty());

    // Test 8: Different keys store independent values.
    db.set("language", "C++");
    db.set("editor", "VS Code");

    assert(db.get("language") == "C++");
    assert(db.get("editor") == "VS Code");

    std::cout << "All database tests passed!\n";

    return 0;
}