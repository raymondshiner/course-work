#include "lab11.h"
#include "./utils/utils.h"




int menu()
{
	int num;
	do
	{
		printf("Please choose from the following\n");
   		printf("1) Sort by Symbol\n");
   		printf("2) Sort by Company Name\n");
   		printf("3) Sort by Price\n");
   		printf("4) Quit\n");
   		printf("Choice --> ");
   		scanf("%d", &num);
	}while(num < 1 && num > 4);
 
   return num;
}// end menu


int fillArray(struct Stock array[], FILE *fin)
{
	//int x = 0;
	//char stringPrice[10];
	//checking for end of file
	char temp[100];
	int count = 0;

	fgets(temp, 100, fin); // file init

	while(!feof(fin))
	{
		fgets(temp, 100, fin);
		count++;
	}

	int records = count/3;
	//count = count/3;

	rewind(fin);

	int x;

	for(x = 0; x<records; x++)
	{
		fgets(temp, 100, fin);
		strip(temp);
		strcpy(array[x].symbol, temp);

		fgets(temp, 100, fin);
		strip(temp);
		strcpy(array[x].companyName, temp);

		fscanf(fin, "%lf", &array[x].currentPrice);
		fgets(temp, 100, fin);
	}

	return records;
/*
	do
	{
		fgets(array[x].symbol, 10, fin);
		strip(array[x].symbol);

		fgets(array[x].companyName,100,fin);
		strip(array[x].companyName);
		
		fgets(stringPrice,10,fin);
		strip(stringPrice);
		sscanf(stringPrice,"%lf", &array[x].currentPrice);
		
		x++;
	}while(!feof(fin)); 

	return x; //returns the elements in the array

 */
}

void symbolSort(struct Stock array[], int total)
{
	int sorted,search,index;
	for(sorted = 0; sorted < total; sorted++)
	{
		index = sorted;
		for(search = sorted + 1; search < total; search++)
		{
			if(strcmp(array[search].symbol,array[index].symbol) < 0)
				index = search;
		}

		struct Stock temp = array[index];
		array[index] = array[sorted];
		array[sorted] = temp;
	}
}
void printArray(struct Stock array[], int total)
{
	int x;
	for(x = 0; x < total; x++)
	{
		printf("%s - %s - %.3lf\n",array[x].companyName,array[x].symbol,array[x].currentPrice);
	}
}
void companySort(struct Stock array[], int total)
{
	int sorted,search,index;
	for(sorted = 0; sorted < total; sorted++)
	{
		index = sorted;
		for(search = sorted + 1; search < total; search++)
		{
			if(strcmp(array[search].companyName,array[index].companyName) < 0)
				index = search;
		}

		struct Stock temp = array[index];
		array[index] = array[sorted];
		array[sorted] = temp;
	}
}

void priceSort(int total, struct Stock array[])
{
	int sorted,search, index;
	for(sorted = 0; sorted < total; sorted++)
	{
		index = sorted;
		for(search = sorted + 1; search < total; search++)
		{
			if(array[search].currentPrice < array[index].currentPrice)
				index = search;
		}

		struct Stock temp = array[index];
		array[index] = array[sorted];
		array[sorted] = temp;
	}
}
