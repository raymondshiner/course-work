#include <stdio.h>

void function1(int array[][3], int rows, int cols);
void function2(int array[][3], int rows, int cols);
void function3(int array[], int rows, int cols);
void function4(int array[], int rows, int cols);
void function5(int * array, int rows, int cols);
void function6(int (*array)[3], int rows, int cols);
void function7(int **array, int rows, int cols);


int main()
{
	int twod[4][3] = { {0, 1, 2}, {10, 11, 12}, {20, 21, 22}, {30, 31, 32} };
	// NOTE: a 2D array is a double pointer so you have to derefernce the name
	// to be able to use a 1D pointer
	int *ptr = *twod;

	/* This gives us an idea of the memory map */
	printf("sizeof(ptr) %ld\n", sizeof(ptr) );
	printf("sizeof(twod[0]) %ld\n", sizeof(twod[0]) );
	printf("sizeof(twod[0][0]) %ld\n", sizeof(twod[0][0]) );

	printf("twod %p\n", twod);
	printf("ptr %p\n", ptr);

	printf("&twod[0] %p\n", &twod[0]);
	printf("&twod[0][0] %p\n", &twod[0][0]);
	printf("&twod[0][1] %p\n", &twod[0][1]);
	printf("&twod[0][2] %p\n", &twod[0][2]);

	printf("&twod[1] %p\n", &twod[1]);
	printf("&ptr %p\n", &ptr);
	/* end memory map */

   	printf("twod + 3 is: %p\n", twod + 3);
   	printf("*(*(twod + 1)) is: %d\n", *(*(twod + 1)));
   	printf("*twod + 1 is: %p\n", *twod+1);
   	printf("*twod[2] is: %d\n", *twod[2]);
   	printf("*(twod + 2) + 2 is: %p\n", *(twod + 2) + 2);
   	printf("twod[1] is: %p\n", twod[1]);
   	printf("twod[1][2] is: %d\n", twod[1][2]);
   
   	printf("ptr %p\n", ptr);
   	printf("twod [1] %p\n", twod [1]);
   	printf("ptr[1] %d\n", ptr[1]);
   	printf("ptr + 1 %p\n", ptr + 1);
   	printf("*(ptr + 1) %d\n", *(ptr + 1) );
   	printf("twod + 1 %p\n", twod+1);
   	printf("*twod + 1 %p\n", *twod + 1);
   	printf("ptr[8] %d\n", ptr[8]);

	function1(twod,4,3);
	function2(twod,4,3);
	function3(twod[0],4,3);
	function4(twod[0],4,3);
	function5(twod[0],4,3);
	function6(twod,4,3);
	function7(twod,4,3);

	return 0;

}// end main

void function1(int twod[][3], int rows, int cols)
{
	int x,y;
	printf("function 1\n");

	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			printf("%d ", twod[x][y]);
		}
		printf("\n");
	}
}

void function2(int twod[][3],int rows,int cols)
{
	printf("function 2\n");
	int x,y;
	for(x = 0; x < rows; x++)
	{
		for(y = cols; y > 0; y--)
		{
			printf("%d ", *(*(twod + x)+y - 1));
		}
		printf("\n");
	}
	
}

void function3(int twod[],int rows, int cols)
{
	int x,y, index;
	index = 0;

	printf("function 3 \n");
	
	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			
			printf("%d ", twod[index]);
			index++;
		}
		printf("\n");
	}


}

void function4(int twod[], int rows, int cols)
{
	int x, y;
	int index = 2; //first index to be printed out

	printf("function 4 \n");
	for(x = 0; x < rows; x++)
	{
		for(y = cols; y > 0; y--)
		{
			printf("%d ", *(twod + index));
			index --;
		}
		index = index + 6; //sets it to the index we want first in the next row
		printf("\n");
	}
}


void function5(int *twod, int rows, int cols)
{
	printf("function 5\n");
	int x, y;
	int index = 2;

	for(x = 0; x < rows; x++)
	{
		for(y = cols; y > 0; y--)
		{
			printf("%d ", twod[index]);
			index --;
		}
		index = index + 6;
		printf("\n");
	}
}


void function6(int(*twod)[3],int rows, int cols)
{
	int x,y;

	printf("function 6\n");
	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			printf("%d ", twod[x][y]);
		}
	
		printf("\n");
	}
}

void function7(int **twod, int rows, int cols)
{
	//THIS FUNCTION WON'T WORK
}







