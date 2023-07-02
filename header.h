#pragma once
#include<time.h>

#define MAX_ID 5

typedef struct {
	char id[MAX_ID];
	time_t vrijeme_pocetka;
	time_t vrijeme_zavrsetka;
	int trajanje;
} Podaci;

void ocistiUnos();
void generirajID(char id[]);
int provjeriID(char id[]);
void prikaziSudoku(int sudoku[9][9]);
int rjesiSudoku(int sudoku[9][9]);
void rucniUnosSudoku(int sudoku[9][9]);
void spremiVrijeme(const Podaci podaci);
void ispisiID(const char id[]);