#include <iostream>
#include <queue>

using namespace std;

#define MAX 55

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
    char contaminado = 'T';
    char rocha = 'X';
    pair<int,int> coordenada;
    coordenada.first = i;
    coordenada.second = j;
    queue<pair<int,int> > coordinateQueue;
    coordinateQueue.push(coordenada);
    matriz[i][j] = contaminado;

    while(!coordinateQueue.empty()){
        
        coordenada = coordinateQueue.front();
        coordinateQueue.pop();
        for(int k=0; k < 4; k++){
            int vizinhoX = vizinhosXaxys[k]+coordenada.first;
            int vizinhoY = vizinhosYaxys[k]+coordenada.second;
            //verificando se o vizinho esta nos limites da matriz
            if(vizinhoX >= 0 && vizinhoX < linhas && vizinhoY >= 0 && vizinhoY < colunas){
                if(matriz[vizinhoX][vizinhoY] != contaminado && matriz[vizinhoX][vizinhoY] != rocha){
                    coordinateQueue.push({vizinhoX,vizinhoY});
                    matriz[vizinhoX][vizinhoY] = contaminado;
                }
            }
        }
    }

}

int main(){

    int linhas, colunas;

    cin >> linhas >> colunas;

    while(linhas != 0 && colunas != 0){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                cin >> matriz[i][j];
            }
        }

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if(matriz[i][j] == 'T'){
                    BFS(i,j,linhas,colunas);
                }
            }
        }

        printMatriz(linhas,colunas);
        cin >> linhas >> colunas;
    }
    
    return 0;
}