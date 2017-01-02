#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H

typedef double (*Sigfun)(double);

Sigfun functions[1];
Sigfun d_functions[1];

void init_functions();

Sigfun get_func(int n);


static double logistic(double x);
static double d_logistic(double x);

#endif
