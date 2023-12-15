#include "defs.h"
#include <stdio.h>

int readPatients(char path[], Patients *patients, int max_size) {
    	FILE *file = fopen(path, "r");
    	if(file == NULL) {
        	printf("Nao foi possivel abrir o arquivo.\n");
        	return 0;
    	}

    	char line[100];
    	int i;
    	for(i = 0; i < max_size && fgets(line, sizeof(line), file); i++) {
        	sscanf(line, "%d;%49[^;];%d", &patients[i].ID, patients[i].name, &patients[i].phoneNumber);
    	}

    	fclose(file);
    	return i;
}

int readDiet(char path[], Diet *diet, int max_size) {
	FILE *file = fopen(path, "r");
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
		return 0;
	}

	char line[100];
	int i;
	for(i=0; i<max_size && fgets(line, sizeof(line), file); i++) {
		sscanf(line, "%d;%d-%d-%d;%49[^;];%49[^;];%d", &diet[i].ID, &diet[i].date.day, &diet[i].date.month, &diet[i].date.year, diet[i].meal, diet[i].food, &diet[i].calories);
	};

	fclose(file);
	return i;
};

int readMealPlan(char path, MealPlan *mealPlan, int max_size) {
	FILE *file = fopen(path, "r");
	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
		return 0;
	}
	char line[100];
	int i;
	for(i=0; i<max_size && fgets(line, sizeof(line), file); i++) {
		sscanf(line, "%d;%d-%d-%d;%49[^;];%d;%d", &mealPlan[i].ID, &mealPlan[i].date.day, &mealPlan[i].date.month, &mealPlan[i].date.year, mealPlan[i].meal, &mealPlan[i].minCal, &mealPlan[i].maxCal);
	};

	fclose(file);
	return i;
};
