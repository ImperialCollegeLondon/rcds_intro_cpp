/*
  Exercise: Discriminating points
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <cmath>
using namespace std;

// Compute the Pythagorean distance between points (x,y) and (xc, yc)
double distance(const double x, const double y, const double xc, const double yc)
{
  return sqrt(pow(x-xc, 2) + pow(y-yc, 2));
}

// Verify if a point (x,y) is inside of a circle
void check_circle(const double x, const double y, const double xc, const double yc, const double r, bool &status)
{
  const double d = distance(x, y, xc, yc);
  if (d <= r)
    status = true;
  else
    status = false;
}

int main() {

  const double xc = 1, yc = 1, r = 1;
  double x, y;
  bool status;

  for(;;)
    {
      cout << "\nIntroduce coordinate (x,y): " << endl;
      cin >> x >> y;
      if (cin.eof()) break;

      check_circle(x, y, xc, yc, r, status);
      if (status)
	      cout << "The point is inside of the circle." << endl;
      else
	      cout << "The point is outside of the circle" << endl;
    }

  return 0;

}