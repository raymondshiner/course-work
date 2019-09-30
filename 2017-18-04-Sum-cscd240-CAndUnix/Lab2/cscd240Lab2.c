#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESS 15

int main()
{
	char goAgain;
	char name[100];
	int theNum, guess, range, counter;

	range = 0;
	counter = 0;

	while(range < 100)
	{
		printf("Please enter a number that is greater than 99\n:");
		scanf("%d",&range);	
	}

	getchar();//strips carriage return from the statement above.

	srand(time(0));
	theNum = rand() % range;

	printf("Please enter your name: ");
	fgets(name,100,stdin);	
	
	
	
	while(guess != theNum && counter != MAX_GUESS)
	{
		printf("\nPlease try and guess my number between 1 and %d: ", range);
		scanf("%d",&guess);
		
		while(guess < 1 || guess > range)
		{
			printf("\nSorry. Your number isn't in range. Please try again: ");
			scanf("%d",&guess);
		}
		
		counter++;
		
		if(guess < theNum)
			printf("Too small.\n");
		else if(guess > theNum)
			printf("Too big. \n");	
		
	}

	if(counter == MAX_GUESS)
		printf("\nI'm sorry. You couldn't guess the correct number with your given guesses.");

	else
	{
		printf("\nGood job %s, you guessed my number in only %d guesses.",name,counter);
	}
		


	
	printf("\nWould you like to try again y/n: ");
	scanf(" %c", &goAgain);	

	if(goAgain == 'y')
		main();
		

	return 0;

}// end main

