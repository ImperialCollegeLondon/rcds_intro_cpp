// Data structure with points
struct point2d {
  double *coordinate;
  double distance;
};

// Assignt to distance the distance between coordinates and center
void compute_distance(point2d &p)
{
  p.distance = sqrt(pow(p.coordinate[0],2) + pow(p.coordinate[1],2));
}

// Compute the mean of the distance in an array point2d
double mean(const point2d *v, int n)
{
  double sum = 0;
  for (int i = 0; i < n; i++)    
    sum += v[i].distance;
  return sum / n;
}

// ROOT macro
void exercise6() {

  // Create variables
  const int n = 1000;
  point2d punti[n];

  fstream f;
  f.open("../data.dat", ios::in);

  if (!f.good())
    {
      cerr << "Error reading file data.dat" << endl;
      return;
    }

  // Read file and load data
  for (int k = 0; k < n; k++)
    {
      punti[k].coordinate = new double[2];
      f >> punti[k].coordinate[0] >> punti[k].coordinate[1];

      // Compute distance
      compute_distance(punti[k]);
    }
  
  f.close();

  cout << "mean = " << mean(punti, n) << endl;

  // Clean memory
  for (int k = 0; k < n; k++)
    delete[] punti[k].coordinate;

}