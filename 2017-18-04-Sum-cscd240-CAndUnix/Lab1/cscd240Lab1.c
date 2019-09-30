#include <stdio.h>
#include <stdlib.h>

int main()
{

	int bYear, result;
	double shoeSize;

	printf("Please enter your shoe size ");
	fscanf(stdin, "%lf", &shoeSize);

	printf("Please enter your birth year (yyyy) ");
	fscanf(stdin, "%d", &bYear);

	printf("The last two numbers are your age and ");
	

	 
	int temp = shoeSize;
	result = ( (temp * 5 + 50) * 20 + 1018 -  bYear);   

	printf("the first number(s) are your shoe size: %d\n", result); 
	
    return 0;
}// end main


