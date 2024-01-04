/**
 * @file tsv.h
 */

#ifndef TSV_H
#define TSV_H

#include "struct.h"

void ficheiro_tsv_1(char *arquivo, Dados *dados);
void ficheiro_tsv_2(char *arquivo, Dieta *dieta);
void ficheiro_tsv_3(char *arquivo, Plano *plano);
void listar_plano_tsv(Plano *plano, int diainicio, int diafim, int mesinicio, int mesfim);
void calcmedia_tsv(Dados *dados, Dieta *dieta, int diainicio, int mesinicio, int diafim, int mesfim);
void tabela_tsv(Dados *dados, Dieta *dieta, Plano *plano);

#endif