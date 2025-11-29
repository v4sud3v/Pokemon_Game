#include "Moves.h"

Moves::Moves(std::initializer_list<Entry> entries)
    : entries_(entries) {}

const Moves::Entry& Moves::at(std::size_t index) const {
    return entries_.at(index);
}

std::size_t Moves::size() const {
    return entries_.size();
}