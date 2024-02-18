//Jeanlucas Ferreira Santana 23.2.4071

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include <ctype.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET


#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)


































//Função espera receber argumentos da linha de comando, no caso, o nosso programa e o arquivo txt.

int main(int argc, char *argv[]){
    char **matrixTabuleiro;
    int linhas, colunas;
    int **matrixRegrasLinhas, **matrixRegrasColunas;
    int maxColunas = 0, maxLinhas = 0, auxLinhas= 0, auxColunas=0;
    int *vetor;
    int *vetor2;

    //Abertura do arquivo e leitura de dados.


    //Verifica se há pelo menos um argumento além do nome do programa.
    if(argc == 2){
        //Armazena o arquivo txt em uma variavel, para ser acessado e lido depois.
        char *arquivoTxt = argv[1];
        //Abre o arquivo para leitura.
        FILE *arquivo = fopen(arquivoTxt, "r");

        //Verifica se o arquivo foi aberto com sucesso e realiza as operacoes necessarias.
        if(arquivo != NULL){
            //Le 2 inteiros apartir do arquivo, como o numero de linhas
            //e colunas esta na primeira linha do arquivo, facilita nosso trabalho. 
            if(fscanf(arquivo, "%d %d", &linhas, &colunas)==2){
                //printf("Valores lidos: %d %d\n", linhas, colunas);
                printf("\n");
                if(linhas > 26 || colunas > 26){
                    printf("Erro: Número de linhas e/ou colunas inválido(s).\n");
                    fclose(arquivo);
                    return 1;
                }
            }
            else{
                printf("Erro ao ler o numero de linhas e colunas.\n");
                //Fecha o arquivo.
                fclose(arquivo);
                return 1;
            }
            
          
            //Leitura do numero maximo de numeros nas instrucoes laterais, 
            //uso o nome de auxColunas e maxColunas, pois as instrucoes laterais sao
            //delimitadas pelas colunas, alem de acrescentar um espaco a mais para o cabecalho.
            
                
            int *primeiroNumero = malloc(linhas * sizeof(int));
            char linha[100];

            for (int i = 0; i < linhas; i++) {
                if(fgets(linha, sizeof(linha), arquivo) != NULL) {
                    if(sscanf(linha, "%d", &auxColunas)==1){
                        if (auxColunas > maxColunas) {
                        maxColunas = auxColunas;
                    }
                        primeiroNumero[i] = auxColunas;
                    }
                }
            }

        


            // Exibe os valores usados para saber a quantidade de colunas da matriz instrucao.
            /*printf("Valores do primeiro número de cada linha do bloco 1: \n");
            for (int i = 0; i < linhas; i++) {
                printf("%d ", primeiroNumero[i]);
            }
            printf("\n");*/
            //printf("Maior valor para o numero de colunas da Matriz de instrucoes laterais: %d\n", maxColunas);
            //printf("\n");
            //free(primeiroNumero);



            //Leitura do numero maximo de numeros nas instrucoes acima do tabuleiro, 
            //uso o nome de auxLinhas e maxLinhas, pois as instrucoes acima do tabuleiro sao
            //delimitadas pelas linhas, alem de acrescentar um espaco a mais para o cabecalho.


            int *primeiroNumero1 = malloc(colunas * sizeof(int));
            char linha1[100];

            for (int i = 0; i < colunas; i++) {
                if(fgets(linha1, sizeof(linha1), arquivo) != NULL) {
                    sscanf(linha1, "%d", &auxLinhas);
                    if(auxLinhas > maxLinhas){
                        maxLinhas = auxLinhas;
                    }
                    primeiroNumero1[i] = auxLinhas;
                }
            }

            /*printf("Valores do primeiro número de cada linha do bloco 2:\n");
            for (int i = 0; i < colunas; i++) {
                printf("%d ", primeiroNumero1[i]);
            }
            printf("\n");*/
            //printf("Maior valor para o numero de linhas da Matriz de instrucoes acima: %d\n", maxLinhas);
            //printf("\n");
            free(primeiroNumero1); 
            
            

            //Aloca memoria para o tabuleiro.
            matrixTabuleiro = alocarMatrixTabuleiro(linhas, colunas);
            //Aloca memoria para as matrizes de instrucoes.
            matrixRegrasLinhas = alocarInstrucoesLaterais(maxColunas, linhas);
            matrixRegrasColunas = alocarInstrucoesAcima(colunas, maxLinhas);

            fseek(arquivo, 0, SEEK_SET); //Volta ao inicio do arquivo para colocar os valores nas matrizes.
            fscanf(arquivo, "%*d%*d"); //Pula os dois primeiros numeros.
            fseek(arquivo, 1, SEEK_CUR); //Pula o bloco
            
            //Vetor para armazenar os numeros das instrucoes.

            //int *vetor;
            vetor = malloc(linhas * sizeof(int));

            for(int i = 0; i < linhas; i++){
                fscanf(arquivo, "%d", &vetor[i]); 
                //Armazena o numero de numeros que vai haver na instrucao
                //lateral, para depois, usar esse numero para ler a quantidade de numeros naquela linha.
                for(int j=0; j<vetor[i]; j++){
                    fscanf(arquivo, "%d", &matrixRegrasLinhas[i][j]);
                }
            }


            fseek(arquivo, 1, SEEK_CUR);//Pula o bloco.

            
            //Vetor para armazenar os numeros das instrucoes.


            //int *vetor2;
            vetor2 = malloc(colunas * sizeof(int));
            for(int i = 0; i < colunas; i++){
                fscanf(arquivo, "%d", &vetor2[i]); 

                //Armazena o numero de numeros que vai haver na instrucao
                //lateral, para depois, usar esse numero para ler a quantidade de numeros naquela linha.

                for(int j=0; j<vetor2[i]; j++){
                    fscanf(arquivo, "%d", &matrixRegrasColunas[i][j]);
                }
            }

           /*
            printf("\n");
            for(int i=0; i<colunas; i++){
                for(int j=0; j<vetor2[i]; j++){
                    printf("%d ", matrixRegrasColunas[j][i]);
                }
                printf("\n");
            } */ //Para printar a matriz das regras acima, eh necessario que, o uso de uma logica diferente, devido
            // a sua formatacao.



            fseek(arquivo,0, SEEK_SET); //Volta ao inicio do arquivo novamente para a leitura da matriz principal.
            fscanf(arquivo, "%*d%*d"); //Pula os dois primeiros numeros.
            
            
            // Pula os números antes da matriz principal.
            for (int i = 0; i < linhas; i++){
                for (int j = 0; j < colunas; j++){
                    char temp;
                    // Pula os números antes de cada caractere na matriz principal.
                    while (fscanf(arquivo, " %c", &temp) == 1 && temp != '.') {
                        //Continua lendo enquanto não encontrar o caractere '.'.
                        //Isso ignora qualquer outro caractere diferente de '.'.
                    } 
                    matrixTabuleiro[i][j] = temp; //Armazena na matriz os dados lidos na variavel temporaria.
                }
            }

            fclose(arquivo); //Fecha o arquivo.
        }
        //Caso o arquivo .txt for NULL, imprimimos uma mensagem de erro e retornamos 1.
        else{
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }
    //Caso a passagem de argumentos for incorreta, imprimimos uma mensagem falando que
    //o programa foi passado como parametro, porem, o arquivo .txt, nao. 
    else{
        printf("Uso: %s, porém, não há arquivo.txt\n", argv[0]);
        return 1; 
    }
    
    //Interacao com o usuario e recebimento de comandos.

    printf(BOLD(CYAN("Bem vindo ao Nonograma!\n")));
    printf("\n");

    printf(BOLD(MAGENTA("--------------------------------------------------------------------------------------------------------\n")));
    printf("COMANDO         ARGUMENTO         RESULTADO\n");
    printf("X                AC               Preenche a célula da linha A e coluna C com um 'x'\n");
    printf("-                EC               Preenche a célula da linha E e coluna C com um '-'.\n");
    printf(".                BA               Limpa a célula da linha B e coluna A.\n");
    printf("resolver                          Resolve o Nonograma e marca automaticamente as células com 'x' ou '-'.\n");
    printf("salvar           out.txt          Salva o Nonograma tal como está no momento no arquivo 'out.txt'.\n");
    printf("sair                              Encerra o programa (sem salvar as últimas alterações).\n");
    printf(BOLD(MAGENTA("--------------------------------------------------------------------------------------------------------\n")));

    
    


    char comando[26];//Variavel que recebera o comando do usuario, 27 de tamanho, 1 para o '\0' e 1 para 
    //'n', totalizando para o usuario o total de 25 caracteres.

    //Exibe o nonograma para o usuario.
    exibirNonograma(matrixTabuleiro, matrixRegrasLinhas, matrixRegrasColunas, linhas, colunas, maxLinhas, maxColunas);


    while(1){
        //Variavel que recebera o comando do usuario, 27 de tamanho, 1 para o '\0' e 1 para 
        //'n', totalizando para o usuario o total de 25 caracteres.
        printf(BOLD(CYAN("\nDigite um comando: ")));
        fgets(comando, 25, stdin);//Armazena o comando. 

        //Remove o "\n" no final da string, posicionado automaticamente pelo fgets e substitui pelo '\0'(final da string).
        comando[strcspn(comando, "\n")] = '\0';

        //Deixa todas as letras minusculas para facilitar a manipulacao.
        for(int i=0; i<strlen(comando); i++){
            comando[i] = tolower(comando[i]);
        }


        char caractere; //Criando uma variavel para armazenar o comando retirado da string,
        //e nos auxiliar na demarcacao da matriz.
        caractere = comando[0];

        char nomeArquivo[50];


        //Caso o comando, seja sair, a funcao sair sera aplicada.
        if(strcmp(comando, "sair") == 0){
            sair(matrixTabuleiro, linhas, matrixRegrasLinhas,matrixRegrasColunas, maxLinhas);
        }
        else if(strcmp(comando, "resolver") == 0){
            printf("\n");
            printf("Perdeu, Playboy! Muito difícil para você, né? Infelizmente, a função 'resolver' do jogo ainda está em desenvolvimento. Vai tentando aí, sabichão...\n");
        }


        //Caso receba o caractere '-' como primeiro caractere.
        else if(caractere == '-'){
            char letraUm = comando[2];
            char letraDois = comando[3];
            marcarComTraco(matrixTabuleiro, letraUm, letraDois);
            //printf("\ec\e[3j");
            exibirNonograma(matrixTabuleiro, matrixRegrasLinhas, matrixRegrasColunas, linhas, colunas, maxLinhas, maxColunas);
            printf("\n");
        }

        //Caso receba o caractere 'x' como primeiro caractere.
        else if(caractere == 'x'){
            char letraUm = comando[2];
            char letraDois = comando[3];
            marcarComX(matrixTabuleiro, letraUm, letraDois);
            exibirNonograma(matrixTabuleiro, matrixRegrasLinhas, matrixRegrasColunas, linhas, colunas, maxLinhas, maxColunas);
            printf("\n");
        }

        //Caso receba o caractere '.' como primeiro caractere.
        else if(caractere == '.'){
            char letraUm = comando[2];
            char letraDois = comando[3];
            marcarComPonto(matrixTabuleiro, letraUm, letraDois);
            exibirNonograma(matrixTabuleiro, matrixRegrasLinhas, matrixRegrasColunas, linhas, colunas, maxLinhas, maxColunas);
            printf("\n");
        }

        else if(strcmp(comando, "salvar") == 0){
            //Pega o nome do arquivo .txt.
            printf(BOLD(CYAN("\nDigite o nome do arquivo(sem espaços).txt: ")));
            fgets(nomeArquivo, sizeof(nomeArquivo), stdin);

            //Remover '\n'.
            nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
            FILE *arquivo1 = fopen(nomeArquivo, "w");
            if(arquivo1==NULL){
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            
            //Salva o numero de linhas e colunas do jogo.
            fprintf(arquivo1, "%d %d", linhas, colunas);
            fprintf(arquivo1, "\n");
            fprintf(arquivo1, "\n");

            //Salva o primeiro bloco de dados
            for(int i=0; i<linhas; i++){
                fprintf(arquivo1, "%d ", vetor[i]);
                for(int j=0; j<vetor[i]; j++){
                    fprintf(arquivo1, "%d ", matrixRegrasLinhas[i][j]);
                }
                fprintf(arquivo1, "\n");
            }


            fprintf(arquivo1, "\n");

            //Salva o segundo bloco de dados.
            for(int i=0; i<colunas; i++){
                fprintf(arquivo1, "%d ", vetor2[i]);
                for(int j=0; j<vetor2[i]; j++){
                    fprintf(arquivo1,"%d ", matrixRegrasColunas[i][j]);
                }
                fprintf(arquivo1, "\n");
            }


            fprintf(arquivo1, "\n");

            //Salva a matrix do tabuleiro.
            for(int i=0; i<linhas; i++){
                for(int j=0; j<colunas; j++){
                    fprintf(arquivo1, "%c ", matrixTabuleiro[i][j]);
                }
                fprintf(arquivo1, "\n");
            }

            fclose(arquivo1); //Fecha o arquivo usado para salvar o jogo.

        }

        else{
            printf("\n");
            printf("ERRO: Comando inválido! Parece que alguém tentou desbloquear o Xadrez 2. Calma lá, logo lançaremos, mas não aqui!\n");
            continue;
        }
    }

    return 0;// Final da funcao main.
}







