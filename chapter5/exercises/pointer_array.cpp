// Import libraries
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Print elements of a vector
void print_vector(double* v, int size);

// Compute inverse of a vector
double* inverse_vector(double* v, int size);

// Main function
int main() {

    // Declare variables
    int n;
    cout << "Enter size of vector: "; cin >> n;
    
    // Initialize dynamic array
    double* vec = new double[n];
    cout << "Enter vector elements separated by space: "; 
    for (int i = 0; i < n; i++) cin >> vec[i];

    // Print vector elements
    cout << "\nOriginal vector "; print_vector(vec, n);
    cout << "Size of dynamic vector: " << sizeof(double*) << " bytes \n";

    // Measure time with chrono
    auto start = high_resolution_clock::now();
    double* inv_vec = inverse_vector(vec, n);
    auto end = high_resolution_clock::now();

    // Print result and computation time
    cout << "\nInverse vector: "; print_vector(inv_vec, n);
    cout << "Size of dynamic vector: " << sizeof(double*) << " bytes \n";
    cout << "Computation time: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";

    // Free allocated memory
    delete[] vec;
    delete[] inv_vec;

    return 0;
}

// Print elements of a vector
void print_vector(double* v, int size) {

    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

}

// Compute inverse of a vector
double* inverse_vector(double* v, int size) {

    // Allocate new array for inverse
    double* inv = new double[size];

    for (int i = 0; i < size; i++) {
        if (v[i] == 0) throw runtime_error("\nDivision by zero in inverse_vector");
        inv[i] = 1.0 / v[i];
    }
    
    return inv;

}
