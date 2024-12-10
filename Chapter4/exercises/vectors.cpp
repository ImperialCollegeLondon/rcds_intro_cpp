#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declare variables
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> vec = {1, 2, 3, 4, 5};

    // Access elements
    cout << "\nArray elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    // Access elements
    cout << "\nVector elements:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // Add element to vector
    vec.push_back(6);
    cout << "\nVector after adding element: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // Remove last element from vector
    vec.pop_back(); // Removes the last element
    cout << "\nVector after removing the last element: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;

}