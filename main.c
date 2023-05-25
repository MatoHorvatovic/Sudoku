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

    // Odabir rješavanja Sudoku zadatka
    int rjesavanje;
    printf("Odaberite način rješavanja Sudoku zadatka:\n");
    printf("1. Ručni unos brojeva\n");
    printf("2. Automatsko rješavanje\n");
    printf("3. Ispis ID-a korisnika\n");
    printf("4. Ispis najboljeg vremena\n");
    printf("Odabir: ");
    scanf("%d", &rjesavanje);
    ocistiUnos();

    // Izvršavanje odabranog koraka
    switch (rjesavanje) {
    case 1:
        // Ručni unos brojeva
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("Unesite broj za polje (%d, %d): ", i + 1, j + 1);
                scanf("%d", &sudoku[i][j]);
                ocistiUnos();
            }
        }

        printf("Sudoku zadatak je unesen:\n");
        prikaziSudoku(sudoku);
        break;

    case 2:
        // Automatsko rješavanje
        if (rjesiSudoku(sudoku)) {
            printf("Sudoku je riješen:\n");
            prikaziSudoku(sudoku);
        }
        else {
            printf("Sudoku nije riješen.\n");
        }
        break;

    case 3:
        // Ispis ID-a korisnika
        ispisiID(podaci);
        break;

    case 4:
        // Ispis najboljeg vremena
        ispisiNajboljeVrijeme(podaci);
        break;

    default:
        printf("Pogrešan odabir. Program će se završiti.\n");
        return 1;
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
        printf("Preostalo vrijeme: %02d:%02d\r", minuta, sekunda);
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
