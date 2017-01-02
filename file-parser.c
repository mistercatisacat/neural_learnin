#include <stdio.h>
#include <stdlib.h>
#include "file-parser.h"

#define BUFF_SIZE 1000

Network* read_network(char filename[]) {
        Network* n = NULL;
        FILE* f = fopen(filename,"r");
        char buffer[BUFF_SIZE];
        if (f == NULL) {
                fprintf(stderr, "could not open file: %s\n",filename );
                return n;
        }
        n = malloc(sizeof(Network));
        n->num = 0;
        n->layers = NULL;
        n->height = 0;
        while (fgets(buffer,BUFF_SIZE - 1,f)) {
              //  printf("line: %s",buffer);
                int num,f_type,i;
                sscanf(buffer,"%d %d",&num,&f_type);
                n->num++;
                // use this so that the max height is stored in the network struct
                if (n->height < num){
                  n->height = num;
                }
                n->layers = realloc(n->layers,sizeof(Layer) * n->num);
                n->layers[n->num -1].num = num;
                n->layers[n->num -1].neurons = malloc(sizeof(Neuron) * num);
                n->layers[n->num -1].f_type = f_type;
                if (n->num > 1) {
                        for (i=0; i<n->layers[n->num -1].num; i++) {
                                n->layers[n->num -1].neurons[i].num = n->layers[n->num - 2].num;
                                n->layers[n->num -1].neurons[i].weights = malloc(sizeof(double) *
                                                                                 n->layers[n->num -1].neurons[i].num);
                              //  printf("prev\n");
                        }
                }else{
                        for (i=0; i<n->layers[n->num -1].num; i++) {
                                n->layers[n->num -1].neurons[i].num = 0;
                                n->layers[n->num -1].neurons[i].weights = NULL;
                            //    printf("no prev\n");
                        }
                }
        }
        fclose(f);
        return n;
}


void save_weights(Network *n, char filename[]){
  FILE* f = fopen(filename,"w");
  int i,j,k;
  if(f == NULL){
    return;
  }
  // loop through the layers
  for (i =1; i < n->num; i ++){
    // loop through the neurons
    for (j =0; j < n->layers[i].num; j++){
      // loop through weights
      for (k =0; k < n->layers[i].neurons[j].num; k++){
        fprintf(f, "%f\n", n->layers[i].neurons[j].weights[k]);
      //  fprintf(stdout, "%f ", n->layers[i].neurons[j].weights[k]);
    }
      //fprintf(stdout, "\n");
    }
  }
  fclose(f);
}

void read_weights(Network *n, char filename[]) {
  FILE* f = fopen(filename,"r");
  int i,j,k;
  char buffer[BUFF_SIZE];
  if(f == NULL){
    return;
  }
  // loop through the layers
  for (i =1; i < n->num; i ++){
    // loop through the neurons
    for (j =0; j < n->layers[i].num; j++){
      // loop through weights
      for (k =0; k < n->layers[i].neurons[j].num; k++){
        if (fgets(buffer,BUFF_SIZE - 1,f) == NULL){
          //break out of the loop
          i = n->num;
          j =  n->layers[i].num;
          k = n->layers[i].neurons[j].num;
        }else{
          printf("%s",buffer);
          sscanf(buffer, " %lf",&(n->layers[i].neurons[j].weights[k]));
        }
      }
    }
  }
}
