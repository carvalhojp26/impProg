#include "utils.c"
#include <stdio.h>

int main() {
    	const int MAX_PACIENTS = 10; 
    	Patients patients[MAX_PACIENTS];
    
   	readPatients("data/patients.txt", patients, MAX_PACIENTS);

    	int count = readPatients("data/patients.txt", patients, MAX_PACIENTS);

    	for (int i = 0; i < count; i++) {
        	printf("ID: %d, Nome: %s, Telemovel: %d\n", patients[i].ID, patients[i].name, patients[i].phoneNumber);
    	}

	const int MAX_DIETS = 10;
    	Diet diets[MAX_DIETS];

    	count = readDiet("data/diet.txt", diets, MAX_DIETS);

    	for (int i = 0; i < count; i++) {
        	printf("ID: %d, Data: %02d-%02d-%04d, Refeicao: %s, Comida: %s, Calorias: %d\n",
               		diets[i].ID, 
               		diets[i].date.day, diets[i].date.month, diets[i].date.year, 
               		diets[i].meal, diets[i].food, 
               		diets[i].calories);
    	}
    	return 0;
}

