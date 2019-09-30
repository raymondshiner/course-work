#include "lab5.h"

int readInitialLength()
{
	int length;
	do
	{
		printf("Please enter a number greater than 0: ");
		scanf("%d",&length);
	}while(length<1);

	return length;

}

int *createAndFill(int length)
{
	int *temp = (int*)calloc(length, sizeof(int));
	int x;
	
	for(x = 0; x < length; x++)
	{
		printf("please enter a number: ");
		scanf("%d",&temp[x]);
	}

	return temp;
}

int menu()
{
	int choice = 0;
        
	printf("Please choose from the following menu: \n");
        printf("\n");
        printf("1) Print the sorted array \n2) Add an item to the array \n3) Find a number in the array \n4) Quit \n\nEnter here: ");
        
	scanf("%d",&choice);

	
	printf("%d",choice);

    return choice;
}

void printSortedArray(int *array, int length)
{
	int i, j, temp, smallest;

	for(i = 0; i < length - 1; i++)
	{
		smallest = i;
		for(j = i + 1; j < length; j++)
		{
			if(array[j] < array[smallest])
				smallest = j;
		}

		temp = array[smallest];
		array[smallest] = array[i];
		array[i] = temp;
	}
	
	int x;
	for(x = 0; x < length; x++)
		printf("%d\n",array[x]);

}



int *addItem(int *length, int *array)
{
	int otherLength = *length;
	int* temp = (int*)calloc(*length + 1, sizeof(int));
	
	int x;	
	for(x = 0; x < *length; x++);
	{
		temp[x] = array[x];
	}	
	
	printf("Please enter a integer: ");
	scanf("%d", &temp[x]);

	cleanUp(array);
	*length = otherLength + 1;
	return temp;
}



int readValue()
{
	int num = 0;

	printf("Please enter the number you want to find in the array: ");
	scanf("%d",&num);

	return num;


}
void printIfFound(int value, int * array, int length)
{

	int x;
	int found = 0;
	for(x = 0; x < length; x++)
	{
		if(array[x] == value)
			found = 1;
	}

	if(found != 0)
	{
		printf("Your value %d was found at index %d.\n", value, x);
	}

	else
		printf("Your value wasn't contained within your array.\n");	

}

void cleanUp(int *array)
{
	free(array);
	array = NULL;

}

