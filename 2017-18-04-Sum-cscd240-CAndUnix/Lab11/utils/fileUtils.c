#include "fileUtils.h"

FILE * openInputFile()
{
	FILE *inputFile = fopen("stocks.txt","r");

	return inputFile;

}//end of openInputFile

