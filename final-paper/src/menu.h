#ifndef MENU_H
#define MENU_H

#include "types.h"
#include "utils.h"
#include "logic.h"

/**
 * @file menu.h
 * @brief Cabeçalho para as Funções de Interface do Menu
 * 
 * Este ficheiro de cabeçalho declara as funções utilizadas na interface do menu do programa.
 * Contém os protótipos das funções definidas em menu.c, abrangendo a inicialização de dados
 * e a gestão das opções do menu. Este ficheiro promove a modularidade e a manutenção do código,
 * facilitando a integração e reutilização das funções em diferentes partes do programa.
 */


void initializeDiets(Diet diets[], int size);
void initializePatients(Patients patients[], int size);
void initializeMealPlans(MealPlan mealPlans[], int size);
void handleExceededCalories(Diet diets[], int size);
void handleOutOfRange(Diet diets[], MealPlan mealPlans[], int numDiets);
void handleMealPlan(MealPlan mealPlans[], int size);
void handleAverageCalories(Diet diets[], int numDiets);
void handlePrintTable(MealPlan mealPlans[], Diet diets[], Patients patients[], int size);
void clearScreen();
void waitForUserInput();
int showMenuAndGetChoice();

#endif // MENU_H
