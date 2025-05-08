// Include libraries
#include <iostream>
using namespace std;

// Function computing double of array
void double_values(int* arr, int size);

// Function printing elements od array
void print_array(const int* arr, int size);

// Main function
int main() {

    // Declare variables
    int size;
    int *arr = new int[size]; // Dynamic memory allocation for the array

    // Assign values (even size is input now)
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " elements separated by space: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Print elements of array
    cout << "Original array: ";
    print_array(arr, size);

    // Double values
    double_values(arr, size);

    // Print elements of doubled array
    cout << "Doubled array: ";
    print_array(arr, size);

    // Free dynamically allocated memory
    delete[] arr;

    return 0;

}

// Function computing double of array
void double_values(int* arr, int size) {

    // Using pointer arithmetic to iterate and modify the array
    
    // Declares a pointer p of type int* and initializes it to point to the start of the array arr
    // Iterate while p points to a between boundaries of the array
    // Moves the pointer p to the next element in the array
    for (int *p = arr; p < arr + size; ++p) {
        *p = *p * 2;
    }

}

// Function printing elements od array
void print_array(const int* arr, int size) {

    // Using pointer arithmetic to access and print the array elements
    
    // Declaring pointer as const ensures that values it points to cannot be altered
    // Ensure printing function works in non destructive manner
    for (const int *p = arr; p < arr + size; ++p) {
        cout << *p << " ";
    }
    cout << endl;
}