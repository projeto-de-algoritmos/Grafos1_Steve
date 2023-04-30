#include <iostream>
#include <queue>

using namespace std;

#define MAX 1025

//Grafo representado por uma matriz
char matriz[MAX][MAX];
int vizinhosXaxys[4] = {1,-1,0,0};
int vizinhosYaxys[4] = {0,0,-1,1}; 

void printMatriz(int linhas,int colunas){
     for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }
    cout <<endl;
}

void BFS(int i, int j, int linhas, int colunas){

    //coordenada representado por par de int, "x"(linha) e "y"(coluna) respectivamente.
    char visitado = 'o';
    pair<int,int> pixel;
    pixel.first = i;
    pixel.second = j;
    queue<pair<int,int> > pixelQueue;
    pixelQueue.push(pixel);
    matriz[i][j] = visitado;

    while(!pixelQueue.empty()){
        
        pixel = pixelQueue.front();
        pixelQueue.pop();
        for(int k=0; k < 4; k++){
            int vizinhoX = vizinhosXaxys[k]+pixel.first;
            int vizinhoY = vizinhosYaxys[k]+pixel.second;
            //verificando se o vizinho esta nos limites da matriz
            if(vizinhoX >= 0 && vizinhoX < linhas && vizinhoY >= 0 && vizinhoY < colunas){
                if(matriz[vizinhoX][vizinhoY] != visitado){
                    pixelQueue.push({vizinhoX,vizinhoY});
                    matriz[vizinhoX][vizinhoY] = visitado;
                }
            }
        }
    }

}

int main(){

    int linhas, colunas, clicks = 0;

    cin >> linhas >> colunas;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cin >> matriz[i][j];
        }
    }

    cout << endl;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j] != 'o'){
                BFS(i,j,linhas,colunas);
                printMatriz(linhas,colunas);
                clicks++;
            }
        }
    }

    cout << clicks << endl;
    return 0;
}