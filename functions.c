#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>


//Funcao para alocar memoria para a matrix do tabuleiro.
char **alocarMatrixTabuleiro(int linhas, int colunas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    char **matrixTabuleiro = (char**)malloc(linhas * sizeof(char *)); //"Linhas".
    for(int i=0; i<linhas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixTabuleiro[i] = (char*)malloc(colunas * sizeof(char)); //"Colunas".
    }
    return matrixTabuleiro; //Retorna a matrix com a quantidade de memoria necessaria.
}


//Funcao para liberar a memoria da matrix do tabuleiro. 
void liberarMatrixTabuleiro(char **matrixTabuleiro, int linhas){
    for(int i=0; i<linhas; i++){
        free(matrixTabuleiro[i]); //Libera a memoria dos ponteiros tipo char. "Colunas"
    }
    free(matrixTabuleiro);//Libera a memoria do array de ponteiros que recebe os ponteiros do tipo char. "Linhas"
}


//Funcao para alocar as instrucoes laterais.
int **alocarInstrucoesLaterais(int maxColunas, int linhas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    int **matrixRegrasLinhas = (int**)malloc(linhas * sizeof(int *)); //"Linhas".
    for(int i=0; i<linhas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixRegrasLinhas[i] = (int*)malloc(maxColunas * sizeof(int)); //"Colunas".
    }
    return matrixRegrasLinhas; //Retorna a matrix com a quantidade de memoria necessaria.
}





//Funcao para liberar a memoria da matrix de instrucao lateral
void liberarMatrixInstrucoesLaterais(int **matrixRegrasLinhas, int linhas){
    for(int i=0; i<linhas; i++){
        free(matrixRegrasLinhas[i]);
    }
    free(matrixRegrasLinhas);
}





//Funcao para alocar as instrucoes acima do tabuleiro.
int **alocarInstrucoesAcima(int colunas, int maxLinhas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    int **matrixRegrasColunas = (int**)malloc(colunas * sizeof(int *)); //"Linhas".
    for(int i=0; i<colunas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixRegrasColunas[i] = (int*)malloc(maxLinhas* sizeof(int)); //"Colunas".
    }
    return matrixRegrasColunas;
}
//Retorna a matrix com a quantidade de memoria necessaria. 




//Funcao para liberar a matrix das instrucoes da parte de cima.
void liberarMatrixInstrucoesAcima(int **matrixRegrasColunas, int maxLinhas){
    for(int i=0; i<maxLinhas; i++){
        free(matrixRegrasColunas[i]);
    }
    free(matrixRegrasColunas);
}



void exibirNonograma(char **matrixTabuleiro, int **matrixRegrasLinhas, int **matrixRegrasColunas, int linhas, int colunas, int maxLinhas, int maxColunas){
    printf("\n");
    //Imprime a matrix de instrucoes que fica na parte de cima.
    for(int i=0; i<maxLinhas; i++){
        printf("         ");
        //Uso o %2d para caso haja numeros maiores que 10. 
        for(int j=0; j<colunas; j++){
            printf("%2d  ", matrixRegrasColunas[j][i]);
        }
        printf("\n");
    }
    

    //Imprime o cabecalho da parte de cima.

    printf("          ");
    for(int i=0; i<colunas; i++){
        printf("%c   ", 'A'+ i);
    }
    printf("\n");




    //Imprime a matrix de instrucoes ao lado e o tabuleiro. 

    for(int i=0; i<linhas; i++){
        for(int j=0; j<maxColunas; j++){
            //Verificacao para caso haja a existencia de numeros maiores que 10.
            if(matrixRegrasLinhas[i][j]>10){
                printf("%2d ", matrixRegrasLinhas[i][j]);
            }
            else{
                printf(" %d ", matrixRegrasLinhas[i][j]);
            }
        }
        //Printa o cabecalho e o tabuleiro
        printf(" %c ", 'A' + i);
        for(int k=0; k<colunas; k++){
            printf(" %c  ", matrixTabuleiro[i][k]);
        }
        printf("\n");
    }
}


//Funcao para sair do jogo.

void sair(char **matrixTabuleiro, int linhas, int **matrixRegrasLinhas, int **matrixRegrasColunas, int maxLinhas){
    liberarMatrixTabuleiro(matrixTabuleiro, linhas);
    liberarMatrixInstrucoesLaterais(matrixRegrasLinhas, linhas);
    liberarMatrixInstrucoesAcima(matrixRegrasColunas, maxLinhas);
    exit(0);
}

//Funcoes para demarcar a matriz tabuleiro, repare que usamos, -97 ao inves de 65, 
//pois, para meios de verificacao, ao receber o comando, tornamos todos os caracteres minusculos
//entao na hora de receber as letras, as recebemos minusculas, entao temos que iteragir apartir dos
//termos em minusculo na tabela ascii.

//Marca a matriz com um x.
void marcarComX(char **matrixTabuleiro, char letraUm, char letraDois){
    int letra1Aux = (int)letraUm;
    int letra2Aux = (int)letraDois;
    matrixTabuleiro[letra1Aux - 97][letra2Aux - 97] = 'x';
}

//Marca a matriz com um traco.
void marcarComTraco(char **matrixTabuleiro, char letraUm, char letraDois){
    int letra1Aux = (int)letraUm;
    int letra2Aux = (int)letraDois;
    matrixTabuleiro[letra1Aux - 97][letra2Aux - 97] = '-';
}

//Marca a matriz com um ponto.
void marcarComPonto(char **matrixTabuleiro, char letraUm, char letraDois){
    int letra1Aux = (int)letraUm;
    int letra2Aux = (int)letraDois;
    matrixTabuleiro[letra1Aux - 97][letra2Aux - 97] = '.';
}












































