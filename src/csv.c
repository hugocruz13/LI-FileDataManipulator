/**
 * @file csv.c
 */

#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "csv.h"

/**
 * @brief Verifica os nomes dos ficheiros, caso sejam os ficheiros corretos, entra e verifica as condições, caso contrario, retorna uma mensagem de erro.
 *
 * @param arquivo Nome do arquivo CSV e bin a ser lido na função.
 * @param dados Invocação da struct dados na função.
 */
void ficheiro_csv_1(char *arquivo, Dados *dados)
{
    if (strcmp(arquivo, "dados.csv") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {

        int i = 0;
        FILE *ficheiro = fopen(arquivo, "r"); //**< Abre o ficheiro em modo leitura, com o nome ficheiro. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }

        printf("\nDados clientes:\n\n");

        /**
         * @brief While: percorre o arquivo CSV, lê os dados até ao ';' e armazena-os na struct Dados.
         *
         * @param ficheiro Nome do arquivo CSV a ser lido na função.
         * @param dados Invocação da struct dados na função.
         * @param i Variável para percorrer o array.
         */

        while (fscanf(ficheiro, "%d;%[^;];%d\n", &dados->n_cliente[i], dados->nome_cliente[i], &dados->num_telefone[i]) == 3)
        {
            printf("\t%04d %s %d\n", dados->n_cliente[i], dados->nome_cliente[i], dados->num_telefone[i]);
            i++;
        }

        fclose(ficheiro); //**< Fecha o arquivo. */
    }

    else if (strcmp(arquivo, "dados_csv.bin") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {
        int i = 0;

        FILE *ficheiro = fopen(arquivo, "rb"); //**< Abre o ficheiro em modo leitura (binaria), com o nome ficheiro. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }
        printf("\nDados clientes:\n\n");

        /**
         * @brief For: vai realizar a leitura dos dados do arquivo binário e armazená-los na struct Dados.
         */

        for (int i = 0; i < 3; i++)
        {
            fread(&dados->n_cliente[i], sizeof(int), 1, ficheiro);      //**< Modo leitura relativamente a ficheiros binários */
            fread(dados->nome_cliente[i], sizeof(char), max, ficheiro); //**< Modo leitura relativamente a dados binários do tipo string */
            fread(&dados->num_telefone[i], sizeof(int), 1, ficheiro);   //**< Modo leitura relativamente a dados binários interios */
        }
        /**
         * @brief For: Apresenta os dados armazenados na struct Dados.
         *
         */
        for (int i = 0; i < 3; i++)
        {
            printf("\t%04d %s %d\n", dados->n_cliente[i], dados->nome_cliente[i], dados->num_telefone[i]);
        }

        fclose(ficheiro); //**< Fecha o arquivo. */
    }

    else //**< Outros casos  */
    {
        printf("\nErro: Ficheiro inválido\n"); //**< Mensagem de erro  */
        return;
    }
}
/**
 * @brief Lê dados de um arquivo CSV e os armazena na estrutura Dieta.
 *
 * @param arquivo Nome do arquivo CSV a ser lido na função.
 * @param dieta Invocação da struct dieta na função.
 */
void ficheiro_csv_2(char *arquivo, Dieta *dieta)
{
    if (strcmp(arquivo, "dietas.csv") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {

        FILE *ficheiro = fopen(arquivo, "r"); //**< Abre o ficheiro em modo leitura, como o nome ficheiro. */
        char linha[max];                      //**< Tamanho para armazenar cada linha do arquivo. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }

        printf("\nDieta realizada pelo cliente:\n\n");

        for (int i = 0; i < max; i++)
        {
            if (fgets(linha, sizeof(linha), ficheiro) == NULL) //**< Verifica se as linhas do arquivo CSV estão vazias.Verifica se as linhas do arquivo CSV estão vazias. */
            {
                break; //**< Sai do loop se não houver mais linhas para ler. */
            }

            /**
             * @brief Extrai dados da linha formatada do arquivo CSV e os armazena na estrutura Dieta.
             * @param linha Nome da linha do arquivo CSV a ser lido na função.
             * @param dieta Invocação da struct dieta na função.
             * @param i Variável para percorrer o array.
             *
             */
            sscanf(linha, "%d;%d-%d-%d;%[^;];%[^;];%d ", &dieta->n_cliente[i], &dieta->dia[i], &dieta->mes[i], &dieta->ano[i], dieta->refeicao[i], dieta->alimento[i], &dieta->calorias[i]);
            printf("\t%04d %02d-%02d-%d %s %s %d \n", dieta->n_cliente[i], dieta->dia[i], dieta->mes[i], dieta->ano[i], dieta->refeicao[i], dieta->alimento[i], dieta->calorias[i]);
        }

        fclose(ficheiro); //**< Fecha o arquivo após a leitura dos dados. */
    }

    else if (strcmp(arquivo, "dietas_csv.bin") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {
        FILE *ficheiro = fopen(arquivo, "rb"); //**< Abre o ficheiro em modo leitura (binaria), com o nome ficheiro. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }

        printf("\nDieta realizada pelo cliente:\n\n");

        /**
         * @brief For: vai realizar a leitura dos dados do arquivo binário e armazená-los na struct Dados.
         */

        for (int i = 0; i < 4; i++)
        {
            fread(&dieta->n_cliente[i], sizeof(int), 1, ficheiro);  //**< Modo leitura relativamente a dados binários interios */
            fread(&dieta->dia[i], sizeof(int), 1, ficheiro);        //**< Modo leitura relativamente a dados binários interios */
            fread(&dieta->mes[i], sizeof(int), 1, ficheiro);        //**< Modo leitura relativamente a dados binários interios */
            fread(&dieta->ano[i], sizeof(int), 1, ficheiro);        //**< Modo leitura relativamente a dados binários interios */
            fread(dieta->refeicao[i], sizeof(char), max, ficheiro); //**< Modo leitura relativamente a dados binários do tipo string */
            fread(dieta->alimento[i], sizeof(char), max, ficheiro); //**< Modo leitura relativamente a dados binários do tipo string */
            fread(&dieta->calorias[i], sizeof(int), 1, ficheiro);   //**< Modo leitura relativamente a dados binários interios */
        }
        /**
         * @brief For: Apresenta os dados armazenados na struct Dados.
         *
         */
        for (int i = 0; i < 4; i++)
        {
            printf("\t%04d %02d-%02d-%d %s %s %d \n", dieta->n_cliente[i], dieta->dia[i], dieta->mes[i], dieta->ano[i], dieta->refeicao[i], dieta->alimento[i], dieta->calorias[i]);
        }

        fclose(ficheiro); //**< Fecha o arquivo. */
        return;
    }
    else //**< Outros casos  */
    {
        printf("\nErro: Ficheiro inválido\n"); //**< Mensagem de erro  */
        return;
    }
}

/**
 * @brief Lê dados de um arquivo CSV e bin e armazena os na estrutura Plano.
 *
 * @param arquivo Nome do arquivo (CSV|.bin) a ser lido na função.
 * @param dieta Invocação da struct dieta na função.
 */
void ficheiro_csv_3(char *arquivo, Plano *plano)
{
    if (strcmp(arquivo, "planos.csv") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {
        FILE *ficheiro = fopen(arquivo, "r"); //**< Abre o ficheiro em modo leitura, como o nome ficheiro. */
        char linha[100];                      //**< Tamanho para armazenar cada linha do arquivo. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }

        printf("\nPlano nutricional:\n\n");

        for (int i = 0; i < 100; i++)
        {
            if (fgets(linha, sizeof(linha), ficheiro) == NULL) //**< Verifica se as linhas do arquivo CSV estão vazias.Verifica se as linhas do arquivo CSV estão vazias. */
            {
                break; //**< Sai do loop se não houver mais linhas para ler. */
            }

            /**
             * @brief Extrai dados da linha formatada do arquivo CSV e os armazena na estrutura Dieta.
             * @param linha Nome da linha do arquivo CSV a ser lido na função.
             * @param dieta Invocação da struct dieta na função.
             * @param i Variável para percorrer o array.
             *
             */

            sscanf(linha, "%d;%d-%d-%d;%[^;];%d Cal, %d Cal", &plano->n_cliente[i], &plano->dia[i], &plano->mes[i], &plano->ano[i], plano->refeicao[i], &plano->calorias_min[i], &plano->calorias_max[i]);
            printf("\t%04d %02d-%02d-%d %s %d Cal, %d Cal \n", plano->n_cliente[i], plano->dia[i], plano->mes[i], plano->ano[i], plano->refeicao[i], plano->calorias_min[i], plano->calorias_max[i]);
        }
        fclose(ficheiro); //**< Fecha o arquivo após a leitura dos dados. */
    }
    else if (strcmp(arquivo, "planos_csv.bin") == 0) //**< Compara as strings, caso sejam iguais entra neste loop */
    {
        FILE *ficheiro = fopen(arquivo, "rb"); //**< Abre o ficheiro em modo leitura (binaria), com o nome ficheiro. */

        if (ficheiro == NULL) //**< Verifica se o ficheiro é nulo, caso seja entra no ciclo*/
        {
            printf("Erro: Não foi possível abrir %s\n", arquivo); //**< Apresenta uma mensagem de erro*/
            return;                                               //**< Retorno indicando falha na abertura do arquivo.*/
        }

        printf("\nPlano nutricional:\n\n");

        /**
         * @brief For: vai realizar a leitura dos dados do arquivo binário e armazená-los na struct Dados.
         */

        for (int i = 0; i < 3; i++)
        {
            fread(&plano->n_cliente[i], sizeof(int), 1, ficheiro);    //**< Modo leitura relativamente a dados binários interios */
            fread(&plano->dia[i], sizeof(int), 1, ficheiro);          //**< Modo leitura relativamente a dados binários interios */
            fread(&plano->mes[i], sizeof(int), 1, ficheiro);          //**< Modo leitura relativamente a dados binários interios */
            fread(&plano->ano[i], sizeof(int), 1, ficheiro);          //**< Modo leitura relativamente a dados binários interios */
            fread(plano->refeicao[i], sizeof(char), max, ficheiro);   //**< Modo leitura relativamente a dados binários do tipo string */
            fread(&plano->calorias_min[i], sizeof(int), 1, ficheiro); //**< Modo leitura relativamente a dados binários interios */
            fread(&plano->calorias_max[i], sizeof(int), 1, ficheiro); //**< Modo leitura relativamente a dados binários interios */
        }
        /**
         * @brief For: Apresenta os dados armazenados na struct Dados.
         */
        for (int i = 0; i < 3; i++)
        {
            printf("\t%04d %02d-%02d-%d %s %d Cal, %d Cal \n", plano->n_cliente[i], plano->dia[i], plano->mes[i], plano->ano[i], plano->refeicao[i], plano->calorias_min[i], plano->calorias_max[i]);
        }

        fclose(ficheiro); //**< Fecha o arquivo. */
    }
    else //**< Outros casos  */
    {
        printf("\nErro: Ficheiro inválido\n"); //**< Mensagem de erro  */
        return;
    }
}

/**
 * @brief Está função é responsável por listar um cliente existente no plano, a escolha do utilizador para ficheiros CSV.
 *
 * Realiza a leitura do número do cliente e da refeição que o utilizador pretende visualizar, verifica o periodo em
 * seguida compra cliente e refeição com os dados do plano, caso sejam verdadeiros apresenta os dados do cliente
 * caso sejam falsa aprenta uma mensagem de erro.
 *
 * @param plano Invocação da struct plano na função.
 * @param diainicio Invocação  do dia de início defenido.
 * @param mesinicio Invocação  do mes de início defenido.
 * @param diafim Invocação  do dia de fim defenido.
 * @param mesfim  Invocação  do mes de fim defenido.
 */
void listar_plano_csv(Plano *plano, int diainicio, int diafim, int mesinicio, int mesfim)
{
    int cliente;       //**< Armazena nº cliente*/
    char refeicao[20]; //**< Armazena o nome do cliente*/

    printf("\nDigite o cliente e a refeição que pretende visualizar (numero refeição):");
    scanf("%d%[^\n]", &cliente, refeicao); //**< Realiza a leitura */

    printf("\n  Plano nutricional do cliente %04d, refeição:%s\n\n", cliente, refeicao); //**< Apresenta os clientes selecionados */

    for (int i = 0; i < max; i++)
    {
        if ((mesinicio < plano->mes[i] && plano->mes[i] < mesfim) || //**< Verifica o período se for válido entra no loop */
            (mesinicio == plano->mes[i] && diainicio <= plano->dia[i] && plano->dia[i] <= diafim) ||
            (mesfim == plano->mes[i] && diainicio <= plano->dia[i] && plano->dia[i] <= diafim))
        {
            if (cliente == plano->n_cliente[i]) //**< Verifica se o cliente existe */
            {
                if (strcmp(refeicao, plano->refeicao[i]) == 0) //**< Verifica se a refeição existe */
                {
                    printf("\t%04d %02d-%02d-%d %s %d Cal, %d Cal\n", plano->n_cliente[i], plano->dia[i], plano->mes[i], plano->ano[i], plano->refeicao[i], plano->calorias_min[i], plano->calorias_max[i]); //**< Apresenta o plano do cliente selecionado */
                }
            }
        }
    }
}

/**
 * @brief Calcula a média de calorias consumidas por cliente num período de tempo para ficheiros CSV.
 *
 * Inicialmente, a mesma verifica se as datas estão dentro de intervalos válidos, restringindo assim alguns dos clientes, em seguida
 * verifica o numero de cliente e a refeição, onde realiza a soma das calorias e a contagem de vezes que o cliente realizou a refeição.
 * Por fim caso as calorias sejam diferentes de 0, realiza a média das calorias consumidas por cliente.
 *
 * @param plano Invocação da struct plano na função.
 * @param diainicio Invocação  do dia de início defenido.
 * @param mesinicio Invocação  do mes de início defenido.
 * @param diafim Invocação  do dia de fim defenido.
 * @param mesfim  Invocação  do mes de fim defenido.
 */
void calcmedia_csv(Dados *dados, Dieta *dieta, int diainicio, int mesinicio, int diafim, int mesfim)
{
    int i = 0;                                                //**< Responsável por percorrer o array*/
    float c1_pequeno = 0, c1_almoco = 0, c1_jantar = 0;       //**< Armazena as contagens */
    float cal_pequeno1 = 0, cal_almoco1 = 0, cal_jantar1 = 0; //**< Armazena as calorias */

    float c2_pequeno = 0, c2_almoco = 0, c2_jantar = 0;       //**< Armazena as contagens */
    float cal_pequeno2 = 0, cal_almoco2 = 0, cal_jantar2 = 0; //**< Armazena as calorias */

    float c3_pequeno = 0, c3_almoco = 0, c3_jantar = 0;       //**< Armazena as contagens */
    float cal_pequeno3 = 0, cal_almoco3 = 0, cal_jantar3 = 0; //**< Armazena as calorias */

    printf("\nMédia de todos os clientes:\n\n");

    for (i = 0; i < 4; i++)
    {
        if ((mesinicio < dieta->mes[i] && dieta->mes[i] < mesfim) || //**< Verifica o período  */
            (mesinicio == dieta->mes[i] && diainicio <= dieta->dia[i] && dieta->dia[i] <= diafim) ||
            (mesfim == dieta->mes[i] && diainicio <= dieta->dia[i] && dieta->dia[i] <= diafim))
        {
            if (dieta->n_cliente[i] == 1) //**< Verifica o numero de cliente */
            {
                if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_pequeno1 = cal_pequeno1 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c1_pequeno++;                                     //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_almoco1 = cal_almoco1 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c1_almoco++;                                    //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição  */
                {
                    cal_jantar1 = cal_jantar1 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c1_jantar++;                                    //**< Contador  */
                }
            }

            if (dieta->n_cliente[i] == 2) //**< Verifica o numero de cliente */
            {
                if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_pequeno2 = cal_pequeno2 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c2_pequeno++;                                     //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_almoco2 = cal_almoco2 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c2_almoco++;                                    //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição  */
                {
                    cal_jantar2 = cal_jantar2 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c2_jantar++;                                    //**< Contador  */
                }
            }

            if (dieta->n_cliente[i] == 3) //**< Verifica o numero de cliente */
            {
                if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_pequeno3 = cal_pequeno3 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c3_pequeno++;                                     //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição  */
                {
                    cal_almoco3 = cal_almoco3 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c3_almoco++;                                    //**< Contador  */
                }
                if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição  */
                {
                    cal_jantar3 = cal_jantar3 + dieta->calorias[i]; //**< Acumula as calorias  */
                    c3_jantar++;                                    //**< Contador  */
                }
            }
        }
    }

    // Cliente 1
    if (cal_pequeno1 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_pequeno1 = cal_pequeno1 / c1_pequeno;                                                   //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 1 ao pequeno almoço: %.2f\n", media_cal_pequeno1); //**< Apresenta a media  */
    }

    if (cal_almoco1 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_almoco1 = cal_almoco1 / c1_almoco;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 1 ao almoço: %.2f\n", media_cal_almoco1); //**< Apresenta a media  */
    }

    if (cal_jantar1 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_jantar1 = cal_jantar1 / c1_jantar;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 1 ao jantar: %.2f\n", media_cal_jantar1); //**< Apresenta a media  */
    }

    // Cliente 2
    if (cal_pequeno2 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_pequeno2 = cal_pequeno2 / c2_pequeno;                                                   //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 2 ao pequeno almoço: %.2f\n", media_cal_pequeno2); //**< Apresenta a media  */
    }

    if (cal_almoco2 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_almoco2 = cal_almoco2 / c2_almoco;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 2 ao almoço: %.2f\n", media_cal_almoco2); //**< Apresenta a media  */
    }

    if (cal_jantar2 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_jantar2 = cal_jantar2 / c2_jantar;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 2 ao jantar: %.2f\n", media_cal_jantar2); //**< Apresenta a media  */
    }

    // Cliente 3
    if (cal_pequeno3 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_pequeno3 = cal_pequeno3 / c3_pequeno;                                                   //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 3 ao pequeno almoço: %.2f\n", media_cal_pequeno3); //**< Apresenta a media  */
    }

    if (cal_almoco3 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_almoco3 = cal_almoco3 / c3_almoco;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 3 ao almoço: %.2f\n", media_cal_almoco3); //**< Apresenta a media  */
    }

    if (cal_jantar3 != 0) //**< Se as calorias forem diferentes de 0 entra no loop  */
    {
        float media_cal_jantar3 = cal_jantar3 / c3_jantar;                                             //**< Realiza a media   */
        printf("\tMédia das calorias consumidas pelo cliente 3 ao jantar: %.2f\n", media_cal_jantar3); //**< Apresenta a media  */
    }
}

/**
 * @brief Tabela com todas as informações do plano nutricional para ficheiros CSV.
 *
 * Inicialmente, a mesma verifica o numero de cliente e a refeição, dentro dessas condições soma as calorias e por cliente e refeição.
 * Por fim verifica o numero de cliente e a refeição, e apresenta as calorias acumuladas por cliente.
 *
 * @param dados Invocação da struct dados na função.
 * @param dieta Invocação da struct dieta na função.
 * @param plano Invocação da struct plano na função.
 */
void tabela_csv(Dados *dados, Dieta *dieta, Plano *plano)
{
    float cal_pequeno1 = 0, cal_almoco1 = 0, cal_jantar1 = 0; //**< Armazena as calorias cliente 1*/
    float cal_pequeno2 = 0, cal_almoco2 = 0, cal_jantar2 = 0; //**< Armazena as calorias cliente 2*/
    float cal_pequeno3 = 0, cal_almoco3 = 0, cal_jantar3 = 0; //**< Armazena as calorias cliente 3*/

    for (int i = 0; i < 6; i++)
    {

        if (dieta->n_cliente[i] == 1) //**< Verifica o cliente */
        {
            if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição */
            {
                cal_pequeno1 = cal_pequeno1 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição */
            {
                cal_almoco1 = cal_almoco1 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição */
            {
                cal_jantar1 = cal_jantar1 + dieta->calorias[i]; //**< Soma as calorias */
            }
        }

        if (dieta->n_cliente[i] == 2) //**< Verifica o cliente */
        {
            if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição */
            {
                cal_pequeno2 = cal_pequeno2 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição */
            {
                cal_almoco2 = cal_almoco2 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição */
            {
                cal_jantar2 = cal_jantar2 + dieta->calorias[i]; //**< Soma as calorias */
            }
        }

        if (dieta->n_cliente[i] == 3) //**< Verifica o cliente */
        {
            if (strcmp(dieta->refeicao[i], " pequeno almoço") == 0) //**< Verifica a refeição */
            {
                cal_pequeno3 = cal_pequeno3 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " almoço") == 0) //**< Verifica a refeição */
            {
                cal_almoco3 = cal_almoco3 + dieta->calorias[i]; //**< Soma as calorias */
            }
            if (strcmp(dieta->refeicao[i], " jantar") == 0) //**< Verifica a refeição */
            {
                cal_jantar3 = cal_jantar3 + dieta->calorias[i]; //**< Soma as calorias */
            }
        }
    }

    printf("\nTabela:\n\n");
    printf("\t-----------------------------------------------------------------------------------------------\n");
    printf("\t|   NP   | Paciente |   Tipo Refeição  |   Inicio   |    Fim     | Mínimo | Máximo  | Consumo |\n");
    printf("\t|--------|----------|------------------|------------|------------|--------|---------|---------|\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (dados->n_cliente[i] == plano->n_cliente[j]) //**< Responsável por verificar os clientes que contém planos, para realizar a aprsentação do nome correto  */
            {

                if (dieta->n_cliente[i] == 1) //**< Verifica o cliente */
                {
                    if (strcmp(plano->refeicao[j], " jantar") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-16s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f   |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_jantar1); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_almoco1); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " pequeno almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_pequeno1); //**< Apresenta linha da tabela */
                    }
                    else //**< Outros casos */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   | -----\n ", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j]); //**< Apresenta linha da tabela */
                    }
                }
                if (dieta->n_cliente[i] == 2) //**< Verifica o cliente */
                {
                    if (strcmp(plano->refeicao[j], " jantar") == 0) //**< Verifica a refeição */
                    {

                        printf("\t|  %04d  |   %s  | %-16s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f   |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_jantar2); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_almoco2); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " pequeno almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_pequeno2); //**< Apresenta linha da tabela */
                    }
                    else //**< Outros casos */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   | -----\n ", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j]); //**< Apresenta linha da tabela */
                    }
                }

                if (dieta->n_cliente[i] == 3) //**< Verifica o cliente */
                {
                    if (strcmp(plano->refeicao[j], " jantar") == 0) //**< Verifica a refeição */
                    {

                        printf("\t|  %04d  |   %s  | %-16s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f   |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_jantar3); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_almoco3); //**< Apresenta linha da tabela */
                    }
                    else if (strcmp(plano->refeicao[j], " pequeno almoço") == 0) //**< Verifica a refeição */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   |  %0.2f |\n", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j], cal_pequeno3); //**< Apresenta linha da tabela */
                    }
                    else //**< Outros casos */
                    {
                        printf("\t|  %04d  |   %s  | %-17s | %02d-%02d-2023 | %02d-%02d-2023 |  %d   |   %d   | -----\n ", plano->n_cliente[j], dados->nome_cliente[i], plano->refeicao[j], dieta->dia[i], dieta->mes[i], plano->dia[j], plano->mes[j], plano->calorias_min[j], plano->calorias_max[j]); //**< Apresenta linha da tabela */
                    }
                }
            }
        }
    }
    printf("\t----------------------------------------------------------------------------------------------\n");
}