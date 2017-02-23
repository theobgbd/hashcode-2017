#include <stdio.h>
#include <stdlib.h>
#include "reading_file.h"

struct general
{
   char nbVideo[50];
   char nbEndpoint[50];
   char nbRequest[50];
   char nbCache[50];
   char capacityCache[50];
};
typedef struct general;



typedef enum { False, True } Boolean;


int ReadingFile(char * file_name)
{
	general param;
	int check = 0;
	int indexStore = 0;
	current = fgetc(file);
	// check si le fichier s'ouvre correctement
	FILE *file = fopen(file_name, "r");
	if(file == NULL)
	{
		printf("ERREUR - le fichier ne s'ouvre pas correctement\n\n");
	}

	while(current != '\n')
	{
		if(current == ' ')
		{
			check = check + 1;
			indexStore = 0;
			continue;
		}
		if(check == 0)
		{
			param.nbVideo[indexStore] = current; 
			indexStore = indexStore + 1;
		}
		if(check == 1)
		{
			param.nbEndpoint[indexStore] = current; 
			indexStore = indexStore + 1;
		}
		if(check == 2)
		{
			param.nbRequest[indexStore] = current; 
			indexStore = indexStore + 1;
		}
		if(check == 3)
		{
			param.nbCache[indexStore] = current; 
			indexStore = indexStore + 1;
		}
		if(check == 4)
		{
			param.capacityCache[indexStore] = current; 
			indexStore = indexStore + 1;
		}
		current = fgetc(file);
		
	}

	int current = fgetc(file);

	int endpoint[1000][1000];

	int request[1000][1000][1000];

	int cache[1000][1000];


	
	return current;
}


int main (int argc, char *argv[])
{
	
}
