#if !defined(NETWORK_H)
#define NETWORK_H

typedef struct {
  int num;
  double* weights;
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

typedef struct {
  int size;
  double *elements;
} Vector;


void init_weights(Network* n);

void clear_network(Network** n);

void feed_forward(Network* n, Vector* input);

#endif
