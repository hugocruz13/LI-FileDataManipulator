/**
 * @file main.c
 * @author Grupo 30
 * @brief
 * @version 0.73
 * @date 2023-12-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <string.h>
#include "csv.h"
#include "tsv.h"

/**
 * @brief Define um período especificado pelos usuários.
 *
 * Esta função solicita ao usuário que insira datas de início e fim (no formato dd-mm)
 * e verifica se as datas estão dentro de intervalos válidos (dia: 1-31, mês: 1-12).
 * A função continua a solicitar entradas até que datas válidas sejam fornecidas.
 *
 * @param diainicio Armazena o dia de início defenido.
 * @param mesinicio Armazena o mes de início defenido.
 * @param diafim Armazena o dia de fim defenido.
 * @param mesfim Armazena o mes de fim defenido.
 */
void periodo(int *diainicio, int *mesinicio, int *diafim, int *mesfim)
{
    printf("\nDefinir periodo (dd-mm): \n");
    while (*diainicio > 31 || *diainicio < 1 || *mesinicio > 12 || *mesinicio < 1) //**< Condições necessárias  */
    {
        printf("\n\tData de inicio: ");
        scanf("%d-%d", diainicio, mesinicio); //**< Leitura das datas de inicio  */
    }

    while (*diafim > 31 || *diafim < 1 || *mesfim > 12 || *mesfim < 1) //**< Condições necessárias  */
    {
        printf("\tData de fim: ");
        scanf("%d-%d", diafim, mesfim); //**< Leitura das datas de fim  */
    }
}
/**
 * @brief Realiza a contagem de quem ultrapassou certas calorias num período de tempo.
 *
 * Esta função solicita ao usuário que insira um valor de calorias e um período de tempo (no formato dd-mm),
 * e verifica se as datas estão dentro de intervalos válidos (dia: 1-31, mês: 1-12), e se as calorias do ficheiro
 * dietas forem maiores que as inseridas, realiza a contagem de quantos utilizadores ultrapassaram as calorias.
 *
 * @param dieta Invocação da struct dieta na função.
 * @param diainicio Invocação  do dia de início defenido.
 * @param mesinicio Invocação  do mes de início defenido.
 * @param diafim Invocação  do dia de fim defenido.
 * @param mesfim  Invocação  do mes de fim defenido.
 */
void contador_calorias(Dieta *dieta, int diainicio, int diafim, int mesinicio, int mesfim)
{
    float calorias;   //**< Armazena as calorias inseridas pelo utilizador  */
    int contador = 0; //**< Realiza a contagem dos clientes que ultrapassaram as calorias inseridas */

    printf("\nDigite o valor de calorias que pretende ver quantos utilizadores ultrapassaram:");
    scanf("%f", &calorias);

    for (int i = 0; i < 4; i++)
    {
        if ((mesinicio < dieta->mes[i] && dieta->mes[i] < mesfim) || //**< Verifica o período se for válido entra no loop */
            (mesinicio == dieta->mes[i] && diainicio <= dieta->dia[i] && dieta->dia[i] <= diafim) ||
            (mesfim == dieta->mes[i] && diainicio <= dieta->dia[i] && dieta->dia[i] <= diafim))
        {
            if (dieta->calorias[i] > calorias) //**< Verifica se as calorias são maiores que as inseridas pelo utilizador */
            {
                contador++; //**< Contador de utilizadores que ultrapassaram as calorias
            }
        }
    }

    printf("\n\tDe 4 utilizadores %d ultrapassaram as %0.01f calorias. \n", contador, calorias);
}
/**
 * @brief Está função é responsável por ordenar os clientes por ordem decrescente e apresentar os clientes fora do intervalo de calorias.
 *
 *Inicialmente, a mesma verifica se as datas estão dentro de intervalos válidos, restringindo assim alguns dos clientes,
 *caso as datas estejam dfora dos intervalos válidos, compara os números de cliente da struct dieta com os números de cliente
 *da struct plano, garantindo que os clientes que não estão no plano não são apresentados. Por fim, compara as refeições, garantindo
 *que os clientes realizem as refeições planeadas no plano, e valida se estão fora do intervalo de calorias.
 *
 * @param dieta Invocação da struct dieta na função.
 * @param plano Invocação da struct plano na função.
 * @param diainicio Invocação  do dia de início defenido.
 * @param mesinicio Invocação  do mes de início defenido.
 * @param diafim Invocação  do dia de fim defenido.
 * @param mesfim  Invocação  do mes de fim defenido.
 */

void listagem(Dieta *dieta, Plano *plano, Dados *dados, int diainicio, int diafim, int mesinicio, int mesfim)
{
    int j, k, temp;                    //**< Variáveis auxiliares */
    int clientes_verificados[4] = {0}; //**< Array para armazenar os clientes verificados */
    char nomes_ordenados[max][max];    //**< Matriz para armazenar os nomes dos clientes verificados */

    for (j = 0; j < 4; j++)
    {
        if ((mesinicio < dieta->mes[j] && dieta->mes[j] < mesfim) || //**< Verifica o período se for válido entra no loop */
            (mesinicio == dieta->mes[j] && diainicio <= dieta->dia[j] && dieta->dia[j] <= diafim) ||
            (mesfim == dieta->mes[j] && diainicio <= dieta->dia[j] && dieta->dia[j] <= diafim))
        {
            for (k = 0; k < 4; k++)
            {
                if (dieta->n_cliente[j] == plano->n_cliente[k]) //**< Verifica se os clientes existem em planos */
                {
                    if (strcmp(dieta->refeicao[j], plano->refeicao[k]) == 0) //**< Verifica se as refeições existem em planos */
                    {
                        if (dieta->calorias[j] < plano->calorias_min[k] || dieta->calorias[j] > plano->calorias_max[k]) //**< Verifica se as calorias estão fora do intervalo defenido */
                        {
                            if (dados->n_cliente[j] != 0)
                            {
                                clientes_verificados[j] = dados->n_cliente[j];      //**< Armazena os clientes verificados num variavel da função*/
                                strcpy(nomes_ordenados[j], dados->nome_cliente[j]); //**< Armazena os nomes dos clientes verificados num variavel da função*/
                            }
                        }
                    }
                }
            }
        }
    }

    for (j = 0; j < 4; j++)
    {
        for (k = j + 1; k < 4; k++)
        {
            if (clientes_verificados[j] < clientes_verificados[k]) //**< Ordena os clientes por ordem decrescente */
            {
                temp = clientes_verificados[j];
                clientes_verificados[j] = clientes_verificados[k];
                clientes_verificados[k] = temp;

                char temp_nome[50];
                strcpy(temp_nome, nomes_ordenados[j]);
                strcpy(nomes_ordenados[j], nomes_ordenados[k]);
                strcpy(nomes_ordenados[k], temp_nome);
            }
        }
    }

    // Imprimir os clientes ordenados
    printf("\nListagem dos pacientes ordenada por ordem decrescente:\n\n");
    for (j = 0; j < 4; j++)
    {
        if (clientes_verificados[j] != 0)
        {
            printf("\t%04d %s\n", clientes_verificados[j], nomes_ordenados[j]); //**< Apresenta os clientes ordenados */
        }
    }
}


/**
 * @brief Função principal do programa.
 * @param argc Número de argumentos de linha de comando.
 * @param argv Array de strings contendo os argumentos de linha de comando.
 */
int main(int argc, char *argv[])
{
    int modo;
    int diainicio = 0, diafim = 0; //**< Armazena dias */
    int mesinicio = 0, mesfim = 0; //**< Armazena meses */

    if (argc < 2) //**< Verifica se o numero de argumentos */
    {
        printf("Caso necessite de ajuda: %s -ajuda\n", argv[0]); //**< Apresenta a mensagem como usar modo -ajuda */
        return 1;
    }

    if (strcmp(argv[1], "-csv") == 0) //**< Verifica se o argumento é -csv */
        modo = 1;
    else if (strcmp(argv[1], "-tsv") == 0) //**< Verifica se o argumento é -tsv */
        modo = 2;
    else if (strcmp(argv[1], "-ajuda") == 0) //**< Verifica se o argumento é -ajuda */
        modo = 3;
    else //**< Outros casos */
    {
        printf("Caso necessite de ajuda: %s -ajuda\n", argv[0]);
        return 1;
    }

    Dados dados; //**< Invocação da struct dados */
    Dieta dieta; //**< Invocação da struct dieta */
    Plano plano; //**< Invocação da struct plano */

    switch (modo)
    {
    case 1: //**< Caso o argumento seja -csv */

        ficheiro_csv_1(argv[2], &dados);                                        //**< Invoca a função ficheiro_csv_1*/
        ficheiro_csv_2(argv[3], &dieta);                                        //**< Invoca a função ficheiro_csv_2*/
        ficheiro_csv_3(argv[4], &plano);                                        //**< Invoca a função ficheiro_csv_3*/
        periodo(&diainicio, &diafim, &mesinicio, &mesfim);                      //**< Invoca a função periodo*/
        contador_calorias(&dieta, diainicio, mesinicio, diafim, mesfim);        //**< Invoca a função */
        listagem(&dieta, &plano, &dados, diainicio, mesinicio, diafim, mesfim); //**< Invoca a função contador_calorias*/
        listar_plano_csv(&plano, diainicio, mesinicio, diafim, mesfim);         //**< Invoca a função listar_plano_csv */
        calcmedia_csv(&dados, &dieta, diainicio, diafim, mesinicio, mesfim);    //**< Invoca a função calcmedia_csv*/
        tabela_csv(&dados, &dieta, &plano);                                     //**< Invoca a função tabela_csv*/

        break;

    case 2: //**< Caso o argumento seja -tsv */

        ficheiro_tsv_1(argv[2], &dados);                                        //**< Invoca a função ficheiro_tsv_1*/
        ficheiro_tsv_2(argv[3], &dieta);                                        //**< Invoca a função ficheiro_tsv_2 */
        ficheiro_tsv_3(argv[4], &plano);                                        //**< Invoca a função ficheiro_tsv_3 */
        periodo(&diainicio, &diafim, &mesinicio, &mesfim);                      //**< Invoca a função periodo*/
        contador_calorias(&dieta, diainicio, mesinicio, diafim, mesfim);        //**< Invoca a função contador_calorias*/
        listagem(&dieta, &plano, &dados, diainicio, mesinicio, diafim, mesfim); //**< Invoca a função */
        listar_plano_tsv(&plano, diainicio, mesinicio, diafim, mesfim);         //**< Invoca a função listagem*/
        calcmedia_tsv(&dados, &dieta, diainicio, diafim, mesinicio, mesfim);    //**< Invoca a função calcmedia_tsv*/
        tabela_tsv(&dados, &dieta, &plano);                                     //**< Invoca a função tabela_tsv*/

        break;

    case 3: //**< Caso o argumento seja -ajuda */

        printf("\nEste programa utiliza os seguintes formatos (CSV ou TSV). Existindo tambem uma versão binária de cada ficheiro \n");
        printf("\nModo de utilização:\n");
        printf("\tPara utilizar com arquivos CSV, execute: %s -csv dados.csv dietas.csv planos.csv\n", argv[0]);
        printf("\tPara utilizar com arquivos TSV, execute: %s -tsv dados.tsv dietas.tsv planos.tsv\n", argv[0]);
        printf("\tPara utilizar com arquivos (CSV|bin), execute: %s -csv dados.csv dietas_csv.bin planos.csv\n", argv[0]);
        printf("\tPara utilizar com arquivos (TSV|bin), execute: %s -tsv dados.tsv dietas_tsv.bin planos_tsv.bin\n", argv[0]);
        break;

        return 0;
    }
}