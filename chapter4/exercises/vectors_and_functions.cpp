// Import libraries
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Print elements of a vector
void print_vector(vector<double> v);

// Compute inverse of a vector
vector<double> inverse_vector(vector<double> v);

// Main function
int main() {

    // Declare variables
    int n;
    cout << "Enter size of vector: "; cin >> n;

    // Initialize vector
    vector<double> vec(n);
    cout << "Enter vector elements separated by space: "; 
    for (int i = 0; i < n; i++) cin >> vec[i];

    // Print vector elements
    cout << "\nOriginal vector "; print_vector(vec);
    cout << "Size of vector: " << sizeof(vector<double>) << " bytes \n";

    // Measure time with chrono
    auto start = high_resolution_clock::now();
    vector<double> inv_vec = inverse_vector(vec);
    auto end = high_resolution_clock::now();

    // Print result and computation time
    cout << "\nInverse vector: "; print_vector(inv_vec);
    cout << "Size of inverse vector: " << sizeof(vector<double>) << " bytes \n";
    cout << "Computation time: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";

    return 0;

}

// Print elements of a vector
void print_vector(vector<double> v) {

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

}

// Compute inverse of a vector
vector<double> inverse_vector(vector<double> v) {

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) throw runtime_error("\nDivision by zero in inverse_vector");
        v[i] = 1.0 / v[i];
    }
    
    return v;

}
