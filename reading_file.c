#include <stdio.h>
#include <stdlib.h>
#include "reading_file.h"
#include <string.h>

struct general
{
   char nbVideo[50];
   char nbEndpoint[50];
   char nbRequest[50];
   char nbCache[50];
   char capacityCache[50];
};
typedef struct general general;



typedef enum { False, True } Boolean;


int ReadingFile()
{
	general param;
	int check = 0;
	int indexStore = 0;
	int current = 0;
	// check si le fichier s'ouvre correctement
	FILE *file = fopen("kittens.in", "r");
	if(file == NULL)
	{
		printf("ERREUR - le fichier ne s'ouvre pas correctement\n\n");
	}

	while((current = fgetc(file)) != '\n') // première ligne
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
	}

	char *sizeVideo[atoi(param.nbVideo)]; // contient la deuxième ligne
	int indexVideo = 0;
	int indexChar = 0;
	char nb[5];


	while((current = fgetc(file)) != '\n')
	{
		if(current == ' ')
		{
			sizeVideo[indexVideo] = nb;
			indexVideo = indexVideo + 1;

			printf("%s\n", nb);
			indexChar = 0;
			for (int x = 0; x < 5; x++)
			{
				nb[x] = ' ';
			}
			continue;
		}
		if(indexChar == 3)
		{
			continue;
		}
		nb[indexChar] = current;
		indexChar = indexChar  + 1;
	}

	char Ld[4];
	char K[strlen(param.nbCache)];
	int indexLd = 0;
	int indexK = 0;


	while((current = fgetc(file)) != ' ')
	{
		Ld[indexLd] = current;
		indexLd = indexLd + 1;
	}

	while((current = fgetc(file)) != '\n')
	{
		K[indexK] = current;
		indexK = indexK + 1;
	}

	printf("LD : %s\nK : %s\n", Ld, K);

	int count = 0;
	char* IDcache[strlen(K)];
	char* Latency[strlen(K)]; 
	char word[500];
	int indexCo = 0;
	int indexWord = 0;
	int indexLatence = 0;
	int checkCo = 0;

	while(count < strlen(K))
	{
		current = fgetc(file);
		if(current == ' ')
		{
			indexLatence = 0;
			checkCo = 1;
			Latency[indexCo] = word;
			for(int x = 0; x<500; x++)
			{
				word[x] = ' ';
			}
		}
		if(current == '\n')
		{
			indexCo = indexCo + 1;
			IDcache[indexCo] = word;
			for(int x = 0; x<500; x++)
			{
				word[x] = ' ';
			}
			indexWord = 0;
			count = count + 1;
		}
		if(checkCo == 0)
		{
			word[indexWord] = current;
			indexWord = indexWord + 1;
		}
		if(checkCo == 1)
		{
			word[indexWord] = current;
			indexWord = indexWord + 1;
		}
	}


	int **endpoints;
	endpoints=(int **) malloc(10*sizeof(int *));
	for(int i=0;i<10;i++)
    		endpoints[i]=(int *) malloc(20*sizeof(int));


	int cache[1000][1000];

	printf("PARAM %s \n", param.nbVideo);
	printf("PARAM %s \n", param.nbEndpoint);
	printf("PARAM %s \n", param.nbRequest);
	printf("PARAM %s \n", param.nbCache);
	printf("PARAM %s \n", param.capacityCache);
	
	return current;
}


int main (int argc, char *argv[])
{
	ReadingFile();
	return 0;
}
