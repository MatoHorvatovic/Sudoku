#pragma once

typedef struct {
    char* id;
    char* ime;
} Podaci;


void prikaziSudoku(int sudoku[9][9]);
int rjesiSudoku(int sudoku[9][9]);
void ocistiUnos();
void ispisiID(Podaci podaci);
void ispisiNajboljeVrijeme(Podaci podaci);