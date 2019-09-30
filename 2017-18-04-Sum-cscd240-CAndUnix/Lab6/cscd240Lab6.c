#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"
#include "fileUtils.h"

#define MAX 100

int main()
{

	int monthDays, choice;
	int * temps;
	FILE * fin = NULL;
	char fn[MAX];

	readFileName(fn);	
	fin = openInputFile(fn);

	monthDays = readDays(fin);
	temps = fillArray(monthDays, fin);

	do
	{
		choice = menu();

		if(choice == 1)
		{
			displayMaxTemp(temps, monthDays);

		}// end choice == 1

		else if(choice == 2)
		{
			displayMinTemp(temps, monthDays);
		}// end choice == 2

		else if(choice == 3)
		{
			displayAvgTemp(temps, monthDays);
		}// end choice == 3

		else if(choice == 4)
		{
			displayMedianTemp(temps, monthDays);

		}// end choice == 4

		else if(choice == 5)
		{
			displayModeTemp(temps, monthDays);

		}// end choice == 5


		else if(choice == 6)
		{
			fclose(fin);
			fin = NULL;
			cleanUp(temps);
			temps = NULL;
			
			readFileName(fn);
			fin = openInputFile(fn);
			
			monthDays = readDays(fin);
			temps = fillArray(monthDays, fin);

		}// end choice == 6

	}while(choice != 7);

	fclose(fin);

	cleanUp(temps);
	temps = NULL;

}// end main

