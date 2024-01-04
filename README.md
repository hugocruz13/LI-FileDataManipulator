# Trabalho Prático

Licenciatura em Engenharia de Sistemas Informáticos 2023-24

Laboratórios de Informática

## Grupo  *30*
| Número | Nome |
| -----  | ---- |
| a23010 | Hugo Cruz |
| a23015 | Lino Azevedo |
| a23016 | Dani Cruz |

## Organização

[doc/](./doc/)  documentação com o relatório

[src/](./src/)  Código da solução desenvolvida 

## Relatórios e Código

- **Relatório LaTeX:** [doc/relatorio/d-30-doc.pdf](doc/relatorio/d-30-doc.pdf)
- **Relatório Doxygen:** [doc/latex/d-30-refman.pdf](doc/latex/d-30-refman.pdf)
- **Código Fonte:** [src/](/src/)

## Descrição do Projeto

O projeto consiste em desenvolver um programa em C para gerenciar informações relacionadas à saúde e nutrição de 
pacientes. O programa permite carregar dados de pacientes, informações sobre suas dietas e planos nutricionais a 
partir de arquivos de texto. Além disso, oferece funcionalidades como apresentar estatísticas sobre a ingestão 
de calorias, listar pacientes com refeições fora do intervalo prescrito e gerar tabelas de refeições planeadas e 
realizadas

## Estratégia de Desenvolvimento 

- **Hugo Cruz (a23010):** Implementação do modo de utilização, argumentos, listar o paciente do plano nutricional, 
tabelas ficheiros binários, e divisão em ficheiros .c, .h, CSV, desenvolvimento do relatório. 

- **Lino Azevedo (a23015):** Implementação do contador, listagem de cliente fora intervalo de calorias, calculo da 
média de calorias por cliente, num determinado período, desenvolvimento do relatório.

- **Dani Cruz (a23016):** Implementação de ficheiros CSV e TSV, divisão em ficheiros .c .h para as funções TSV, e 
ficheiro.h contendo as struct, desenvolvimento do relatório.
 
## Decisões Coletivas 

-No âmbito da nossa colaboração no projeto em grupo, começámos por realizar uma seleção criteriosa de ficheiros 
CSV. Durante a análise, constatámos que esses ficheiros utilizam tanto pontos e vírgulas como vírgulas para 
separar as palavras. Esta escolha revelou-se fundamental, uma vez que verificámos que as informações presentes 
no enunciado seguiam precisamente essa estrutura. Optámos, assim, por utilizar esses ficheiros, com o propósito 
de assegurar uma correspondência exata com o formato das informações fornecidas, conclusão que considerámos ser 
a mais apropriada para atingir os nossos objetivos.

-Paralelamente, no decurso do desenvolvimento do projeto, deparámo-nos com um desafio relacionado à utilização de 
variáveis em funções. Após uma deliberação conjunta, decidimos adotar a abordagem estruturada através da 
utilização de "struct", o que nos possibilita a utilização das variáveis em qualquer momento do código.

-Por fim, decidimos ajustar a nossa estratégia em relação aos argumentos. Inicialmente, optámos por utilizar 1 
argumento apenas para deferir o modo onde nos deparamos poder vir a ser um problema relativamente aos ficheiros 
binários, então colocamos 5 argumentos podendo definir os ficheiros que pretendíamos utilizar.

## Compilação e Execução:

Para compilar este projeto, é necessário ter o comando "make" instalado. Após a instalação, um arquivo Makefile 
está disponível no diretório. Este arquivo é responsável por compilar automaticamente todos os arquivos. Basta 
executar make para realizar a compilação.

```bash
make
```

## Comando com Sintaxe de Utilização:

- Ficheiros (CSV): `./prog -csv dados.csv dietas.csv planos.csv`
- Ficheiros (TSV): `./prog -tsv dados.tsv dietas.tsv planos.tsv`
- Ficheiros (CSV|bin): `./prog -csv dados.csv dietas_csv.bin planos.csv`
- Ficheiros (TSV|bin): `./prog -tsv dados.tsv dietas_tsv.bin planos_tsv.bin`

## Conclusão
O presente relatório é parte integrante da avaliação do trabalho prático da Unidade Curricular Laboratórios de Informática.

Ao longo do projeto, enfrentamos a decisão crucial de não apenas utilizar ficheiros CSV, mas também de incorporar ficheiros TSV, que são delimitados por tabulações, e posteriormente, ficheiros no formato binário.

Durante o desenvolvimento, deparamo-nos com a necessidade de uma abordagem estruturada para manipular variáveis em funções. A decisão coletiva de adotar "struct" conferiu-nos flexibilidade, permitindo o acesso a variáveis em qualquer ponto do código. Esta escolha contribuiu significativamente para a clareza e organização do nosso código.

Uma das etapas que se revelou particularmente desafiadora foi a elaboração do relatório em LaTeX, uma tarefa que conseguimos concluir com êxito.

Este projeto não apenas aprimorou as nossas habilidades técnicas, mas também destacou a importância de decisões ponderadas e flexibilidade durante o processo de desenvolvimento. Cada desafio superado contribuiu para uma compreensão mais profunda das melhores práticas de programação e promoveu um ambiente colaborativo e eficiente na execução do projeto em grupo.

Embora tenha sido uma etapa desafiadora, acreditamos que alcançamos não só os objetivos propostos, mas também os prazos definidos.


