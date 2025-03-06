#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void imprimeTabuleiro(int tabuleiro[10][10]){
    printf("   A B C D E F G H I J\n\n");
    for(int i=0;i<10;i++){
            printf("%d  ",i);
        for(int j=0;j<10;j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}
//h1,2 v0,3
int vereficaSobreposicao(int navioH[2],int navioV[2],int tamanhoH,int tamanhoV){
    for(int i = 0;i<tamanhoH;i++){
        if(navioH[1]+i == navioV[1]){
            for(int j =0; j<tamanhoV;j++){
                if(navioH[0] == navioV[0]+j){
                    return 1;
                }
            }
        }
    }
return 0;
}

int main() {
    //inicializa tabuleiro com 0
    int tabuleiro[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tabuleiro[i][j] = 0;
        }
    }
    int navioH[2]={0,1}, navioV[2]={1,6}, tamanhoH=3, tamanhoV=3; //navio[linha da posição inicial][coluna da posição inicial]

    if(navioH[1]+tamanhoH>9 || navioV[0]+tamanhoV>9 || vereficaSobreposicao(navioH,navioV,tamanhoH,tamanhoV)){
        printf("Posicao invalida do navio\n");
    }else{
        for(int i = 0;i<tamanhoH;i++){ //coloca os navio no tabuleiro
            tabuleiro[navioH[0]][navioH[1]+i] = 3;
        }
        for(int i = 0;i<tamanhoV;i++){
            tabuleiro[navioV[0]+i][navioV[1]] = 3;
        }
        imprimeTabuleiro(tabuleiro);
    }



    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
