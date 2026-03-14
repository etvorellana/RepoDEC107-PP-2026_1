#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500

int leiaMatriz(double M[N][N], char *fileName)
{
    // qui devemos implementar uma leitura de arquivo mas
    // vamos simplificar e preencher a matriz com valores aleatórios
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)        {
            M[i][j] = (double)rand()/RAND_MAX; // valores aleatórios entre 0 e 1
        }
    }
    return 0;
}

int multiplicaMatrizes(double A[N][N], double B[N][N], double C[N][N], double alpha, double beta)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double soma = 0;
            for (int k = 0; k < N; k++)
            {
                soma += A[i][k] * B[k][j];
            }
            C[i][j] = beta * C[i][j] + alpha * soma;
        }
    }
    return 0;
}

int printMatrix(double M[N][N], int mSize)
{
    // qui devemos implementar uma escrita de arquivo mas
    // vamos simplificar e imprimir apenas o primeiro elemento
    printf("Primeiro elemento da matriz: %f\n", M[0][0]);
    return 0;
}

int main(void)
{

    // Declarando As variáveis
    double A[N][N], B[N][N], C[N][N];
    double alpha, beta;
    char filaNameA[100], filaNameB[100], fileNameC[100];

    // Entrada de dados
    strcpy(filaNameA, "matrizA.txt");
    strcpy(filaNameB, "matrizB.txt");
    strcpy(fileNameC, "matrizC.txt");
    leiaMatriz(A, filaNameA);
    //printMatrix(A, N);
    leiaMatriz(B, filaNameB);
    //printMatrix(B, N);
    leiaMatriz(C, fileNameC);
    //printMatrix(C, N);
    alpha = 1.0;
    beta = 0.0;

    // processamento
    multiplicaMatrizes(A, B, C, alpha, beta);
    
    // Saída de resultados
    //printMatrix(C, N);
    return 0;
}