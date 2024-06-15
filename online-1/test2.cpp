#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Example 2D vector
    std::vector<std::vector<int>> edges = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5}
    };

    // Custom comparison function for sorting in descending order
    auto compare = [](const std::vector<int>& a, const std::vector<int>& b) {
        return a > b; // Compare vectors in descending order
    };

    // Sort the 2D vector using the custom comparison function
    std::sort(edges.begin(), edges.end(), compare);

    // Display the sorted 2D vector
    std::cout << "Sorted 2D vector in descending order:\n";
    for (const auto& row : edges) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
