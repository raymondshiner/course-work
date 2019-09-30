#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.h"

int main()
{
	return 0;
}


int menu()
{
	return 0;
}

int readDays(FILE * fin)
{
	int days;
	fgets(days,MAX,fin);

	return days;
}

void cleanUp(int * array)
{
	free(array);
	array = NULL;
}

void sort(int * array, int total)
{
	//will fill in later
}

int * fillArray(int total, FILE * fin)
{

	char ignore[MAX];
	fgets(ignore,sizeof(ignore),fin); //this will skip the first line of the array b/c we know that is the days

	int * array = (int *)calloc(total,sizeof(int));
	
	int i;
	for(i = 0; i < total; i++)
	{
		fgets(array[x], MAX, fin);
	}

	fclose(fin);//file no longer needed

	return array;
}

void displayMaxTemp(int * array, int total)
{
	int max = array[0];
	int x;
	for(x = 1; x < total; x++)
	{
		if(max < array[x])
			max = array[x];
	}

	printf("The max temp for this month is: %d",max);

}

void displayMinTemp(int * array, int total)
{
	int min = array[0];
	int x;
	for(x = 1; x < total; x++)
	{
		if(min > array[x])
			min = array[x];
	}

	printf("The min temp for this month is: %d",min);
}

void displayAvgTemp(int * array, int total)
{
	double avg;
	int x;
	for(x = 0; x < total; x++)
	{
		avg = avg +  array[x];
	}

	avg /= total;

	printf("The average temp for this month is: %.1lf", total);
}

void displayModeTemp(int * array, int total)
{
	int counter = 0;
	int modeCount = 0;
	
	int numCheck = 0;
	int modeNum = 0;

	sort(array);

	int i;
	for(i = 0; i < total; i++)
	{
		numCheck = array[i];
		counter = 1;

		int j;
		for(j = i + 1; j < total; j++)
		{
			if(numCheck == array[j])
				counter++;
		}

		if(counter > counter2)
		{
			mode = first;
			modeIndex = counter;
		}
		
		else if(counter == modeCount)
		{
			if(mode > numCheck)
				mode = first;

		}
		else if(modeCount == 1)
			mode = array[0]; //this is because we already know the array is sorted
			
	}

	printf("The mode(most frequent number) for this month was: %d",mode);
}

void displayMedianTemp(int * array, int total)
{
	int med = 0;

	sort(array);


	if(total % 2 == 1)
	{
		med = array[total / 2];
	}

	else
	{
		med = array[total / 2] + array[total / 2 + 1];
		
		med = med / 2;
	}

	printf("The median temp for this month is: %d", med);
}











