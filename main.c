#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* id;
    char* ime;
} Podaci;

int main() {
    // Unos podataka korisnika
    Podaci podaci;
    podaci.id = "ABC123";  // Generiraj ID korisnika
    printf("Unesite svoje ime: ");
    char ime[100];
    scanf("%s", ime);
    ocistiUnos();
    podaci.ime = malloc(strlen(ime) + 1);
    strcpy(podaci.ime, ime);

    // Spremanje podataka u datoteku
    FILE* datoteka = fopen("podaci.txt", "a");
    if (datoteka == NULL) {
        printf("Pogreška pri otvaranju datoteke.\n");
        return 1;
    }
    fprintf(datoteka, "%s %s\n", podaci.id, podaci.ime);
    fclose(datoteka);

    printf("Podaci su spremljeni u datoteku.\n");

    // Prikaz Sudoku ploče
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    prikaziSudoku(sudoku);

    // Rješavanje Sudoku zadatka
    int rjesenje = rjesiSudoku(sudoku);

    if (rjesenje) {
        printf("Sudoku je riješen:\n");
        prikaziSudoku(sudoku);
    }
    else {
        printf("Sudoku nije riješen.\n");
    }

    // Odbrojavanje vremena
    time_t pocetak = time(NULL);
    int trajanje = 0;
    while (trajanje < 300) {  // Ograničenje na 5 minuta (300 sekundi)
        time_t trenutno = time(NULL);
        trajanje = trenutno - pocetak;

        // Prikaz preostalog vremena
        int preostalo = 300 - trajanje;
        int minuta = preostalo / 60;
        int sekunda = preostalo % 60;
        printf("Preostalo vrijeme: %02d:%02d\n", minuta, sekunda);

        // Provjerite je li Sudoku riješen i prekinite odbrojavanje ako je
        if (rjesenje) {
            printf("Čestitamo, Sudoku je riješen!\n");
            break;
        }

        // Dodajte ovdje kod za ažuriranje sučelja s preostalim vremenom

        // Simulacija korisnikovog unosa brojeva u Sudoku
        printf("Unesite broj (1-9) i koordinate (redak, stupac) za unos (npr. 5 2 3): ");
        int broj, redak, stupac;
        scanf("%d %d %d", &broj, &redak, &stupac);
        ocistiUnos();
        sudoku[redak - 1][stupac - 1] = broj;
        prikaziSudoku(sudoku);
    }

    // Spremanje vremena rješavanja Sudoku zadatka
    datoteka = fopen("podaci.txt", "a");
    if (datoteka == NULL) {
        printf("Pogreška pri otvaranju datoteke.\n");
        return 1;
    }
    fprintf(datoteka, "%s %d\n", podaci.id, trajanje);
    fclose(datoteka);

    return 0;
}