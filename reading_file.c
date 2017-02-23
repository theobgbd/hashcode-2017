#include <stdio.h>
#include <stdlib.h>
#include "reading_file.h"

struct myStruct
{
   char string[50];
   int jeSaisPas;
   char letter;
};
typedef struct myStruct myStruct;


typedef enum { False, True } Boolean;


int ReadingFile(char * file_name)
{
	// check si le fichier s'ouvre correctement
	FILE *file = fopen(file_name, "r");
	if(file == NULL)
	{
		printf("ERREUR - le fichier ne s'ouvre pas correctement\n\n");
	}

	int current = fgetc(file);
	
	return current;
}


int main (int argc, char *argv[])
{
}
