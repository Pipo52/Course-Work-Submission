#pragma once
#include <iostream>
#include <stdexcept>

template <typename Container>
void printAll(const std::string& label, const Container& items) {
    std::cout << "\n--- " << label << " ---\n";
    for (const auto& item : items) {
        item->printInfo();
    }
}

template <typename Container, typename Comparator>
auto findMax(const Container& items, Comparator comp) -> decltype(*items.begin()) {
    if (items.empty()) {
        throw std::runtime_error("Container is empty.");
    }
    auto maxIt = items.begin();
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (comp(*maxIt, *it)) {
            maxIt = it;
        }
    }
    return *maxIt;
}
