#if !defined(NETWORK_H)
#define NETWORK_H

typedef struct {
  int num;
  double* weights;
  double* new_weights;
  double output;
} Neuron;

typedef struct {
  int num;
  int f_type;
  double bias;
  Neuron* neurons;
}Layer;

typedef struct {
  int num;
  int height;
  Layer* layers;
}Network;

typedef struct vector{
  int size;
  double *elements;
} Vector;

typedef struct {
  int num;
  Vector* inputs;
  Vector* expected;
} Traning_set;


void init_weights(Network* n);

void clear_network(Network** n);

void feed_forward(Network* n, Vector* input);

double get_error(Network *n, Vector* expected);

Vector run_set(Network *n, Traning_set set);

void clear_vector(Vector* v);

void clear_traning_set(Traning_set* set);

#endif
