#include <iostream>
#include <vector>

int main() {
    // Define a 2D vector
    std::vector<std::vector<int>> my2DVector = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Iterate through the 2D vector using nested loops
    // i represents the row index, and j represents the column index
    for (int i = 0; i < my2DVector.size(); ++i) {
        for (int j = 0; j < my2DVector[i].size(); ++j) {
            // Access the element at the current position (i, j)
            std::cout << my2DVector[i][j] << " ";
        }
        std::cout << std::endl; // Move to the next line after each row
    }

    return 0;
}
