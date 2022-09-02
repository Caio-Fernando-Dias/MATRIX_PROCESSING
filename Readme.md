# Processamento de matrizes por segmentação de arquivo	

<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>  
</a> 
</div>

<h2><a>Objetivo</a></h2>

<p>O objetivo proposto pelo trabalho é implementar um sistema de multiplicação de matrizes com base em uma estratégia de segmentação em arquivo. Sendo assim, ler à partir de documentos textos coordenadas para recortar uma matriz filha de uma matriz mãe na qual está em um documento txt. Após recortamos a matriz filha, calculamos sua transposta e por fim, multiplicamos a matriz filha recortada pela sua matriz originando uma terceira matriz que será armazenada em uma tabela hash.</p>

<h2><a>Explicando o código</a></h2>

<h2><a>Leitura</a></h2>

```c++
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
```

<p></p>

<h2><a>Transposta</a></h2>

```c++
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
```

<p></p>

<h2><a>Multiplicação</a></h2>

```c++
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
```

<p></p>

<h2><a>Armazenando na Hash</a></h2>

```c++

//JOGANDO MATRIZ MUTIPLICADA DENTRO DE UMA HASH !!!!RESOLVER!!!!


```
<p></p>


<h2><a>Compilando</a></h2>


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<h2><a>Dados</a></h2>

<p>Disciplina: Algoritmos e Estrutura De Dados II 2022-2

Aluno: Caio Fernando Dias

Professor: Michel Pires

Data: 02/09/2022</p>

<h2><a>Contato</a></h2>

<div> 
  <a href="https://www.instagram.com/caio_fer_dias/" target="_blank"><img src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank"></a>
  <a href = "mailto:caiodias200109@gmail.com"><img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank"></a>
  <a href="https://www.linkedin.com/in/caio-dias-8a4962246/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
  <a href="https://t.me/caio_fer_dias" target="_blank"><img src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"></a>
  <a href="https://www.facebook.com/caiofernando.dias.77"><img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white"></a>
  <a href="https://github.com/Caio-Fernando-Dias"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
</div>

