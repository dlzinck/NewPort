//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Drew Lane Zinck II
// Course      : CS 300
// Project     : Project Two - Advising Assistance Program
// Description : Reads course data from a CSV file, stores courses in a BST,
//               prints all courses in alphanumeric order, and prints a single
//               course with its prerequisites.
//============================================================================

// Required libraries
#include <cctype>     // for isspace(), toupper()
#include <fstream>    // for ifstream (reading files)
#include <iostream>   // for cout, cin
#include <sstream>    // for stringstream (splitting lines)
#include <string>     // for string
#include <vector>     // for vector
#include <limits>     // for numeric_limits used in input validation

//---------------------------------------------------------------------------------
// Data Model
// Defines the structure used to represent one course from the CSV file
//---------------------------------------------------------------------------------
struct Course {
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;
};

//---------------------------------------------------------------------------------
// Helper Functions
//---------------------------------------------------------------------------------

// Trim function to remove leading and trailing whitespace from a string
// so that if the CSV data contains extra spaces it wont break comparisons
std::string Trim(const std::string& input) {

    // Finds the index of first non-whitespace character
    size_t start = 0;
    while (start < input.length() && std::isspace(input[start])) {
        start++;
    }

    // Finds the index of last non-whitespace character
    size_t end = input.length();
    while (end > start && std::isspace(input[end - 1])) {
        end--;
    }

    // Returns the substring that excludes outer whitespace
    return input.substr(start, end - start);
}

// Converts a string to all uppercase characters
// This makes sure that course searches are case-insensitive
std::string ToUpper(const std::string& input) {
    std::string result = input;

    for (size_t i = 0; i < result.length(); i++) {
        result[i] = std::toupper(result[i]);
    }
    return result;
}

// This function splits a single CSV line into separate values using comma as delimiter.
// For example: "CS200,Data Structures,CS100"
// Returns a vector of ["CS200", "Data Structures", "CS100"]
std::vector<std::string> SplitCSVLine(const std::string& line) {
    std::vector<std::string> tokens;
    // Treats the line like an input stream
    std::stringstream ss(line);  
    std::string value;
    // Reads the values separated by commas
    while (std::getline(ss, value, ',')) {
        // Removes the extra spaces from each token before storing
        tokens.push_back(Trim(value));
    }
    return tokens;
}

//---------------------------------------------------------------------------------
// Binary Search Tree (BST)
//---------------------------------------------------------------------------------

// A Node stores ONE Course and links to two child nodes
// On the left  = courses with smaller courseNumber
// On the right = courses with larger courseNumber
struct Node {
    Course course;     // The course data stored in this node
    Node* left;        // Pointer to left child
    Node* right;       // Pointer to right child

    // When we create a new Node, it starts with no children
    Node(const Course& newCourse) {
        course = newCourse;
        left = nullptr;
        right = nullptr;
    }
};

// A Binary Search Tree stores Courses ordered by courseNumber
// This lets us print courses in alphanumeric order using an in-order traversal
class BinarySearchTree {
private:
    Node* root;   // The top of the tree - nullptr means the tree is empty

    // Recursive helper used internally to insert nodes
    void Insert(Node*& node, const Course& course);
    // Recursive helper for in-order traversal
    void InOrder(Node* node) const;
    // Recursive helper for searching
    const Course* Search(Node* node, const std::string& courseNumber) const;

public:
    BinarySearchTree() {
        root = nullptr;
    }
    void Insert(const Course& course);
    const Course* Search(const std::string& courseNumber) const;
    void PrintInOrder() const;
};

// Public Insert function, starts recursive insertion at the root of the tree
void BinarySearchTree::Insert(const Course& course) {
    Insert(root, course);
}

// Recursive Insert helper that places a course into the correct position in the BST
void BinarySearchTree::Insert(Node*& node, const Course& course) {

    // If this spot in the tree is empty, create a new node here
    if (node == nullptr) {
        node = new Node(course);
        return;
    }
    // If the new course number is smaller, go left
    if (course.courseNumber < node->course.courseNumber) {
        Insert(node->left, course);
    }
    // If the new course number is larger, go right
    else if (course.courseNumber > node->course.courseNumber) {
        Insert(node->right, course);
    }
    // If course numbers are equal, overwrite existing data
    else {
        node->course = course;
    }
}

// Public Search function that starts recursive search from the root
const Course* BinarySearchTree::Search(const std::string& courseNumber) const {
    return Search(root, courseNumber);
}

// Recursive Search helper that looks for a courseNumber in the BST and returns a pointer if found
const Course* BinarySearchTree::Search(Node* node, const std::string& courseNumber) const {

    // If we hit a null node, the course does not exist
    if (node == nullptr) {
        return nullptr;
    }
    // If we found the matching course number
    if (courseNumber == node->course.courseNumber) {
        return &node->course;
    }
    // If the target is smaller, search left subtree
    if (courseNumber < node->course.courseNumber) {
        return Search(node->left, courseNumber);
    }
    // Otherwise search right subtree
    return Search(node->right, courseNumber);
}

// Public PrintInOrder function that starts recursive in-order traversal from the root
void BinarySearchTree::PrintInOrder() const {
    InOrder(root);
}

// Recursive InOrder helper that raverses left subtree, prints current course, then right subtree
void BinarySearchTree::InOrder(Node* node) const {
    // If the node is null, nothing to process
    if (node == nullptr) {
        return;
    }
    // Visit left subtree, smaller courseNumbers
    InOrder(node->left);
    // Process current node, print course info
    std::cout << node->course.courseNumber
              << ", "
              << node->course.courseTitle
              << std::endl;
    // Visit right subtree, larger courseNumbers
    InOrder(node->right);
}


// LoadCourses function that reads the CSV file and inserts valid courses into BST
// and returns true if at least one course was loaded
bool LoadCourses(const std::string& filename, BinarySearchTree& tree) {
    std::ifstream file(filename);
    // If file cannot be opened
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file: " << filename << std::endl;
        return false;
    }
    std::string line;
    // Read each line from file
    while (std::getline(file, line)) {
        // Skip empty lines
        if (Trim(line).empty()) {
            continue;
        }
        std::vector<std::string> tokens = SplitCSVLine(line);
        // Must have at least course number and title
        if (tokens.size() < 2) {
            std::cout << "Format error: Missing course number or title." << std::endl;
            continue;
        }
        Course course;
        // Normalize and assign course number
        course.courseNumber = ToUpper(tokens[0]);
        // Assign title
        course.courseTitle = tokens[1];
        // Add prerequisites if they exist
        for (size_t i = 2; i < tokens.size(); i++) {
            course.prerequisites.push_back(ToUpper(tokens[i]));
        }
        // Insert into BST
        tree.Insert(course);
    }
    file.close();
    return true;
}

//---------------------------------------------------------------------------------
// MAIN FUNCTION
//---------------------------------------------------------------------------------
int main() {
    BinarySearchTree tree;           // Create the Binary Search Tree that will store courses
    std::string filename;
    int choice = 0;
    while (choice != 9) {           // Continue looping until user selects Exit

        std::cout << "\n===== Course Advising Program =====\n";         // Display menu options
        std::cout << "1. Load Data Structure\n";
        std::cout << "2. Print Course List\n";
        std::cout << "3. Print Course\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;                 // Get user selection

        // If the user enters something that is not a number, cin fails.
        // Clear the error state and discard the bad input so the menu works again.
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n";
        continue;
}

        if (choice == 1) {                  // OPTION 1: Load course data from CSV file
            // Hard coded file in for simplicity but can be made to accept dynamically as well
            filename = "CS 300 ABCU_Advising_Program_Input.csv"; 
            if (LoadCourses(filename, tree)) {
                std::cout << "Courses loaded successfully.\n";
            }
        } else if (choice == 2) {           // OPTION 2: Print all courses in alphanumeric order
            tree.PrintInOrder();
        } else if (choice == 3) {           // OPTION 3: Search for and display a specific course
            std::string courseNumber;
            std::cout << "Enter course number: ";
            std::cin >> courseNumber;
            const Course* course = tree.Search(ToUpper(courseNumber));
            if (course == nullptr) {
                std::cout << "Course not found.\n";
            } else {
                std::cout << course->courseNumber << ", "
                          << course->courseTitle << std::endl;
                if (course->prerequisites.empty()) {
                    std::cout << "Prerequisites: None\n";
                } else {
                    std::cout << "Prerequisites:\n";
                    for (const std::string& prereq : course->prerequisites) {
                        const Course* prereqCourse = tree.Search(prereq);
                        if (prereqCourse != nullptr) {
                            std::cout << " - " << prereqCourse->courseNumber
                                      << ", " << prereqCourse->courseTitle
                                      << std::endl;
                        } else {
                            std::cout << " - " << prereq << std::endl;
                        }
                    }
                }
            }
        } else if (choice == 9) {               // OPTION 9: Exit the program
            std::cout << "Goodbye.\n";
        } else {                                // Handle invalid menu input
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}