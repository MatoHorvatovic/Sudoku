#pragma once
#include<time.h>
#define MAX_IME 50
#define MAX_ID 10

typedef struct {
	char ime[MAX_IME];
	char id[MAX_ID];
	time_t vrijeme_pocetka;
	time_t vrijeme_zavrsetka;
	int trajanje;
} Podaci;

void ocistiUnos();
void unesiIme(char ime[]);
void prikaziSudoku(int sudoku[9][9]);
void generirajID(char id[]);
int rjesiSudoku(int sudoku[9][9]);
void unesiBrojeve(int sudoku[9][9]);
void spremiVrijeme(const Podaci podaci);
void ispisiID(const char id[]);
void ispisiNajboljeVrijeme(const Podaci podaci);