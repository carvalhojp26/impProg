#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @file utils.c
 * @brief Implementação das funções de utilidade para o programa.
 *
 * Este ficheiro contém as implementações das funções de utilidade declaradas em 'utils.h'.
 * As funções aqui presentes oferecem uma variedade de operações auxiliares, incluindo leitura de dados
 * de ficheiros, manipulação e impressão de datas e períodos, limpeza do buffer de entrada e ordenação de arrays.
 * Estas funções são utilizadas em várias partes do programa para realizar tarefas comuns, como processamento
 * de dados de entrada e apresentação de informações de forma legível.
 *
 * As funções implementadas neste ficheiro incluem:
 * - Leitura e interpretação de dados de ficheiros com formatos específicos.
 * - Verificação se uma data está dentro de um período especificado.
 * - Impressão formatada de datas e períodos.
 * - Limpeza do buffer de entrada para evitar leituras indesejadas de dados.
 * - Ordenação de arrays de inteiros em ordem decrescente.
 *
 * @note As funções neste ficheiro são dependentes das estruturas de dados e tipos enumerados definidos em 'types.h'
 *       e declarados em 'utils.h'.
 */

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
                                sscanf(line, "%d; %49[^;];%d", &patients[i].ID, patients[i].name, &patients[i].phoneNumber);
                                break;

                        case DIET:
                                Diet *diet = (Diet *)data;
                                sscanf(line, "%d;%d-%d-%d; %49[^;];%49[^;];%d", &diet[i].ID, &diet[i].date.day, &diet[i].date.month, &diet[i].date.year, diet[i].meal, diet[i].food, &diet[i].calories);
                                break;

                        case MEAL_PLAN:
                                MealPlan *mealPlan = (MealPlan *)data;
                                sscanf(line, "%d;%d-%d-%d; %49[^;]; %d Cal, %d Cal", &mealPlan[i].ID, &mealPlan[i].date.day, &mealPlan[i].date.month, &mealPlan[i].date.year, mealPlan[i].meal, &mealPlan[i].minCal, &mealPlan[i].maxCal);
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

        //antes
        if (date.year < period.begin.year ||
                (date.year == period.begin.year && date.month < period.begin.month) ||
                (date.year == period.begin.year && date.month == period.begin.month && date.day < period.begin.day)) {
                return -1;
        }

        //depois
        if (date.year > period.end.year ||
                (date.year == period.end.year && date.month > period.end.month) ||
                (date.year == period.end.year && date.month == period.end.month && date.day > period.end.day)) {
                return 2;
        }

        return 1;
}

void printDate(Date date) {
	printf("data: %02d-%02d-%04d ", date.day, date.month, date.year);
}

void printPeriod(Period period) {
	printf("Início: ");
	printDate(period.begin);
	printf(", Fim: ");
	printDate(period.end);
	printf("\n");
}


void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

void sortDescending(int ids[], int numberEl) {
        int i, j, temp;

        for (i = 0; i < numberEl - 1; i++) { // Itera do primeiro valor ao penultimo
                for (j = i + 1; j < numberEl; j++) { // Itera do segundo valor ao ultimo
                        if (ids[i] < ids[j]) { // Verifica se o primeiro valor e menor que o segundo
                                temp = ids[i]; // Casos seja os troca de lugar, durante a troca utiliza temp, uma variavel temporaria para armazenar o valor do elemento do primeiro loop
                                ids[i] = ids[j];
                                ids[j] = temp;
                        }
                }
        }
}

void fillPeriod(Period *period) {
	int isValidDate = 1;
	do {
		if(!isValidDate){
		       printf("Data invalida\n");
		       clearInputBuffer();
		}
		printf("Escreva a data de inicio do periodo (dd-mm-aaaa): \n");
	        scanf("%d-%d-%d", &period->begin.day, &period->begin.month, &period->begin.year);
	        isValidDate = (period->begin.year >= 1) &&
	                      (period->begin.month >= 1 && period->begin.month <= 12) &&
	                      (period->begin.day >= 1 && period->begin.day <= 31) && 
	                      !((period->begin.month == 2 && period->begin.day > 29) ||
	                        (period->begin.month == 2 && period->begin.day == 29 &&
	                         !((period->begin.year % 4 == 0 && period->begin.year % 100 != 0) || (period->begin.year % 400 == 0))));
	} while (!isValidDate);

	isValidDate = 1;	
	do {
		if(!isValidDate){
		       printf("Data invalida\n");
		       clearInputBuffer();
		}
		clearInputBuffer();
	        printf("Escreva a data de fim do periodo (dd-mm-aaaa): \n");
	        scanf("%d-%d-%d", &period->end.day, &period->end.month, &period->end.year);
	        isValidDate = (period->end.year >= 1) &&
	                      (period->end.month >= 1 && period->end.month <= 12) &&
	                      (period->end.day >= 1 && period->end.day <= 31) &&
	                      !((period->end.month == 2 && period->end.day > 29) ||
	                        (period->end.month == 2 && period->end.day == 29 &&
	                         !((period->end.year % 4 == 0 && period->end.year % 100 != 0) || (period->end.year % 400 == 0))));
	} while (!isValidDate);
}
