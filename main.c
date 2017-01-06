#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "functions.h"
#include "file-parser.h"

Network* n;

int main(){
  init_functions();
  char filename[] = "xor.net";
  //int *p = malloc(sizeof(int));
 //free(NULL);
  Network* n = read_network(filename);
//  save_weights(n,"pre pre set");

  //read_weights(n,"test_weights");
//  save_weights(n,"pre set");

  init_weights(n);
 // read_weights(n,"xor_weights");


  //Vector input;
  //Vector expected;

//  input = read_vector("nb.input");
  //expected = read_vector("nb.expected");
  Traning_set set = read_traning_set("basic_set", 4, 2, 1);



  int k;
  for (k =0 ;k<2000;k++){
    Vector errors = run_set(n,set,0.5);
    int i = 0;
    for (i = 0; i < errors.size;i++){
      printf("error %d: %f\n",i, errors.elements[i]);
    }
    clear_vector(&errors);
  }

  save_weights(n,"xor_weights");

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
