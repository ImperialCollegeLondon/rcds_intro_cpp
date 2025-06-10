// Import libraries
#include <iostream>
#include <vector>
using namespace std;

// Print elements of a vector
void print_vector(vector<double> v) {

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

}

// Function to find maximum element
int find_max(vector<double> v) {

    // Handle empty vector
    if (v.empty()) return 0.0;
    
    int max_val = v[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > max_val) {
            max_val = v[i];
        }
    }
    
    return max_val;

}

// Function to find minimum element
int find_min(vector<double> vec) {

    // Handle empty vector
    if (vec.empty()) return 0.0;
    
    int min_val = vec[0];
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min_val) {
            min_val = v[i];
        }
    }

    return min_val;

}

// Function to find mean value
double find_mean(vector<double> vec) {

    // Handle empty vector
    if (vec.empty()) return 0.0;
    
    double sum = 0;
    for (int num : vec) {
        sum += num;
    }

    return sum / vec.size();

}

// Function to find most frequent element
int find_mode(vector<double> vec) {

    // Handle empty vector
    if (vec.empty()) return 0.0;
    
    // Manually count frequencies
    int max_freq = 0;
    int mode = vec[0];
    
    for (size_t i = 0; i < vec.size(); ++i) {

        int freq = 1;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] == vec[j]) {
                freq++;
            }
        }
        
        if (freq > max_freq) {
            max_freq = freq;
            mode = vec[i];
        }
        
    }

    return mode;

}

// Main function
int main() {

    // Declare variables
    int n;
    cout << "Enter the size of a vector: "; cin >> n;
    vector<double> vec(n);
    cout << "Enter elements of vector separated by space: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Display original vector
    print_vector(vec);

    // Compute and display statistics
    cout << "Max: " << find_max(vec) << endl;
    cout << "Min: " << find_min(vec) << endl;
    cout << "Mean: " << find_mean(vec) << endl;
    cout << "Mode: " << find_mode(vec) << endl;

    return 0;

}