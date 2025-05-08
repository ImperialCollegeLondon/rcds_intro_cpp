/*
  Exercise: Matrix manipulation
*/

#include <iostream>
using namespace std;

int main() {

  // Create variables
  const int n = 5;
  double v[n] = {2, 5, 10, 20, 50};
  double w[n] = {10, -5, 3, 1, 100};  
  
  // Print values of v
  cout << "Array v:" << endl;
  for (int i = 0; i < n; i++)
    cout << "v[" << i << "] = " << v[i] << endl;

  cout << "Array w:" << endl;
  // Print values of w
  for (int i = 0; i < n; i++)
    cout << "w[" << i << "] = " << w[i] << endl;

  // Create array s
  double s[n];

  // Initialize s with values of v
  for (int i = 0; i < n; i++)
    s[i] = v[i];

  // Sum values of w
  for (int i = 0; i < n; i++)
    s[i] += w[i];

  // Print s
  cout << "Array s = v + w:" << endl;
  for (int i = 0; i < n; i++)
    cout << "s[" << i << "] = " << s[i] << endl;
  
  return 0;

}