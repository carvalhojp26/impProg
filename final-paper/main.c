#include "utils.c"
#include <stdio.h>

int main() {
    	const int MAX_PACIENTS = 10; // Adjust as needed
    	Pacients pacients[MAX_PACIENTS];
    
   	readPacients("data/pacients.txt", pacients, MAX_PACIENTS);

    	int count = readPacients("data/pacients.txt", pacients, MAX_PACIENTS);

    	// Print only the valid records
    	for (int i = 0; i < count; i++) {
        	printf("ID: %d, Nome: %s, Telemovel: %d\n", pacients[i].ID, pacients[i].name, pacients[i].phoneNumber);
    	}

	const int MAX_DIETS = 10;  // Adjust as needed
    	Diet diets[MAX_DIETS];

    	count = readDiet("data/diet.txt", diets, MAX_DIETS);

    	// Print the Diet information
    	for (int i = 0; i < count; i++) {
        	printf("ID: %d, Date: %02d-%02d-%04d, Meal: %s, Food: %s, Calories: %d\n",
               		diets[i].ID, 
               		diets[i].date.day, diets[i].date.month, diets[i].date.year, 
               		diets[i].meal, diets[i].food, 
               		diets[i].calories);
    	}
    	return 0;
}

