#include "utils.h"

void strip(char * array)
{
	int x = 0;
	while (array[x] != '\0' && x < strlen(array))
	{
		if(array[x] == '\r')
			array[x] = '\0';

		else if(array[x] == '\n')
			array[x] = '\0';

		x++;

	}// end while
}// end function

void toUppercaseString(char * array)
{
	int x;
	for(x = 0; x < strlen(array); x++)
	{
		if(array[x] >= 'a' && array[x] <= 'z')
			array[x] = (char)array[x] - 32;;
	}

}// end function

void toLowercaseString(char * array)
{
	int x;
	for(x = 0; x < strlen(array); x++)
	{
		if(array[x] >= 'A' && array[x] <= 'Z')
			array[x] = (char)array[x] + 32;;
	}
}// end function

void stripInputBuffer(FILE * fin)
{
	while(fgetc(fin) != '\n')
	{}
}// end function
