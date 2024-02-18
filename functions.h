// * Arquivo de cabecalho(header) com os prototipos das funcoes
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
char **alocarMatrixTabuleiro(int linhas, int colunas);
void liberarMatrixTabuleiro(char **matrix, int linhas);
int **alocarInstrucoesLaterais(int maxColunas, int linhas);
void liberarMatrixInstrucoesLaterais(int **matrixRegrasLinhas, int linhas);
int **alocarInstrucoesAcima(int colunas, int maxLinhas);
void liberarMatrixInstrucoesAcima(int **matrixRegrasColunas, int maxLinhas);
void exibirNonograma(char **matrixTabuleiro, int **matrixRegrasLinhas, int **matrixRegrasColunas, int linhas, int colunas, int maxLinhas, int maxColunas);
void sair(char **matrixTabuleiro, int linhas, int **matrixRegrasLinhas, int **matrixRegrasColunas, int maxLinhas);
void removerDoisPrimeirosCaracteres(char *str);
void marcarComX(char **matrixTabuleiro, char letraUm, char letraDois);
void marcarComTraco(char **matrixTabuleiro, char letraUm, char letraDois);
void marcarComPonto(char **matrixTabuleiro, char letraUm, char letraDois);
 









#endif

