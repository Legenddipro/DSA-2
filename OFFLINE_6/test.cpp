#include <iostream>
#include <cmath>

int main() {
    double number = 14
    ;

    // Calculate log base 2
    double result = log2(number);

    // Take the floor of the result
    int floorResult = floor(result);

    // Print the result
    std::cout << "Log base 2 of " << number << " is: " << result << std::endl;
    std::cout << "Floor of the result: " << floorResult << std::endl;

    return 0;
}
