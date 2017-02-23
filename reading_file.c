#include <stdio.h>
#include <stdlib.h>

struct myStruct
{
   char string[50];
   int jeSaisPas;
   char letter;
};
typedef struct myStruct myStruct;


myStruct *ReadingFile(char * file_name)
{
	int current = 0;
	// check si le fichier s'ouvre correctement
	FILE *file = fopen(file_name, "r");
	if(file == NULL)
	{
		printf("ERREUR - le fichier ne s'ouvre pas correctement\n\n");
	}

	while(EOF) // lit char l'un après l'autre tant qu'on n'est pas à la fin du fichier
	{
		current = fgetc(file);
	}	

}
