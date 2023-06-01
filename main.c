#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"header.h"

int main() {

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

	int izbor;
	Podaci podaci;

	printf("Dobrodošli u Sudoku program!\n");
	printf("Odaberite opciju:\n");
	printf("1. Novi korisnik\n");
	printf("2. Prijašnji korisnik\n");
	printf("Vaš odabir: ");
	scanf("%d", &izbor);
	ocistiUnos();

	if (izbor == 1) {
		unesiIme(podaci.ime);
		generirajID(podaci.id);
		ispisiID(podaci.id);
	}
	else if (izbor == 2) {
		printf("Unesite ID: ");
		scanf("%s", podaci.id);
		ocistiUnos();
	}
	else {
		printf("Pogrešan odabir. Izlaz iz programa.\n");
		return 0;
	}

	do {
		printf("\nOdaberite opciju:\n");
		printf("1. Prikazi Sudoku zadatak\n");
		printf("2. Automatski rjesi Sudoku\n");
		printf("3. Ručni unos brojeva\n");
		printf("4. Ispisi ID\n");
		printf("5. Ispisi najbolje vrijeme\n");
		printf("6. Obrisi sve podatke\n");
		printf("7. Izlaz iz programa\n");
		printf("Vaš odabir: ");
		scanf("%d", &izbor);
		ocistiUnos();

		switch (izbor) {
		case 1:
			prikaziSudoku(sudoku);
			break;
		case 2:
			rjesiSudoku(sudoku);
			printf("\nSudoku je riješen!\n");
			prikaziSudoku(sudoku);
			break;
		case 3:
			unesiBrojeve(sudoku);
			break;
		case 4:
			ispisiID(podaci.id);
			break;
		case 5:
			ispisiNajboljeVrijeme(podaci);
			break;
		case 6:
			//obrisiPodatke();
			printf("Svi podaci su obrisani.\n");
			break;
		case 7:
			printf("Hvala što ste koristili program. Doviđenja!\n");
			break;
		default:
			printf("Pogrešan odabir. Molimo odaberite ponovno.\n");
			break;
		}

	} while (izbor != 7);

	return 0;
}
