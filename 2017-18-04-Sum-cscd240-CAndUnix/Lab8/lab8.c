#include "lab8.h"

int menu()
{
	int choice;
	do
	{
		printf("Please choose from the following menu\n");
		printf("1) Print triangle to the screen\n");
		printf("2) Print triangle to a file\n");
		printf("3) Create a new triangle\n");
		printf("4) Quit\n");
		printf("----->");
		scanf("%d",&choice);
	}while(choice < 0 || choice > 4);
	return choice;
}

int readTotal()
{
	int num;
	printf("Please enter the total number of rows ");
	scanf("%d", &num);

	while(num < 1)
	{
		printf("Please enter the total number of rows ");
		scanf("%d", &num);
	}	
   
   return num;
}
void cleanUp(int ** pascal, int n)
{
	int x;
	for(x = 0; x < n; x++)
	{
		free(pascal[x]);
		pascal[x] = NULL;
	}
	free(pascal);

}
int ** createTriangle(int n)
{
	int **pascal = (int**)calloc(n,sizeof(int*));

	int r;
	for(r = 0; r < n; r++)
		pascal[r] = (int*)calloc(r+1,sizeof(int));




	**pascal = 1;
	**(pascal+1) = 1;
	*(*(pascal + 1)+1) = 1;

	int c;
	for(r = 2; r < n; r++)
	{
		for(c = 0; c <= r; c++)
		{
			if(c == 0 || c== r)
			{
				*(*(pascal + r)+c) = 1; 
			}
			else
			{
				*(*(pascal + r)+c) = *(*(pascal + r - 1)+ c - 1) + *(*(pascal + r - 1)+c);
		
			}
		}
	}



	return pascal;
}
void printTriangle(FILE * fout, int ** pascal, int n)
{
	int r,c;
	for(r = 0; r < n; r++)
	{
		for(c = 0; c <= r; c++)
		{
			fprintf(fout,"%d ",*(*(pascal+r)+c));
		}
		fprintf(fout,"\n");
	}

}
int retrieveTotal(char * argv)
{
	return atoi(argv);
}
