#include "matriz.hpp"

void LeituraMatriz(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final){

    ifstream arq;

    arq.open("Matriz.txt");

    int a = 0;
    string linha;
    int cont = 0;
    int numero_elementos = (i_final - i_inicial + 1) * (j_final - j_inicial + 1), vetor[numero_elementos], aux = 0;

    if(arq.is_open()){
        for(int i = 0; i < i_inicial - 1; i++){
            getline(arq, linha);
        }

            while(!arq.eof()){
                while(getline(arq, linha, ' ') && cont < numero_elementos){
                    aux++;

                    if(aux >= j_inicial && aux <= j_final){
                        vetor[a] = stoi(linha);
                        a++;
                        cont++;
                    }

                        if(aux >= 10){
                            aux = 0;
                        }
                }
            }
    }

    int linhas = i_final - (i_inicial - 1);
    int colunas = j_final - (j_inicial - 1);
    int matriz[linhas][colunas];

    int k = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = vetor[k];
            mat->matriz[i][j] = matriz[i][j];
            k++;
        }
    }

    arq.close();

}

void CriaTransp(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final){

    int linhas = i_final - (i_inicial - 1);
    int colunas = j_final - (j_inicial - 1);

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            mat->transposta[j][i] = mat->matriz[i][j];
        }
    }
}

void CriaMultiplicada(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final, unordered_map<string, int**> *hash, string chave){

    int linhas = i_final - (i_inicial - 1);
    int colunas = j_final - (j_inicial - 1);

    int** multiplicada = 0;
    multiplicada = new int * [linhas];
    mat->multiplicada = new int * [linhas];
    int soma;

    for(int i = 0; i < linhas; i++){
        multiplicada[i] = new int[linhas];
        mat->multiplicada[i] = new int[linhas];
        for(int j = 0; j < linhas; j++){
            soma = 0;
            for(int k = 0; k < colunas; k++){
                soma += mat->matriz[i][k] * mat->transposta[k][j];
            }
            multiplicada[i][j] = soma;
            mat->multiplicada[i][j] = soma;
        }
    }

    hash->emplace(chave, multiplicada);
}

void Imprimi(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final){

    int linhas = i_final - (i_inicial - 1);
    int colunas = j_final - (j_inicial - 1);
    
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|------------------IMPRIMINDO-A-MATRIZ-RECORTADA-----------------|" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mat->matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|------------------IMPRIMINDO A MATRIZ TRANSPOSTA----------------|" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mat->transposta[i][j] << " ";
        }
        cout << endl;
    }
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|------IMPRIMINDO A [MATRIZ RECORTADA] x [MATRIZ TRANSPOSTA]-----|" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mat->multiplicada[i][j] << " ";
        }
        cout << endl;
    }
    cout << "|----------------------------------------------------------------|" << endl;
}

