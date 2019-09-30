#include "lab9.h"

int main()
{
	do
	{
		char name1[MAX], name2[MAX], word[MAX];
		char alphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
		int wordLength, winner;

		instructions();
		readName(name1);
		readWord(word);
		readName(name2);

		wordLength = strlen(word);
		winner = playGame(word, alphabet, wordLength);
		printResults(winner, name2, word);

	}while(playAgain());

	return 0;

}// end main
