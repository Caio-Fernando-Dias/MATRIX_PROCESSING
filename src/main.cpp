#include "matriz.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    Matriz mat;

    unordered_map<string,int**> hash;
    int** aux;

    string chave;

    int i_i, i_f, j_i, j_f;

    while (true) {
        cout << "Insira o  I inicial e o I final -> ";
        cin >> i_i >> i_f;
        cout << "Insira o J inicial e o J final -> ";
        cin >> j_i >> j_f; 
        cout << endl;

        chave = to_string(i_i) + to_string(i_f) + to_string(j_i) + to_string(j_f);

        auto verificar = hash.find(chave);

        if(verificar != hash.end()){
            for (auto verificar_2: hash) {
                if (verificar_2.first == chave) {
                    aux = verificar_2.second;
                }

                for (int i = 0; i < (i_f - i_i + 1); i++) {
                    for (int j = 0; j < (j_f -j_i + 1); j++) {
                        cout << aux[i][j] << " ";
                    }

                    cout << endl;
                }
            }
        }else{
            cout << "|--------------SALVANDO--------------|" << endl << endl;
            LeituraMatriz(&mat, i_i, i_f, j_i, j_f);
            CriaTransp(&mat, i_i, i_f, j_i, j_f);
            CriaMultiplicada(&mat, i_i, i_f, j_i, j_f, &hash, chave);

            Imprimi(&mat, i_i, i_f, j_i, j_f);
        }
    }


    return 0;
}

/*
    ERRO NO CORTE DA MATRIZ NA LINHA 1 E COLUNA 1
    HASH TEM QUE SER FEITA
    LER COORDENADAS DO ARQUIVO

*/