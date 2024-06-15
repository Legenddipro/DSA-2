// // #include <iostream>

// // int main() {
// //     char character;
// //     std::cout << "Enter a character: ";
// //     std::cin >> character;

// //     int asciiValue = static_cast<int>(character);

// //     std::cout << "ASCII value of " << character << " is: " << asciiValue << std::endl;

// //     return 0;
// // }
// #include <iostream>
// #include <list>
// #include <string>

// using namespace std;

// // Function to display the list of pairs
// void displayList(const list<pair<string, int>>& myList) {
//     for(const auto& pair : myList) {
//         cout << pair.first << ": " << pair.second << endl;
//     }
// }

// int main() {
//     // Create a list of pairs
//     list<pair<string, int>> myList = {{"apple", 10}, {"banana", 20}, {"orange", 30}};

//     cout << "Original list:" << endl;
//     displayList(myList);

//     // Ask user for the pair to delete
//     string keyToDelete;
//     cout << "\nEnter the key to delete: ";
//     cin >> keyToDelete;

//     // Search for the pair with the given key and delete it if found
//     auto it = myList.begin();
//     while (it != myList.end()) {
//         if (it->first == keyToDelete) {
//             it = myList.erase(it); // erase returns the iterator to the next element
//         } else {
//             ++it;
//         }
//     }

//     cout << "\nList after deletion:" << endl;
//     displayList(myList);

//     return 0;
// }
//  #include <iostream>
// #include <vector>
// #include <list>
// #include <utility>
// #include <string>

// using namespace std;

// typedef long long ll_int;

// int main() {
//     int table_size = 5;
//     vector<list<pair<string, ll_int>>> node_list;
//     node_list.resize(table_size);

//     // Adding some data to the vector (just for demonstration)
//     node_list[0].push_back({"A", 1});
//     node_list[2].push_back({"B", 2});
//     node_list[4].push_back({"C", 3});

//     // Clearing the lists in the vector
//     ll_int j = 0;
//     while (j < table_size) {
//         node_list[j].clear();
//         j++;
//     }

//     // Printing the contents of the vector
//     for (int i = 0; i < table_size; ++i) {
//         cout << "List at index " << i << " has size: " << node_list[i].size() << endl;
//     }

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <list>
// #include <utility>
// #include <random>

// using namespace std;

// // Define a type alias for convenience
// using Pair = pair<string, int>;
// using PairList = list<Pair>;
// using VectorOfPairLists = vector<PairList>;

// // Function to randomly select 10% of elements
// VectorOfPairLists selectRandomElements(const VectorOfPairLists& input) {
//     VectorOfPairLists result;

//     // Seed for random number generation
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_real_distribution<> dis(0.0, 1.0);

//     for (const auto& list : input) {
//         PairList selectedElements;
//         for (const auto& pair : list) {
//             if (dis(gen) < 0.1) { // Select 10% of elements randomly
//                 selectedElements.push_back(pair);
//             }
//         }
//         result.push_back(selectedElements);
//     }

//     return result;
// }

// int main() {
//     // Example vector of list of pair
//     VectorOfPairLists data = {
//         {{"A", 1}, {"B", 2}, {"C", 3}},
//         {{"D", 4}, {"E", 5}, {"F", 6}, {"G", 7}},
//         {{"H", 8}, {"I", 9}}
//     };

//     // Selecting 10% of elements randomly
//     VectorOfPairLists selectedData = selectRandomElements(data);

//     // Displaying the selected elements
//     for (const auto& list : selectedData) {
//         for (const auto& pair : list) {
//             cout << "(" << pair.first << ", " << pair.second << ") ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdlib> // For rand() function
// #include <ctime>   // For time() function

// using namespace std;

// // Function to randomly select 10 percent of elements from a vector
// vector<string> selectRandomElements(const vector<string>& input) {
//     vector<string> selectedElements;
    
//     // Calculate the number of elements to select (10 percent of total)
//     int numElementsToSelect = input.size() * 0.10;
    
//     // Set seed for random number generation
//     srand(time(0));
    
//     // Loop to randomly select elements
//     for (int i = 0; i < numElementsToSelect; ++i) {
//         // Generate a random index within the range of the vector size
//         int randomIndex = rand() % input.size();
        
//         // Add the element at the randomly generated index to selectedElements
//         selectedElements.push_back(input[randomIndex]);
//     }
    
//     return selectedElements;
// }

// int main() {
//     // Sample vector of strings
//     vector<string> elements = {"apple", "banana", "orange", "grape", "pineapple", "mango", "kiwi", "strawberry", "watermelon", "pear"};
    
//     // Call the function to select random elements
//     vector<string> selected = selectRandomElements(elements);
    
//     // Output the selected elements
//     cout << "Selected Elements:" << endl;
//     for (const auto& element : selected) {
//         cout << element << endl;
//     }
    
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function
#include <set>     // For std::set

using namespace std;

// Function to randomly select 10 percent of elements from a vector
vector<string> selectRandomElements(const vector<string>& input) {
    vector<string> selectedElements;
    
    // Calculate the number of elements to select (10 percent of total)
    int numElementsToSelect = input.size() * 0.10;
    
    // Set seed for random number generation
    srand(time(0));
    
    // Set to store indices of selected elements
    set<int> selectedIndices;
    
    // Loop to randomly select elements
    while (selectedIndices.size() < numElementsToSelect) {
        // Generate a random index within the range of the vector size
        int randomIndex = rand() % input.size();
        
        // Check if the index has already been selected
        if (selectedIndices.find(randomIndex) == selectedIndices.end()) {
            // Add the index to the set of selected indices
            selectedIndices.insert(randomIndex);
            
            // Add the element at the randomly generated index to selectedElements
            selectedElements.push_back(input[randomIndex]);
        }
    }
    
    return selectedElements;
}

int main() {
    // Sample vector of strings
    vector<string> elements = {"apple", "banana", "orange", "grape", "pineapple", "mango", "kiwi", "strawberry", "watermelon", "pear"};
    
    // Call the function to select random elements
    vector<string> selected = selectRandomElements(elements);
    
    // Output the selected elements
    cout << "Selected Elements:" << endl;
    for (const auto& element : selected) {
        cout << element << endl;
    }
    
    return 0;
}
