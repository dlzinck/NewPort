// Author: Drew Lane Zinck II
// Date: 2025-08-15
// Course: CS210 - Corner Grocer Project
// File: ItemTracker.cpp
// Description: Implementation of the ItemTracker class for counting 
//              and reporting item frequencies.

/**
 * @file ItemTracker.cpp
 * @brief Implementation of the ItemTracker class.
 *
 * This file contains the actual code for the functions we promised in the header.
 * The header said what exists; this file shows *how* each function works.
 */

#include "ItemTracker.h"

#include <fstream>   // std::ifstream, std::ofstream
#include <iostream>  // std::cout, std::cerr

/**
 * @brief Load items from a text file and build the frequency table.
 * @param inputPath Path to the input file.
 * @return true on success, false on failure.
 *
 * Open the file. Read each word (item name). Add +1 to that item’s count in the map.
 * If the file can’t be opened, report the problem and return false.
 */
bool ItemTracker::LoadFromFile(const std::string& inputPath) {
    std::ifstream in(inputPath);
    if (!in.is_open()) {
        std::cerr << "Error: could not open input file: " << inputPath << std::endl;
        return false;
    }

    std::string token;
    while (in >> token) {
        ++freq_[token];  // If token not present, map creates it with 0, then increments.
    }

    return true;
}

/**
 * @brief Write the current frequency table to a backup file.
 * @param outputPath Path to the output file to create or overwrite.
 * @return true on success, false on failure.
 *
 * Create a file and or overwrite if it exists. For every item / count in the map,
 * write a line like: "item count". If we can’t write, say so and return false.
 */
bool ItemTracker::WriteBackup(const std::string& outputPath) const {
    std::ofstream out(outputPath);
    if (!out.is_open()) {
        std::cerr << "Error: could not write backup file: " << outputPath << std::endl;
        return false;
    }

    for (const auto& kv : freq_) {
        out << kv.first << ' ' << kv.second << '\n';
    }

    return true;
}

/**
 * @brief Get the number of times a given item appears.
 * @param item Item name to look up.
 * @return Frequency or 0 if not present.
 *
 * Look for the item in the map. If found, return its number. Otherwise return 0.
 */
int ItemTracker::CountOf(const std::string& item) const {
    auto it = freq_.find(item);
    return (it == freq_.end()) ? 0 : it->second;
}

/**
 * @brief Print all items with counts, one per line as "item count".
 *
 * Loop over every entry and print: name, a space, then the number.
 */
void ItemTracker::PrintAll() const {
    for (const auto& kv : freq_) {
        std::cout << kv.first << ' ' << kv.second << '\n';
    }
}

/**
 * @brief Print a simple text histogram using asterisks for counts.
 *
 * For each item, print the name, a space, then as many '*' as the count.
 */
void ItemTracker::PrintHistogram() const {
    for (const auto& kv : freq_) {
        std::cout << kv.first << ' ';
        for (int i = 0; i < kv.second; ++i) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
