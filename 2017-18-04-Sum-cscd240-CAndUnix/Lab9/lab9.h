#ifndef LAB9_H
#define LAB9_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int playAgain();
void instructions();
int isWinner(char *);
void readName(char *);
void readWord(char *);
char makeCharLowerCase(char a);
int playGame(char *, char *, int);
void printResults(int, char *, char *);
int isLetterInWord(char, char *, char *, int);


#endif
