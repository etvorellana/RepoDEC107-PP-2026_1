#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2048

double* alocaMatriz(int m, int n)
{
    double* A;
    A = (double*) malloc(m*n*sizeof(double));
    return A;
} 

double* leiaMatriz(char *fileName)
{
    // qui devemos implementar uma leitura de arquivo mas
    // vamos simplificar e preencher a matriz com valores aleatórios
    double* M; 
    M = alocaMatriz(N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)        {
            M[i*N+j] = (double)rand()/RAND_MAX; // valores aleatórios entre 0 e 1
        }
    }
    return M;
}

int multiplicaMatrizes(double *A, double *B, double *C, double alpha, double beta)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double soma = 0;
            for (int k = 0; k < N; k++)
            {
                soma += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = beta * C[i*N + j] + alpha * soma;
        }
    }
    return 0;
}

int printMatrix(double *M, int mSize)
{
    // qui devemos implementar uma escrita de arquivo mas
    // vamos simplificar e imprimir apenas o primeiro elemento
    printf("Primeiro elemento da matriz: %f\n", M[0]);
    return 0;
}

int main(void)
{

    // Declarando As variáveis
    double *A, *B, *C;
    double alpha, beta;
    char filaNameA[100], filaNameB[100], fileNameC[100];



    // Entrada de dados
    strcpy(filaNameA, "matrizA.txt");
    strcpy(filaNameB, "matrizB.txt");
    strcpy(fileNameC, "matrizC.txt");
    A = leiaMatriz(filaNameA);
    printMatrix(A, N);
    B = leiaMatriz(filaNameB);
    printMatrix(B, N);
    C = leiaMatriz(fileNameC);
    printMatrix(C, N);
    alpha = 1.0;
    beta = -1.0;

    // processamento
    multiplicaMatrizes(A, B, C, alpha, beta);
    
    // Saída de resultados
    printMatrix(C, N);
    free(A);
    free(B);
    free(C);
    return 0;
}