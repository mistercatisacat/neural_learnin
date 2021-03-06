#include "network.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "functions.h"
#include "back-prop1.h"

void init_weights(Network* n) {
  srand(time(NULL));
  int i,j,k;
  // loop through layers and skip the first layer
  for (i =1;i < (n)->num ;i++){
    // loop through neurons
      n->layers[i].bias = (((double) rand())/RAND_MAX);
    for (j = 0;j < (n)->layers[i].num; j++){
      // loop through the weights
      for(k = 0;k < n->layers[i].neurons[j].num;k ++){
         n->layers[i].neurons[j].weights[k] = (((double) rand())/RAND_MAX);
      }
    }
  }
}

void clear_network(Network** n){
  int i,j,k;
  if (n == NULL)
    return;
// loop through layers
  for (i =0;i < (*n)->num ;i++){
  // loop through neurons
    for (j = 0;j < (*n)->layers[i].num; j++){
      free((*n)->layers[i].neurons[j].weights);
      free((*n)->layers[i].neurons[j].new_weights);
    }
    free((*n)->layers[i].neurons);
  }
  free((*n)->layers);
  free(*n);
  (*n) = NULL;
}



void feed_forward(Network* n, Vector* input) {
  int i,j;

  // iterate throught the layers
  for(i =0 ;i < n->num; i++){
    int f_type = n->layers[i].f_type;
    // iterate through the neurons
    for(j = 0;j < n->layers[i].num; j ++){
      // first layer
      if (i == 0){
        // input was specifed for this specific neuron
        if (input->size > j){
        //  n->layers[i].neurons[j].input = input->elements[j];
          n->layers[i].neurons[j].output = functions[f_type](input->elements[j]);
        }else{
      //    n->layers[i].neurons[j].input = 0;
          n->layers[i].neurons[j].output = functions[f_type](0);
        }
      }else{ //rest of the layers. A sum needs to be calculated and weights multiplied
        double sum = 0;
        Neuron* curr = &n->layers[i].neurons[j];
        int k;
        // sum up the weights times the previous neurons output
        for (k=0;k < curr->num; k ++){
          sum += n->layers[i-1].neurons[k].output * curr->weights[k];
        }
        // pass the sum through the function
      //  n->layers[i].neurons[j].input = sum + n->layers[i].bias;
        n->layers[i].neurons[j].output = functions[f_type](sum + n->layers[i].bias);
      }
    }
  }
}

double get_error(Network* n,Vector* expected){
  double sum = 0;
  int i;
  Layer* l = &n->layers[n->num - 1];
  for (i=0;i<l->num;i++){
    int expec = (expected->size > i)?expected->elements[i]:0;
    sum += 0.5*pow(expec - l->neurons[i].output,2);
  }
  return sum;
}

Vector run_set(Network *n, Traning_set set, double learning_rate) {
  int i;
  Vector errors;
  errors.size = set.num;
  errors.elements = malloc(sizeof(double) * set.num);
  for (i=0; i<set.num; i++){
    feed_forward(n,&(set.inputs[i]));
    errors.elements[i] = get_error(n,&(set.expected[i]));
//    printf("Prop_back i = %d\n",i);
    prop_back(n, learning_rate, &(set.expected[i]));
  }
  return errors;
}

void clear_vector(Vector* v){
  v->size = 0;
  free(v->elements);
  v->elements = NULL;
}

void clear_traning_set(Traning_set* set){
  int i;
  for (i = 0;i < set->num;i++){
    clear_vector(&set->inputs[i]);
    clear_vector(&set->expected[i]);
  }
  free(set->inputs);
  free(set->expected);
  set->inputs = NULL;
  set->expected = NULL;
  set->num = 0;
}
