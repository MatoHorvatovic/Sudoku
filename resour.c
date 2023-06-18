#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_IME 20
#define MAX_ID 5

typedef struct {
	char ime[MAX_IME];
	char id[MAX_ID];
	time_t vrijeme_pocetka;
	time_t vrijeme_zavrsetka;
	int trajanje;
} Podaci;


void ocistiUnos() {
	while (getchar() != '\n');
}

void unesiIme(char ime[]) {
	printf("Unesite svoje ime: ");
	fgets(ime, MAX_IME, stdin);
	ime[strcspn(ime, "\n")] = '\0'; // Uklanja znak novog reda
}

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

void generirajID(char id[]) {
	srand(time(NULL));
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int charsetSize = sizeof(charset) - 1;
	for (int i = 0; i < MAX_ID - 1; i++) {
		id[i] = charset[rand() % charsetSize];
	}
	id[MAX_ID - 1] = '\0';
}

int rjesiSudoku(int sudoku[9][9]) {
	int praznoPolje[2];

	if (!pronadiPraznoPolje(sudoku, praznoPolje)) {
		// Svi elementi su popunjeni, zadatak je riješen
		return 1;
	}

	int redak = praznoPolje[0];
	int stupac = praznoPolje[1];

	for (int broj = 1; broj <= 9; broj++) {
		if (provjeriBroj(sudoku, redak, stupac, broj)) {
			sudoku[redak][stupac] = broj;

			if (rjesiSudoku(sudoku)) {
				return 1;
			}

			sudoku[redak][stupac] = 0;  // Poništi pokušaj
		}
	}

	return 0;  // Sudoku nije riješen
}

int provjeriBroj(int sudoku[9][9], int redak, int stupac, int broj) {
	// Provjera redaka i stupaca
	for (int i = 0; i < 9; i++) {
		if (sudoku[redak][i] == broj || sudoku[i][stupac] == broj) {
			return 0;
		}
	}

	// Provjera kvadranta 3x3
	int pocetakRedak = (redak / 3) * 3;
	int pocetakStupac = (stupac / 3) * 3;

	for (int i = pocetakRedak; i < pocetakRedak + 3; i++) {
		for (int j = pocetakStupac; j < pocetakStupac + 3; j++) {
			if (sudoku[i][j] == broj) {
				return 0;
			}
		}
	}

	return 1;  // Broj je ispravan
}

int pronadiPraznoPolje(int sudoku[9][9], int* praznoPolje) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				*(praznoPolje) = i;
				*(praznoPolje + 1) = j;
				return 1;
			}
		}
	}

	return 0;  // Nema praznih polja
}

void rucniUnosSudoku(int sudoku[9][9]) {

	int* praznoPolje = (int*)malloc(2 * sizeof(int));
	if (praznoPolje == NULL) {
		printf("Greška pri alokaciji memorije.");
		return 1;
	}
	time_t pocetnoVrijeme = time(NULL);
	time_t trenutnoVrijeme;

	while (pronadiPraznoPolje(sudoku, praznoPolje) == 1) {
		prikaziSudoku(sudoku);

		int redak, stupac, broj;

		printf("Unesite redak (1-9), stupac (1-9) i broj (1-9) odvojene razmakom: ");
		scanf("%d %d %d", &redak, &stupac, &broj);
		ocistiUnos();

		redak--;
		stupac--;

		if (redak < 0 || redak >= 9 || stupac < 0 || stupac >= 9 || broj < 1 || broj > 9) {
			printf("Nevažeći unos.\n");
			continue;
		}

		if (!provjeriBroj(sudoku, redak, stupac, broj)) {
			printf("Nevažeći broj.\n");
			continue;
		}

		sudoku[redak][stupac] = broj;
	}
	
	trenutnoVrijeme = time(NULL);
	printf(" \n\nTrebalo vam je %ld sekundi da popunite tablicu.", (trenutnoVrijeme - pocetnoVrijeme));
}

void spremiVrijeme(const Podaci podaci) {
	FILE* datoteka = fopen("podaci.txt", "a");
	if (datoteka == NULL) {
		printf("Pogreška pri otvaranju datoteke.\n");
		return;
	}
	fprintf(datoteka, "%s %d\n", podaci.id, podaci.trajanje);
	fclose(datoteka);
}

void ispisiID(const char id[]) {
	printf("ID korisnika: %s\n", id);
}

void ispisiNajboljeVrijeme(const Podaci podaci) {
	if (podaci.vrijeme_zavrsetka == 0) {
		printf("Nema zabilježenog najboljeg vremena.\n");
	}
	else {
		int vrijeme = (int)(podaci.vrijeme_zavrsetka - podaci.vrijeme_pocetka);
		int minuta = vrijeme / 60;
		int sekunda = vrijeme % 60;
		printf("Najbolje vrijeme: %d min %d sec\n", minuta, sekunda);
	}
}
