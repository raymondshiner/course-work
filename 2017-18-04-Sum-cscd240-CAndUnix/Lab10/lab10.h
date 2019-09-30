#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void strip(char *s);
char * cleanUp(char * str);
char** clean(int argc, char **argv);
void printargs(int argc, char **argv);
char ** makeargs(char *s, int * argc);
char * readString();

#endif
