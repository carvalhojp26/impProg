#include "logic.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

/**
 * @file logic.c
 * @brief Implementação das funções de lógica principal do programa.
 *
 * Este ficheiro contém as definições das funções principais que lidam com a lógica
 * do programa. Inclui funções para calcular calorias excedidas, verificar refeições
 * fora do intervalo de calorias estipulado, listar planos de refeições, calcular a média
 * de calorias consumidas e imprimir tabelas com informações relevantes.
 *
 * As funções neste ficheiro operam sobre as estruturas de dados definidas em 'logic.h'
 * e 'utils.h', sendo essenciais para as operações principais do programa, como a gestão
 * de dietas e planos alimentares.
 *
 * @note Este ficheiro faz uso extensivo das estruturas e funções definidas em 'utils.h'
 *       para operações de data e manipulação de dados.
 *
 * @warning Algumas funções assumem que os dados de entrada são válidos e não realizam
 *          verificações extensivas de erro. A validação adequada dos dados de entrada
 *          é responsabilidade das funções chamadoras.
 */

int exceededCalories(Diet *diet, int max_size, int calories, Period period) {
    	int counter = 0, i, j;
	IDCalories idCalories[100] = {[0 ... 99] = {.ID = -1, .calories = 0}}; // Inicializo todos a -1 para verificar quais posicoes estao vazias

    	for (i=0; i<max_size; i++) { // Itera por todos os itens do diet[]
        	if (dateInPeriod(diet[i].date, period) == 1) {
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

int outOfRange(Diet *diet, MealPlan *mealPlan, Period period, int max_size) {
    	int count = 0;
	int outOfRangeIDs[100];
	for (int k = 0; k < 100; k++) outOfRangeIDs[k] = -1;
	int flag=0;

	// Itera por todos as datas do array e verifica se estao dentro do periodo
    	for (int i = 0; i < max_size; i++) {
		flag=0;
        	if (dateInPeriod(diet[i].date, period) == 1) {
            		for (int j = 0; j < max_size; j++) {
				// Itera os valores obtidos para comparar se os IDs em ambos arrays sao iguais
                		if (diet[i].ID == mealPlan[j].ID) { 
					// Verifica se os valores estao no intervalo definido em MealPlan
                   			if (diet[i].calories < mealPlan[j].minCal || diet[i].calories > mealPlan[j].maxCal) {
						for (int l=0; l<100; l++) {
							if (diet[i].ID == outOfRangeIDs[l]) {
								flag=1;
							}
						}
						if (flag == 0) {
                        				outOfRangeIDs[count++] = diet[i].ID;
                        				break;
						}
                    			}
                		}
            		}
        	}
    	}
	sortDescending(outOfRangeIDs, count);

	printf("IDs fora do intervalo de calorias no período definido:\n");
    	for (int i = 0; i < count; i++) {
        	printf("%d\n", outOfRangeIDs[i]);
    	}

    	return count;
}

int listMealPlan(MealPlan *mealPlan, Period period, int max_size, char *mealType, int IDNum) {
	int i, count=0;
	
	printf("Lista das refeicoes: %s\n", mealType);
	printf("Periodo: %02d-%02d-%04d - %02d-%02d-%04d\n", period.begin.day, period.begin.month, period.begin.year, period.end.day, period.end.month, period.end.year);

	for (i=0; i<max_size; i++) {
		if (dateInPeriod(mealPlan[i].date, period) == 1 && (mealPlan[i].ID == IDNum) && !(strcmp(mealPlan[i].meal, mealType))) {
			printf("Data: %02d-%02d-%04d, Calorias Minimas: %d, Calorias Maximas: %d\n", mealPlan[i].date.day, mealPlan[i].date.month, mealPlan[i].date.year, mealPlan[i].minCal, mealPlan[i].maxCal);
			count++;
		}
	}

	return count;
}

float averageCalories(Diet *diet, Period period, int max_size, char *mealType, int IDNum) {
        int i, sum=0, count=0;
        float averageCal = 0.0;

        for (i=0; i<max_size; i++) {
                if (dateInPeriod(diet[i].date, period) == 1 && (diet[i].ID == IDNum) && !strcmp(diet[i].meal, mealType)) {
                        sum += diet[i].calories;
                        count++;
                }
        }
        if (count != 0) {
                averageCal = (float)sum/count;
        }
        return averageCal;
}

void printTable(MealPlan *mealPlans, Diet *diets, Patients *patients, int max_size) {
	InfoTable infoTable[100] = {[0 ... 99] = {.patient = {.ID = -1, .name = "", .phoneNumber = 0}, .minCal = 0, .maxCal = 0, .calories = 0}}; // Inicializo todos a -1 para verificar quais posicoes estao vazias;
								      
	//Criando o array q vai ser usado para preencher a tabela. Comeco por iterar pelo array de mealPlans para buscar o tipo de refeicao associado a um utilizador e tambem o max e min de calorias totais para aquela refeicao
	for (int plan = 0; plan<max_size && mealPlans[plan].ID != -1; plan++) {

		for(int line = 0;line < 100;line++){
			// Se percorrer ate achar um lugar vazio, tenho que adicionar uma nova entrada no infoTable
			if (infoTable[line].patient.ID == -1) {
				//Nova entrada na tabela
				infoTable[line].patient.ID = mealPlans[plan].ID;
				strcpy(infoTable[line].meal, mealPlans[plan].meal);
				infoTable[line].period.begin = mealPlans[plan].date;
				infoTable[line].period.end = mealPlans[plan].date;
				infoTable[line].minCal = mealPlans[plan].minCal;
				infoTable[line].maxCal = mealPlans[plan].maxCal;	
				break;
			} else if (infoTable[line].patient.ID == mealPlans[plan].ID && !(strcmp(infoTable[line].meal, mealPlans[plan].meal))) {
				switch (dateInPeriod(mealPlans[plan].date, infoTable[line].period)) {
					//Data antes, logo passa ser o inicio do periodo
					case -1:
						infoTable[line].period.begin = mealPlans[plan].date;
						break;
					//Data depois do periodo, logo passa a ser o fim do periodo
					case 2:
						infoTable[line].period.end = mealPlans[plan].date;
						break;

					default:
						break;

				}

				printf("Vou alterar uma entrada existente\n");
				infoTable[line].minCal += mealPlans[plan].minCal;
				infoTable[line].maxCal += mealPlans[plan].maxCal;
				break;
			}
		}
	}

	for (int line=0; (line < 100) && (infoTable[line].patient.ID != -1); line++) {
		for (int patient=0; patient < max_size; patient++) {
			if (infoTable[line].patient.ID == patients[patient].ID) {
				strcpy(infoTable[line].patient.name, patients[patient].name);
				break;
			}
		}
	}

	for (int line = 0; (line < 100) && (infoTable[line].patient.ID != -1); line++) {
		for (int diet=0; diet<max_size && diets[diet].ID != -1; diet++) {
			if ((infoTable[line].patient.ID == diets[diet].ID) && (dateInPeriod(diets[diet].date, infoTable[line].period) == 1) && (!strcmp(infoTable[line].meal, diets[diet].meal))) {
				infoTable[line].calories += diets[diet].calories;
				break;
			}
		}
	}

    	printf("+------+----------------+----------------+------------+------------+----------+----------+----------+\n");
    	printf("| NP   | Paciente       | Tipo Refeição  | Início     | Fim        | Mínimo   | Máximo   | Consumo  |\n");
    	printf("+------+----------------+----------------+------------+------------+----------+----------+----------+\n");
	
	for (int line = 0; line<100 && infoTable[line].patient.ID != -1; line++) {
		printf("| %04d | %-14s | %-14s | %02d-%02d-%04d | %02d-%02d-%04d | %8d | %8d | %8d |\n", infoTable[line].patient.ID, infoTable[line].patient.name, infoTable[line].meal, infoTable[line].period.begin.day, infoTable[line].period.begin.month, infoTable[line].period.begin.year, infoTable[line].period.end.day, infoTable[line].period.end.month, infoTable[line].period.end.year, infoTable[line].minCal, infoTable[line].maxCal, infoTable[line].calories);

	}
	
    	printf("+------+----------------+----------------+------------+------------+----------+----------+----------+\n");
}

