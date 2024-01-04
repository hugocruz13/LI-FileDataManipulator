/**
 * @file csv.h
 */

#ifndef CSV_H
#define CSV_H

#include "struct.h"

void ficheiro_csv_1(char *arquivo, Dados *dados);
void ficheiro_csv_2(char *arquivo, Dieta *dieta);
void ficheiro_csv_3(char *arquivo, Plano *plano);
void listar_plano_csv(Plano *plano, int diainicio, int diafim, int mesinicio, int mesfim);
void calcmedia_csv(Dados *dados, Dieta *dieta, int diainicio, int mesinicio, int diafim, int mesfim);
void tabela_csv(Dados *dados, Dieta *dieta, Plano *plano);

#endif