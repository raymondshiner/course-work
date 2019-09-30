#ifndef LAB11_H
#define LAB11_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare your structure here
struct Stock
{
	char symbol[10];
	char companyName[100];
	double currentPrice;
};




/**
 * Reads from the file and creates a structure and places it into the array.  Look at the file
 * to understand what the contents of the file are
 */
int fillArray(struct Stock array[], FILE * fin);
int menu();

/**
 * Sorts the array based on the stock symbol
 * You will need strcmp
 */
void symbolSort(struct Stock array[], int total);
void printArray(struct Stock array[], int total);

/**
 * Sorts the array based on the company name
 * You will need strcmp
 */
void companySort(struct Stock array[], int total);

/**
 * Sorts the array based on the stock price which is a double
 * Multiple by 100 and cast
 */
void priceSort(int total, struct Stock array[]);



#endif
