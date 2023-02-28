// Macro without functions

{

  // Create variables
  const int n = 1000;
  double *v = new double[n];
  for (int i = 0; i < n; i++)
    v[i] = rand() % 100;

  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += v[i];

  cout << "Mean value: " << sum / n << endl; 

  delete[] v;
}
