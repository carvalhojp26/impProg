#include "utils.h"
#include <stdio.h>

int readFile(char *path, void *data, int max_size, FileType fileType) {
        FILE *file = fopen(path, "r");
        if (file == NULL) {
                printf("Nao foi possivel abrir o ficheiro.\n");
                return 0;
        }

        char line[500];
        int i;

        for (i=0; i<max_size && fgets(line, sizeof(line), file); i++) {

                switch (fileType) {

                        case PATIENTS:
				Patients *patients = (Patients *)data;
                                sscanf(line, "%d;%49[^;];%d", &patients[i].ID, patients[i].name, &patients[i].phoneNumber);
                                break;

                        case DIET:
				Diet *diet = (Diet *)data;
                                sscanf(line, "%d;%d-%d-%d;%49[^;];%49[^;];%d", &diet[i].ID, &diet[i].date.day, &diet[i].date.month, &diet[i].date.year, diet[i].meal, diet[i].food, &diet[i].calories);
                                break;

                        case MEAL_PLAN:
				MealPlan *mealPlan = (MealPlan *)data;
                                sscanf(line, "%d;%d-%d-%d;%49[^;];%d;%d", &mealPlan[i].ID, &mealPlan[i].date.day, &mealPlan[i].date.month, &mealPlan[i].date.year, mealPlan[i].meal, &mealPlan[i].minCal, &mealPlan[i].maxCal);
                                break;

                        default:
                                printf("Tipo de ficheiro nao suportado.\n");
                                break;
                }
        }
        fclose(file);
        return i;
}

int dateInPeriod(Date date, Period period) {
    	if (date.year < period.begin.year || date.year > period.end.year) {
        	return 0;
    	}

    	if (date.year == period.begin.year) {
        	if (date.month < period.begin.month || (date.month == period.begin.month && date.day < period.begin.day)) {
           		return 0;
        	}
    	}

    	if (date.year == period.end.year) {
        	if (date.month > period.end.month || (date.month == period.end.month && date.day > period.end.day)) {
            		return 0;
        	}
    	}

    	return 1;
}

int exceededCalories(Diet *diet, int max_size, int calories, Period period) {
    	int counter = 0, i, j;
	IDCalories idCalories[100] = {[0 ... 99] = {.ID = -1, .calories = 0}}; // Inicializo todos a -1 para verificar quais posicoes estao vazias

    	for (i=0; i<max_size; i++) { // Itera por todos os itens do diet[] 
        	if (dateInPeriod(diet[i].date, period)) {
        		for (j=0; (j<100) && (idCalories[j].ID != -1); j++) { // Itera por idCalories e vejo se a pessoa que consumiu aquelas calorias ja esta registada no array IDCalories
				if (idCalories[j].ID == diet[i].ID) {
					idCalories[j].calories += diet[i].calories;
					break;
				}
			}
			if (j==100) {
				printf("Limite de pacientes atingidos.\n");
				return -1;
			}
			// Paciente nao existia na lista, portando vou adicionar
			if (idCalories[j].ID == -1) {
				idCalories[j].ID = diet[i].ID;
				idCalories[j].calories = diet[i].calories;
			}
		}
    	}

	// Com o array ja populado com ID e Calories, posso fazer a verificacao
	for (i=0; (i<100) && (idCalories[i].ID != -1); i++) {
		if (idCalories[i].calories > calories) {
			counter++;
		}
	}
	return counter;
}

