// Author: Drew Lane Zinck II
// Date: 2025-08-15
// Course: CS210 - Corner Grocer Project
// File: ItemTracker.h
// Description: Declaration of the ItemTracker class for loading,
//              storing, and reporting item purchase frequencies.

/**
 * @file ItemTracker.h
 * @brief Declares the ItemTracker class that stores and works with a list of items
 *        and their purchase frequencies.
 *
 * This header file defines the structure of the ItemTracker class. It tells the
 * compiler what data members (variables) the class will have, and what public
 * functions can be called from other parts of the program.
 *
 * This file is like a "blueprint" for our ItemTracker object. It  basically says that:
 * - What variables the object keeps track of (a map of items to how many times
 *   they appear).
 * - What functions you can call on it (like loading from a file, printing, etc.).
 * The actual code for the functions will be in ItemTracker.cpp — this file just
 * announces that they exist.
 */

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

/**
 * @class ItemTracker
 * @brief Tracks the frequency of items and provides operations to query and print data.
 *
 * This class will be the "manager" for our grocery data. It owns a table (map)
 * that says: "item name" → "how many times it appeared."
 * It has functions for:
 * - Filling the map from a file
 * - Saving it as a backup
 * - Looking up one item's count
 * - Printing all items
 * - Printing a histogram
 */
class ItemTracker {
public:
    /**
     * @brief Load items from a text file and build the frequency table.
     * @param inputPath Path to the input file.
     * @return true if the file loads successfully, false otherwise.
     *
     * Opens a file, read all the words, and count how many times each one shows up.
     * Store those counts in our map. Return true if it worked, false if the file
     * couldn’t be opened or read.
     */
    bool LoadFromFile(const std::string& inputPath);

    /**
     * @brief Write the current frequency table to a backup file.
     * @param outputPath Path to the output file to create.
     * @return true if the file was written successfully, false otherwise.
     *
     * Take the map of items and counts, and write each one to a file so we have a
     * saved copy or "backup". Return true if that file was created and written without
     * problems.
     */
    bool WriteBackup(const std::string& outputPath) const;

    /**
     * @brief Get the number of times a given item appears.
     * @param item The item name to look up.
     * @return The count for that item, or 0 if the item isn’t in the map.
     *
     * Look in the map for the item name. If it’s there, give back its count.
     * If not, give back 0.
     */
    int CountOf(const std::string& item) const;

    /**
     * @brief Print all items and their counts to the console.
     *
     * Loop through every pair in the map and show:
     *   item_name count
     * one per line.
     */
    void PrintAll() const;

    /**
     * @brief Print all items and their counts as a histogram using asterisks (*).
     *
     * For each item, print the name, then print that many * characters so it looks
     * like a simple bar chart.
     */
    void PrintHistogram() const;

private:
    std::map<std::string, int> freq_; //< Item name → count mapping.

    // This is our "table" that remembers every item name and how many times it
    // appeared. The key is a string (item name), and the value is an int (count).
};

#endif // ITEM_TRACKER_H
