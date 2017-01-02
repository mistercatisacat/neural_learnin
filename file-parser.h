#if !defined(FILE_PARSER_H)
#define FILE_PARSER_H

#include "network.h"

Network* read_network(char filename[]);
void save_weights(Network *n, char filename[]);
void read_weights(Network *n, char filename[]);

Vector read_vector(char filename[]);
Traning_set read_traning_set(char filename[], int num, int input_size, int expected_size);

#endif
