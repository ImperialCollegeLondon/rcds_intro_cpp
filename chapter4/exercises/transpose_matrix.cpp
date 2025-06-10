// Import libraries
#include <iostream>
#include <vector>
using namespace std;

// Function printing the elements of a matrix
void print_matrix(vector< vector<double> > matrix) {

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

}

// Function computing transpose
vector< vector<double> > transpose_matrix(vector< vector<double> > matrix) {

    // Declare variables
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector< vector<double> > transposed(cols, vector<double>(rows));

    // Compute transpose matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;

}
// Main function
int main() {

    // Declare variables
    int rows, cols;
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;

    // Initialize empty matrix
    vector< vector<double> > matrix(rows, vector<double>(cols));
    
    // Fill matrix elements
    cout << "Enter elements separated by space:\n";
    for (int i = 0; i < rows; i++) {

        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }

    }


    cout << "\nOriginal array:\n";
    print_matrix(matrix);

    // Transpose and check result
    vector< vector<double> > transposed = transpose_matrix(matrix);
    cout << "\nTranposed array:\n";
    print_matrix(transposed);

    return 0;

}