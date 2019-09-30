#include "lab9.h"
#include "./utils/utils.h"

void instructions()
{
	printf("\n----------  Hello and welcome to HangMan!  ----------\n\n"
			"This is a word guessing game.\nIt is suggested that you have 2 players,"
			"\nunless you are really lonely, then you can play by yourself.\n"
			"We will start by having player 1 enter in their name, and the word they would\n"
			"like player 2 to guess. Then player 2 will enter their name, and begin guessing.\n"
			"Player 2 will begin with 7 chances to guess the word correctly,\n"
			"you will only lose chances when you guess incorrectly.\n"
			"\n---------- GOOD LUCK & HAVE FUN! ----------\n");
}

int playAgain()
{
	char throwAway = getchar();
	char answer[MAX];

	do
	{

		printf("Would you like to play again (yes/no)? \n");
		fgets(answer,MAX,stdin);
		strip(answer);
	
	}while(strlen(answer) > 4); //this ensures yes/no

	
	int x;
	for(x = 0;x < strlen(answer); x++)
	{
		answer[x] = makeCharLowerCase(answer[x]);
	}


	if(answer[0] == 'y')	//if answer is yes we can just check y. if not 
		return 1;	//the no will be the answer
	else
		return 0;

}

int isWinner(char *var)
{

	return 0;
}

void readName(char *name)
{
	printf("Please enter your name: \n");
	fgets(name,MAX,stdin);
	strip(name);
}

void readWord(char *word)
{
	printf("Please enter the word to guess: \n");
	fgets(word,MAX,stdin);
	strip(word);
}

char makeCharLowerCase(char letter)
{
	if(letter >= 'A' && letter <= 'Z')
		letter = (char)(letter+32);

	return letter;
}

int playGame(char *word, char*alphabet, int wordLen)
{
	
	char unknownWord[wordLen];
	int x;
	for(x = 0; x < wordLen; x++)
		unknownWord[x] = (char)'-';  	//init of word checker
					//will look like: [-,-,-,-,-,-,-,-,-]
	
	
	
	
	printf("Your word contains %d letters.\n",wordLen);
	printf("\n");

	
	
	
	
	for(x = 0; x < wordLen; x++)
	{
		printf("%c",unknownWord[x]);

	}
	printf("\n");
	




	char letter;
	int guesses = 7, wordGuessed = 0, foundLetter = 0;
	do
	{
		printf("Avalible Letters: ");
		for(x = 0; x < strlen(alphabet); x++)
		{
			printf("%c",alphabet[x]);
		}
		printf("\n");

			
		for(x = 0; x < wordLen; x++)
		{
			printf("%c",unknownWord[x]);
		}
		printf("\n");



		printf("Please enter a letter: ");
		scanf("%c",&letter);

		char throwaway = getchar(); //removal of rogue carriage return to appease the code gods

		foundLetter = isLetterInWord(letter,word,alphabet,wordLen);
			
		if(foundLetter)

		{

			for(x = 0; x < strlen(word); x++)
			{
				if(word[x] == letter)
					unknownWord[x] = letter;
			}
		}

		else
		{
			guesses--;
			printf("\n Incorrect guess! You have %d more tries!\n", guesses);
		}
		
		for(x = 0; x < wordLen; x++)
		{
			if(unknownWord[x] == (char)'-')
			{
				wordGuessed= 0;
				break;
			}
			
			else
				wordGuessed = 1;
		}


	}while(wordGuessed == 0 && guesses != 0);

	return wordGuessed;
}


void printResults(int winner, char *name, char* word)
{
	if(winner)
		printf("Congradulations, %s! You figured out the word was: %s",name,word);
	else
		printf("Sorry, %s. You failed to figure out the word is: %s",name,word);
}

int isLetterInWord(char letter, char *word, char*alphabet, int wordLen)
{
	int x;
	for(x = 0; x < strlen(alphabet); x++)
	{
		if(alphabet[x] == letter)
			alphabet[x] = ' ';
	}//ensures letter is removed from alphabet

	
	for(x = 0; x < wordLen; x++)
	{
		if(word[x] == letter)
			return 1;
	}


	return 0;
}




