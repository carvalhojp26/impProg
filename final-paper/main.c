#include "utils.h"
#include <stdio.h>

int main() {
    const int MAX_SIZE = 10;

    Patients patients[MAX_SIZE];
    int numPatients = readFile("data/patients.txt", patients, MAX_SIZE, PATIENTS);
    for (int i = 0; i < numPatients; i++) {
        printf("ID: %d, Nome: %s, Telemovel: %d\n", patients[i].ID, patients[i].name, patients[i].phoneNumber);
    }

    Diet diets[MAX_SIZE];
    int numDiets = readFile("data/diet.txt", diets, MAX_SIZE, DIET);
    for (int i = 0; i < numDiets; i++) {
        printf("ID: %d, Date: %02d-%02d-%04d, Meal: %s, Food: %s, Calories: %d\n",
                diets[i].ID,
                diets[i].date.day, diets[i].date.month, diets[i].date.year,
                diets[i].meal, diets[i].food,
                diets[i].calories);
    }

    MealPlan mealPlans[MAX_SIZE];
    int numMealPlans = readFile("data/mealPlan.txt", mealPlans, MAX_SIZE, MEAL_PLAN);
    for (int i = 0; i < numMealPlans; i++) {
        printf("ID: %d, Date: %02d-%02d-%04d, Meal: %s, MinCal: %d, MaxCal: %d\n",
                mealPlans[i].ID,
                mealPlans[i].date.day, mealPlans[i].date.month, mealPlans[i].date.year,
                mealPlans[i].meal, mealPlans[i].minCal, mealPlans[i].maxCal);
    }

    return 0;
}

