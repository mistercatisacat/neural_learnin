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
//  save_weights(n,"pre pre set");

  //read_weights(n,"test_weights");
//  save_weights(n,"pre set");

  init_weights(n);
  save_weights(n,"basic_weights");

  //Vector input;
  //Vector expected;

//  input = read_vector("nb.input");
  //expected = read_vector("nb.expected");

  Traning_set set = read_traning_set("basic_set", 4, 2, 1);
  Vector errors = run_set(n,set);
  int i = 0;
  for (i = 0; i < errors.size;i++){
    printf("error %d: %f\n",i, errors.elements[i]);
  }

  clear_vector(&errors);
  clear_traning_set(&set);

//  printf("pre feed %f\n", (n)->layers[n->num - 1].neurons[0].output);
//  feed_forward(n,&input);
//  printf("post feed %f\n", (n)->layers[n->num - 1].neurons[0].output);
//  printf("error: %f\n",get_error(n,&expected));
//  clear_vector(&input);
//  clear_vector(&expected);
  // do code with the data structure
  clear_network(&n);
}
