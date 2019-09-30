#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void readFileName(char * fn);
FILE * openInputFile(char * fn);
void strip(char * array);

#endif