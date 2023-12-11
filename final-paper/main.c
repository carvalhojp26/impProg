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

    return 0;
}

