#include "lab10.h"


char * readString()
{
  /* You may not change this code */
  char s[MAX]; // MAX is set to 100
  printf("Enter a string: ");
  fgets(s, MAX, stdin);
  strip(s);


  char *temp = (char*)calloc(strlen(s) + 1,sizeof(char));
  strcpy(temp,s);

  return temp;
}// end readString

char ** clean(int argc, char **argv)
{
	int i;
	for(i = 0; i < argc; i++)
	{
		free(argv[i]);
		argv[i] = NULL;
	}
	free(argv);
    return NULL;
}// end clean

char * cleanUp(char * str)
{
    free(str);
    return NULL;

}// end cleanUp


void printargs(int argc, char **argv)
{
	int x;
	for(x = 0; x < argc; x++)
		printf("%s\n", argv[x]);

}// end printargs

char ** makeargs(char *s, int * argc)
{

	char *token = strtok(s," "); //first argument;
	
	while(token != NULL)
	{
		*argc = *argc + 1; //adding 1 argument
		token = strtok(NULL, " ");

	}//tells us how many args there are
	
	//Problem exists here. I'm taking the L. TTYL
	
	char **temp = (char**)calloc(*argc,sizeof(char*)); //creation of our array
	
	token = strtok(s, " ");
	
	int x;
	for(x = 0; x < *argc; x++)
	{
		strip(token);					//strips our token
		int size = strlen(token);			//gets str size
		temp[x] = (char *)calloc(size + 1,sizeof(char)); 	//alloc mem
		temp[x] = token;				//put our token here
		token = strtok(NULL," "); 			//get argument
	}

	return temp;
}// end makeArgs


void strip(char * array)
{
	int x = 0;
	while (array[x] != '\0' && x < strlen(array))
	{
		if(array[x] == '\r')
			array[x] = '\0';

		else if(array[x] == '\n')
			array[x] = '\0';
		x++;

	}// end while
}// end function
