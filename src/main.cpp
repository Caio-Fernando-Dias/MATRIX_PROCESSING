#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Criar uma matriz transposta
/*void CriaTransp(int linhas, int colunas, int matriz[?][?], int transposta[?][?]){
  
}

//Cria uma rotina que multiplique duas matrizes
void Multiplica(int linhas, int colunas, int matriz[?][?], int transposta[?][?], int matrizmult[?][?]){

}*/

int main(){

    ifstream arq;

    int i_inicial, i_final, j_inicial, j_final;


    //LEITURA DE COORDENADAS ONDE DEVE SER FEITO EM UM ARQUIVO TXT !!!!RESOLVER!!!!!

    cout << "Insert the  I inicial and the I final -> ";
    cin >> i_inicial >> i_final;

    cout << "Insert the J inicial and the J final -> ";
    cin >> j_inicial >> j_final;

    cout << endl;

    int cont = 0, numero_elementos = (i_final - i_inicial + 1) * (j_final - j_inicial + 1), aux[numero_elementos], j_coord = 0;
    string linha;

    arq.open("Matriz.txt");

    int a = 0;


    //LEITURA DE LINHA, RECORTANDO MATRIZ E TRANSFORMANDO UMA STRING PARA UM VETOR DE INTEIROS

    if(arq.is_open()){
        for(int i = 0; i < i_inicial - 1; i++){
            getline(arq, linha);
        }

            while(!arq.eof()){
                while(getline(arq, linha, ' ') && cont < numero_elementos){
                    j_coord++;

                    if(j_coord >= j_inicial && j_coord <= j_final){
                        aux[a] = stoi(linha);
                        a++;
                        cont++;
                    }

                        if(j_coord >= 10){
                            j_coord = 0;
                        }
                }
            }
    }

    //TRANSFORMANDO VETOR DE INTEIRO PARA UMA MATRIZ

    int linhas = i_final - (i_inicial - 1);
    int colunas = j_final - (j_inicial - 1);
    int matriz[linhas][colunas];

    int k = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = aux[k];
            k++;
        }
    }

    cout << "IMPRIMINDO A MATRIZ CORTADA" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    //CALCULANDO TRANSPOSTA DA MATRIZ RECORTADA

    int transposta[linhas][colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            transposta[j][i] = matriz[i][j];
        }
    }
    cout << endl;

    cout << "IMPRIMINDO A MATRIZ TRANSPOSTA" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << transposta[i][j] << " ";
        }
        cout << endl;
    }

    //MUTIPLICANDO A MATRIZ RECORTADA PELA A MATRIZ TRANSPOSTA

    int multiplicada[linhas][colunas];
    int teste;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++){

            multiplicada[i][j] = 0;
            for (int x = 0; x < linhas; x++){
                teste += matriz[i][x] * transposta[x][j];
            }

            multiplicada[i][j] = teste;
            teste = 0;
        }
    }
    cout << endl;

    cout << "IMPRIMINDO A MATRIZ CORTADA X MATRIZ TRANSPOSTA" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << multiplicada[i][j] << " ";
        }
        cout << endl;
    }


    //JOGANDO MATRIZ MUTIPLICADA DENTRO DE UMA HASH !!!!RESOLVER!!!!


    arq.close();

    /*
    4) - PASSAR COORDENADAS PARA ARQUIVO TXT
    5) - ARMAZENAR NA HASH
    6) - PASSAR PARA AQUIVOS CPP E HPP
    7) - README
    

    */

    return 0;
}