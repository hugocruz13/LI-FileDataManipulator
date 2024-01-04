/**
 * @file struct.h
 */

#ifndef STRUCT_H
#define STRUCT_H

/**
 * @def max
 * @brief Define o valor máximo como 100.
 */
#define max 100

/**
 * @def min
 * @brief Define o valor mínimo como 10.
 */
#define min 10

/**
 *@struct Dados
 * @brief Esta estrutura contém arrays para armazenar o número do cliente, o nome do cliente e o número de telefone associado a cada cliente.
 */
typedef struct
{
    int n_cliente[min];          /**< Array para armazenar o número do cliente. */
    char nome_cliente[max][max]; /**< Matriz para armazenar o nome do cliente. */
    int num_telefone[min];       /**< Array para armazenar o número de telefone. */
} Dados;

/**
 * @struct Dieta
 * @brief Esta estrutura contém arrays para armazenar o número do cliente, tipos de refeição, tipos de alimento, calorias, e a data de cada refeição.
 */
typedef struct
{
    int n_cliente[min];      /**< Array para armazenar o número do cliente. */
    char refeicao[max][max]; /**< Matriz para armazenar o tipo de refeição. */
    char alimento[max][max]; /**< Matriz para armazenar o tipo de alimento. */
    int calorias[max];       /**< Array para armazenar a quantidade de calorias. */
    int dia[max];            /**< Array para armazenar o dia da entrada na dieta. */
    int mes[max];            /**< Array para armazenar o mês da entrada na dieta. */
    int ano[max];            /**< Array para armazenar o ano da entrada na dieta. */
} Dieta;

/**
 * @struct Plano
 * @brief Esta estrutura contém arrays para armazenar o número do cliente, data tipos de refeição, calorias minimas e maximas.
 */
typedef struct
{
    int n_cliente[min];      /**< Número do cliente associado ao plano. */
    int dia[max];            /**< Array que armazena os dias do plano. */
    int mes[max];            /**< Array que armazena os meses do plano. */
    int ano[max];            /**< Array que armazena os anos do plano. */
    char refeicao[max][max]; /**< Matriz que armazena as refeições do plano. */
    int calorias_min[min];   /**< Array que armazena as calorias mínimas permitidas. */
    int calorias_max[min];   /**< Array que armazena as calorias máximas permitidas. */
} Plano;

#endif