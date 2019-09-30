#include "fileUtils.h"

void readFileName(char * fn)
{
	printf("Please enter your file name: ");
	fgets(fn,MAX,stdin);
	strip(fn);
	
}// end readFileName


FILE * openInputFile(char * fn)
{
	FILE *inputFile;
	inputFile = fopen(fn,"r");

	return inputFile;
	
}// end openInputFile


void strip(char * array)
{
	int len = strlen(array);
	
	int x = 0;
	
	while(x < len)
	{
		if(array[x] == '\r')
			array[x] = '\0';
			
		else if(array[x] == '\n')
			array[x] = '\0';
			
		x++;
	}// end while

}// end strip
