#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAXTAM 100

typedef struct Matriz Matriz;

struct Matriz{
	int i_inicial, i_final, j_inicial, j_final;
	int matriz[MAXTAM][MAXTAM];
	int transposta[MAXTAM][MAXTAM];
	int** multiplicada;
};

void LeituraMatriz(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final);

void CriaTransp(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final);

void CriaMultiplicada(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final, unordered_map<string, int**> *hash, string chave);

void Imprimi(Matriz *mat, int i_inicial, int i_final, int j_inicial, int j_final);

#endif