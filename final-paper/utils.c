#include "defs.h"
#include <stdio.h>

Pacients *readPacients(char path[]) {
	FILE *file = fopen(path, "r");
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
		return NULL;
	}
	
	char line[100];
	Pacients pacients[10];

	for(int i=0; fgets(line, sizeof(line), FILE *path); i++) {
		sscanf(line, "%d;%49[^;];%d", &pacients[i].ID, pacients[i].name, &pacients[i].phone);
	};
	return pacients;	
}
