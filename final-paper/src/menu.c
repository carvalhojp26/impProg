#include "utils.h"
#include "menu.h"
#include "logic.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file menu.c
 * @brief Funções de Interface do Menu.
 * 
 * Este ficheiro contém as definições das funções usadas para criar e gerir
 * a interface do menu do programa. Inclui funções para inicializar dados,
 * manipular opções de menu, e interações de utilizador, como a exibição do menu,
 * limpeza do ecra e espera de entrada do utilizador. Estas funções são projetadas
 * para facilitar a navegação e interação do utilizador com as diversas funcionalidades
 * do sistema.
 */


/**
 * @brief Inicializa um array de Diet com valores padrão.
 *
 * @param diets Array de estruturas Diet a ser inicializado.
 * @param size Tamanho do array a ser inicializado.
 */
void initializeDiets(Diet diets[], int size) {
        for (int i = 0; i < size; i++) {
                diets[i] = (Diet){.ID = -1, .date = {0}, .meal = "", .food = "", .calories = 0};
        }
}


/**
 * @brief Inicializa um array de Patients com valores padrão.
 *
 * @param patients Array de estruturas Patients a ser inicializado.
 * @param size Tamanho do array a ser inicializado.
 */
void initializePatients(Patients patients[], int size) {
        for (int i = 0; i < size; i++) {
                patients[i] = (Patients){.ID = -1, .name = "", .phoneNumber = 0};
        }
}

/**
 * @brief Inicializa um array de MealPlan com valores padrão.
 *
 * @param mealPlans Array de estruturas MealPlan a ser inicializado.
 * @param size Tamanho do array a ser inicializado.
 */
void initializeMealPlans(MealPlan mealPlans[], int size) {
        for (int i = 0; i < size; i++) {
                mealPlans[i] = (MealPlan){.ID = -1, .date = {0}, .meal = "", .minCal = 0, .maxCal = 0};
        }
}


/**
 * @brief Processa e exibe o número de pacientes que excederam um limite de calorias.
 *
 * @param diets Array de Diet contendo informações dietéticas.
 * @param size Tamanho do array de Diet.
 */
void handleExceededCalories(Diet diets[], int size) {
        int caloriesLimit;
        Period period;
        printf("Limite de calorias: \n");
        scanf("%d", &caloriesLimit);
        fillPeriod(&period);
        printf("Numero de pacientes que excederam a quantidade de calorias no periodo definido: %d\n", exceededCalories(diets, size, caloriesLimit, period));
}

/**
 * @brief Identifica e exibe refeições que estão fora do intervalo calórico estabelecido.
 *
 * @param diets Array de Diet contendo informações dietéticas.
 * @param mealPlans Array de MealPlan.
 * @param numDiets Número de elementos no array de Diet.
 */
void handleOutOfRange(Diet diets[], MealPlan mealPlans[], int numDiets) {
        Period period;
        fillPeriod(&period);
        int count = outOfRange(diets, mealPlans, period, numDiets);
        printf("Numero de refeicoes caloricas fora do intervalo: %d\n", count);
}


/**
 * @brief Gerencia e exibe um plano de refeições para um paciente específico.
 *
 * @param mealPlans Array de MealPlan.
 * @param size Tamanho do array de MealPlan.
 */
void handleMealPlan(MealPlan mealPlans[], int size) {
        int IDPatient;
        char mealName[50];
        Period period;
        printf("ID do paciente: \n");
        scanf("%d", &IDPatient);
        printf("Refeicao: \n");
        scanf("%s", mealName);
        fillPeriod(&period);
        listMealPlan(mealPlans, period, size, mealName, IDPatient);
        printf("Plano nutricional para a refeicao '%s' do paciente com ID %d listado.\n", mealName, IDPatient);
}

/**
 * @brief Calcula e exibe a média de calorias consumidas por um paciente.
 *
 * @param diets Array de Diet.
 * @param numDiets Número de elementos no array de Diet.
 */
void handleAverageCalories(Diet diets[], int numDiets) {
        int IDPatient;
        float avgCal;
        char mealName[50];
        Period period;
        printf("ID do paciente: \n");
        scanf("%d", &IDPatient);
        clearInputBuffer();
        printf("Refeicao: \n");
        fgets(mealName, sizeof(mealName), stdin);
        mealName[strcspn(mealName, "\n")] = 0;
        fillPeriod(&period);
        avgCal = averageCalories(diets, period, numDiets, mealName, IDPatient);
        printf("A média de calorias para '%s' do paciente com ID %d é: %.0f\n", mealName, IDPatient, avgCal);
}

/**
 * @brief Exibe uma tabela com informações consolidadas de dietas e planos de refeições.
 *
 * @param mealPlans Array de MealPlan.
 * @param diets Array de Diet.
 * @param patients Array de Patients.
 * @param size Tamanho dos arrays.
 */
void handlePrintTable(MealPlan mealPlans[], Diet diets[], Patients patients[], int size) {
        printTable(mealPlans, diets, patients, size);
}

/**
 * @brief Mostra o menu de opções e obtém a escolha do utilizador.
 * 
 * @return int A escolha do utilizador.
 */
int showMenuAndGetChoice() {
	int choice;
	
	clearScreen();

	printf("---------------MENU---------------\n");
	printf("1-Calorias Ultrapassadas\n");
	printf("2-Refeicao Calorica fora do intervalo\n");
	printf("3-Plano Nutricional\n");
	printf("4-Media Calorias Consumidas\n");
	printf("5-Tabela de Informacoes\n");
	printf("0-Sair\n");
	printf("-----------------------------------\n");
	
	while (1) {
		if (scanf("%d", &choice) == 1) {
			return choice;
		} else {
			printf("Entrada inválida. Por favor, insira um número.\n");
			clearInputBuffer();
		}
	}
}


/**
 * @brief Limpa o ecra do terminal. Verifica o sistema operativo para executar o comando correto.
 */
void clearScreen() {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}


/**
 * @brief Aguarda até que o utilizador pressione Enter.
 */
void waitForUserInput() {
	printf("\nPressione Enter para continuar...");
	// Limpa qualquer caractere residual no buffer de entrada
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
	// Aguarda a nova entrada do utilizador
	while ((c = getchar()) != '\n' && c != EOF) { }
}
