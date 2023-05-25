#include <time.h>
#include <stdlib.h>

typedef struct {
    char* id;
    char* ime;
} Podaci;


    //Funkcija koja se poziva kako bi se prikazalo polje prilikom unosa brojeva u tablicu.
void prikaziSudoku(int sudoku[9][9]) {
    printf("\nSudoku:\n\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("------+-------+------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            if (sudoku[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("%d ", sudoku[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int rjesiSudoku(int sudoku[9][9]) {
    // Implementiraj logiku za rješavanje Sudoku zadatka
    // ...

    return 1;  // Vrati 1 ako je zadatak riješen, inače 0
}

void ocistiUnos() {
    while (getchar() != '\n');
}

void ispisiID(Podaci podaci) {
    printf("ID korisnika: %s\n", podaci.id);
}

void ispisiNajboljeVrijeme(Podaci podaci) {
    // Simulacija dobivanja najboljeg vremena iz datoteke
    int najboljeVrijeme = 150;  // Pretpostavljeno najbolje vrijeme

    printf("Najbolje vrijeme za korisnika %s: %d sekundi\n", podaci.id, najboljeVrijeme);
}