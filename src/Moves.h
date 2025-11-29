#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>
#include <vector>

class Moves {
public:
    struct Entry {
        std::string name;
        int power;
        std::string type;
    };

    Moves(std::initializer_list<Entry> entries);
    ~Moves() = default;

    const Entry& at(std::size_t index) const;
    std::size_t size() const;

private:
    std::vector<Entry> entries_;
};