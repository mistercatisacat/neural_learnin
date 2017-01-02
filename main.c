#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "functions.h"
#include "file-parser.h"


Network* n;

int main(){
  init_functions();
  char filename[] = "basic.net";
  //int *p = malloc(sizeof(int));
 //free(NULL);
  Network* n = read_network(filename);
  save_weights(n,"pre pre set");

  //read_weights(n,"test_weights");
  save_weights(n,"pre set");

  init_weights(n);
  save_weights(n,"post set");

  Vector v;
  v.size = 1;
  v.elements = malloc(sizeof(double) * v.size);
  v.elements[0] = 4;
  printf("pre feed %f\n", (n)->layers[n->num - 1].neurons[0].output);
  feed_forward(n,&v);
  printf("post feed %f\n", (n)->layers[n->num - 1].neurons[0].output);

  // do code with the data structure
  clear_network(&n);
}
