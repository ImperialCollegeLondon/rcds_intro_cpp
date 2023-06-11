// Implementation
#include "functions.h"

void change1(double &a, double &b) {

  double dep = b;
  b = a;
  a = dep;

}

void change2(double *a, double *b) {

  double dep = *b;
  *b = *a;
  *a = dep;
  
}
