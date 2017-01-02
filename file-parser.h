#if !defined(FILE_PARSER_H)
#define FILE_PARSER_H

#include "network.h"

Network* read_network(char filename[]);
void save_weights(Network *n, char filename[]);
void read_weights(Network *n, char filename[]);

#endif
