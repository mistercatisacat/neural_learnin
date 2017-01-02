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

  read_weights(n,"test_weights");
  save_weights(n,"pre set");

  init_weights(n);
  save_weights(n,"post set");

  // do code with the data structure
  clear_network(&n);
}
