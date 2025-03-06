#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void imprimeTabuleiro(int tabuleiro[10][10]){
    printf("   0 1 2 3 4 5 6 7 8 9\n\n");
    for(int i=0;i<10;i++){
            printf("%d  ",i);
        for(int j=0;j<10;j++){
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificaHH(int h1[2],int h2[2],int th1, int th2){//verifica se 2 navios na horizontal se sobrepoem
    if(h1[0] != h2[0]){//se não estiver na mesma linha não se sobrepoem
        return 0;
    }
    for(int i=0;i<th1;i++){ //verifica se eles se sobrepoem ao estar na mesma linha
        if(h1[1]+i == h2[1]){
            return 1;
        }
    }
    for(int i=0;i<th2;i++){//verifica se eles se sobrepoem ao estar na mesma linha
        if(h2[1]+i == h1[1]){
            return 1;
        }
    }
    return 0;
}

int verificaVV(int v1[2],int v2[2],int tv1, int tv2){
    if(v1[1] != v2[1]){
        return 0;
    }
    for(int i=0;i<tv1;i++){
        if(v1[0]+i == v2[0]){
            return 1;
        }
    }
    for(int i=0;i<tv2;i++){
        if(v2[0]+i == v1[0]){
            return 1;
        }
    }
    return 0;
}

int verificaHV(int h[2],int v[2],int th,int tv){//verifica se um navio na horizontal e um na vertical se sobrepoem
    for(int i = 0;i<th;i++){//passa pelas colunas do navio na horizontal
        if(h[1]+i == v[1]){ //verifica se o navio da horizontal e da vertical compartilham uma coluna
            for(int j =0; j<tv;j++){//passa pelas linhas do navio na vertical
                if(h[0] == v[0]+j){//verifica se os navios compartilham a mesma linha
                    return 1; //se sobrepoem
                }
            }
        }
    }
return 0;//não se sobrepoem
}

int verificaDD(int d1[2],int d2[2],int td1,int td2){//verifica os navios da diagonal se sobrepoem
    for(int i=0;i<td1;i++){//passa pelo navio1
        for(int j=0;j<td2;j++){// passa pelo navio2
            if(d1[0]+i == d2[0]+j && d1[1]+i == d2[1]-j){//verifica se a posição se sobrepoe
                return 1;
            }
        }
    }
    return 0;
}

int verificaHD1(int h[2], int d[2], int th, int td){//verifica se um navio horizontal se sobrepoe ao navio da diagonal 1
    for(int i = 0; i<th;i++){//passa pelo navio horizontal
        for(int j =0; j<td;j++){//passa pelo navio diagonal
            if(h[0] == d[0]+j && h[1]+i == d[1]+j){//verifica se a posição se sobrepoe
                return 1;
            }
        }
    }
    return 0;
}

int verificaHD2(int h[2], int d[2], int th, int td){//verifica se um navio horizontal se sobrepoe ao navio da diagonal 2
    for(int i = 0; i<th;i++){//passa pelo navio horizontal
        for(int j =0; j<td;j++){//passa pelo navio diagonal
            if(h[0] == d[0]+j && h[1]+i == d[1]-j){//verifica se a posição se sobrepoe
                return 1;
            }
        }
    }
    return 0;
}

int verificaVD1(int v[2], int d[2], int tv, int td){//verifica se um navio vertical se sobrepoe ao navio da diagonal 1
    for(int i = 0; i<tv;i++){//passa pelo navio vertical
        for(int j =0; j<td;j++){//passa pelo navio diagonal
            if(v[0]+i == d[0]+j && v[1] == d[1]+j){//verifica se a posição se sobrepoe
                return 1;
            }
        }
    }
    return 0;
}

int verificaVD2(int v[2], int d[2], int tv, int td){//verifica se um navio vertical se sobrepoe ao navio da diagonal 2
    for(int i = 0; i<tv;i++){//passa pelo navio vertical
        for(int j =0; j<td;j++){//passa pelo navio diagonal
            if(v[0]+i == d[0]+j && v[1] == d[1]-j){//verifica se a posição se sobrepoe
                return 1;
            }
        }
    }
    return 0;
}

int verificaPosicao(int h1[2],int h2[2],int v1[2],int v2[2],int d1[2],int d2[2],int th1,int th2,int tv1,int tv2,int td1,int td2){//verifica se os navios estão em posição válida
    //verifica se algum navio sai do tabuleiro
    if(h1[1]+th1-1>9 || h2[1]+th2>9 || v1[0]+tv1-1>9 || v2[0]+tv2-1>9 || d1[0]+td1-1>9 || d1[1]+td1-1>9 || d2[0]+td2-1>9 || d2[1]-td2+1<0){
        return 1;
    }
    //verifica a sobreposição dos navios
    if(verificaHH(h1,h2,th1,th2) || verificaVV(v1,v2,tv1,tv2) || verificaDD(d1,d2,td1,td2) || verificaHD1(h1,d1,th1,td1) || verificaHD1(h2,d1,th2,td1) || verificaHD2 (h1,d2,th1,td2) || verificaHD2(h2,d2,th2,td2) || verificaVD1(v1,d1,tv1,td1) || verificaVD1(v2,d1,tv2,td1) || verificaVD2(v1,d2,tv1,tv2) || verificaVD2(v2,d2,tv2,td2) || verificaHV(h1,v1,th1,tv1) || verificaHV(h1,v2,th1,tv2) || verificaHV(h2,v1,th2,tv1) || verificaHV(h2,v2,th2,tv2)){
        return 1;
    }
    return 0;

    if(vereficaHH(h1,h2,th1,th2) || vereficaVV(v1,v2,tv1,tv2) || vereficaHV(h1,v1,th1,tv1) || vereficaHV(h1,v2,th1,tv2) || vereficaHV(h2,v1,th2,tv1) || vereficaHV(h2,v2,th2,tv2)){
        return 0;
    }
    return 1;
}

int main() {
    //inicializa tabuleiro com 0
    int tabuleiro[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tabuleiro[i][j] = 0;
        }
    }
    //inicializa navios
    int navioH1[2]={9,7}, navioH2[2] = {2,5}, navioV1[2]={3,9},navioV2[2] = {7,0}, navioD1[2] = {3,3}, navioD2[2] = {0,2},tamanhoH1=3, tamanhoH2=3, tamanhoV1=3,tamanhoV2=3,tamanhoD1=3,tamanhoD2=3; //navio[linha da posição inicial][coluna da posição inicial]

    //verifica se as posições são validas
    if(verificaPosicao(navioH1,navioH2,navioV1,navioV2,navioD1,navioD2,tamanhoH1,tamanhoH2,tamanhoV1,tamanhoV2,tamanhoD1,tamanhoD2)){
        printf("Posicao invalida do navio\n");
    }else{
        //coloca os navio no tabuleiro se as posições forem válidas
        for(int i = 0;i<tamanhoH1;i++){
            tabuleiro[navioH1[0]][navioH1[1]+i] = 3;
        }
        for(int i = 0;i<tamanhoH2;i++){
            tabuleiro[navioH2[0]][navioH2[1]+i] = 3;
        }
        for(int i = 0;i<tamanhoV1;i++){
            tabuleiro[navioV1[0]+i][navioV1[1]] = 3;
        }
        for(int i = 0;i<tamanhoV2;i++){
            tabuleiro[navioV2[0]+i][navioV2[1]] = 3;
        }
        for(int i=0;i<tamanhoD1;i++){
            tabuleiro[navioD1[0]+i][navioD1[1]+i] = 3;
        }
        for(int i=0;i<tamanhoD2;i++){
            tabuleiro[navioD2[0]+i][navioD2[1]-i] = 3;
        }
        imprimeTabuleiro(tabuleiro);
    }
    return 0;
}
