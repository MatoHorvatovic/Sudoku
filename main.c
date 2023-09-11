#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"header.h"

#define MAX_ID 5



int main() {
	char ime[20], ID[MAX_ID];
	int izbor;
	int sudoku[9][9];
	Podaci* podaci = calloc(1, sizeof(Podaci));
	printf("Dobrodosli u Sudoku program!\n");
	printf("Odaberite opciju:\n");
	printf("1. Novi korisnik\n");
	printf("2. Prijasnji korisnik\n");
	printf("Vaš odabir: ");
	scanf("%d", &izbor);
	ocistiUnos();
	if (izbor == 1) {
		printf("Unesite ime: ");
		scanf("%s",ime);

		// Generiranje ID-a
		generirajID(ID);

		// Pohrana imena i ID-a u datoteku
		FILE* datoteka;
		datoteka = fopen("podaci.txt", "a");
		if (datoteka == NULL) {
			printf("Greska pri otvaranju datoteke!\n");
			return;
		}

		fprintf(datoteka, "%s,%s\n", ime, ID);

		fclose(datoteka);

		printf("Podaci su pohranjeni u datoteku.\n");

	}
	else if (izbor == 2) {
		printf("Unesite ID: ");
		scanf("%s", ID);
		ocistiUnos();

		// Provjera ID-a u datoteci
		int pronaden = provjeriID(ID);
		if (pronaden) {
			printf("ID je pronaden u datoteci.\n");
		}
		else {
			printf("ID nije pronaden u datoteci.\n");
			return 0;
		}
	}
	else {
		printf("Pogresan odabir. Izlaz iz programa.\n");
		return 0;
	}
	printf("Odaberite razinu težine\n");
	printf("1. lagano\n");
	printf("2. srednje\n");
	printf("3. teško\n");
	scanf("%d", &izbor);
	ocistiUnos();
	if (izbor == 1) {
		ucitajSudokuIzDatoteke("lagano.txt", sudoku);
	}
	else if (izbor == 2) {
		ucitajSudokuIzDatoteke("srednje.txt", sudoku);
	}
	if (izbor == 3) {
		ucitajSudokuIzDatoteke("tesko.txt", sudoku);
	}
	prikaziSudoku(sudoku);

	do {
		printf("\nOdaberite opciju:\n");
		printf("1. Prikazi Sudoku zadatak\n");
		printf("2. Automatski rjesi Sudoku\n");
		printf("3. Rucni unos brojeva\n");
		printf("4. Ispisi ID\n");
		printf("5. Ispisi sve korisnike sortirane po vremenu\n");
		printf("6. Izlaz iz programa\n");
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
			rucniUnosSudoku(sudoku);
			spremiVrijeme(*podaci);
			break;
		case 4:
			ispisiID(podaci->id);
			break;
		case 5:
			printf("Korisnici sortirani po vremenu:\n");
			int brojKorisnika = ucitajKorisnike(podaci);
			if (brojKorisnika > 0) {
				bubbleSort(podaci, brojKorisnika);
				for (int i = 0; i < brojKorisnika; i++) {
					printf("ID: %s, Trajanje: %d sekundi\n", podaci[i].id, podaci[i].trajanje);
				}
			}
			else {
				printf("Nema korisnika za ispis.\n");
			}
			break;
		case 6:
			printf("Hvala sto ste koristili program. Doviđenja!\n");
			exit(0);
		default:
			printf("Pogrešan odabir. Molimo odaberite ponovno.\n");
			break;
		}

	} while (izbor != 6);

	return 0;
}
