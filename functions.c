#include "functions.h"
#include <math.h>


void init_functions(){
  functions[0] = &logistic;
  d_functions[0] = &d_logistic;
}

double logistic(double x){
  return 1.0/(1 + exp(-x));
}

double d_logistic(double x){
  double l = logistic(x);
  return l*(1 - l);
}
