#include "utils.h"
#include "logic.h"
#include "types.h"
#include "menu.h"

#include <string.h>
#include <stdio.h>
#define MAX_SIZE 100

/**
 * @file main.c
 * @brief Ponto de entrada principal do programa e interface de utilizador.
 *
 * Este ficheiro implementa a função 'main', que serve como o ponto de entrada principal do programa.
 * Aqui é apresentada a interface de utilizador no formato de um menu de texto, permitindo ao utilizador
 * interagir com o programa e aceder a diferentes funcionalidades relacionadas com a gestão de dietas e planos
 * alimentares. O programa oferece opções para calcular calorias excedidas, verificar refeições fora do intervalo
 * calórico, listar planos nutricionais, calcular a média de calorias consumidas e visualizar uma tabela de informações.
 *
 * As operações implementadas neste ficheiro fazem uso intensivo das funções definidas em 'utils.h' e 'logic.h',
 * e dos tipos de dados definidos em 'types.h'. Dados iniciais são carregados de ficheiros de texto, e o utilizador
 * pode interagir com estes dados através de várias opções de menu.
 *
 * @note Este ficheiro depende das definições em 'utils.h', 'logic.h' e 'types.h' para a sua funcionalidade.
 *
 * @warning A função 'main' assume que os ficheiros de dados necessários estão disponíveis e no formato correto.
 *          O programa pode não funcionar como esperado se estes ficheiros estiverem ausentes ou malformados.
 */

int main () {
	int choice;
	
	Diet diets[MAX_SIZE];
	Patients patients[MAX_SIZE];
	MealPlan mealPlans[MAX_SIZE];
	
	initializeDiets(diets, MAX_SIZE);
	initializePatients(patients, MAX_SIZE);
	initializeMealPlans(mealPlans, MAX_SIZE);
	
	int numPatients = readFile("data/patients.txt", patients, MAX_SIZE, PATIENTS);
	if (numPatients == -1) {
		printf("Erro ao ler dados dos pacientes.\n");
		return 1;
	}
	
	int numDiets = readFile("data/diet.txt", diets, MAX_SIZE, DIET);
	if (numDiets == -1) {
		printf("Erro ao ler dados da dieta.\n");
		return 1;
	}
	
	int numMealPlans = readFile("data/mealPlan.txt", mealPlans, MAX_SIZE, MEAL_PLAN);
	if (numMealPlans == -1) {
		printf("Erro ao ler dados do plano alimentar.\n");
		return 1;
	}
	
	do {
		choice = showMenuAndGetChoice();
		
		switch (choice) {
		    case 1:
			    handleExceededCalories(diets, MAX_SIZE);
			    waitForUserInput();
			    break;
		    case 2:
			    handleOutOfRange(diets, mealPlans, numDiets);
			    waitForUserInput();
			    break;
		
		    case 3:
			    handleMealPlan(mealPlans, MAX_SIZE);
			    waitForUserInput();
			    break;
		
		    case 4:
			    handleAverageCalories(diets, numDiets);
			    waitForUserInput();
			    break;
		
		    case 5:
			    handlePrintTable(mealPlans, diets, patients, MAX_SIZE);
			    waitForUserInput();
			    break;
		
		    case 0:
			    return 0;
		
		    default:
			    printf("Escolha indisponivel\n");
		            break;
		}
	} while (choice != 0);
	
	return 0;
}
