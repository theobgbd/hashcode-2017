#include <stdio.h>
#include <stdlib.h>
#include "reading_file.h"

struct general
{
   int nbVideo;
   int nbEndpoint;
   int nbRequest;
   int nbCache;
   int capacityCache;
};
typedef struct general;



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

	int endpoint[1000][1000];

	int request[1000][1000][1000];

	int cache[1000][1000];


	
	return current;
}


int main (int argc, char *argv[])
{
}
