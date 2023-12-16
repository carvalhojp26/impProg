#include "utils.h"
#include <stdio.h>

int readFile(char *path, void *data, int max_size, FileType fileType) {
        FILE *file = fopen(path, "r");
        if (file == NULL) {
<<<<<<< HEAD
                printf("Nao foi possivel abrir o ficheiro.\n");
=======
                printf("Nao foi possivel abrir o arquivo.\n");
>>>>>>> parent of e67a3ca (Indenting files)
                return 0;
        }

        char line[100];
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
<<<<<<< HEAD
                                printf("Tipo de ficheiro nao suportado.\n");
=======
                                printf("Impossivel abrir este arquivo.");
>>>>>>> parent of e67a3ca (Indenting files)
                                break;
                }
        }
        fclose(file);
        return i;
}

