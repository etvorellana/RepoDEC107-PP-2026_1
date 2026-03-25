#include <stdio.h>
#include <stdlib.h>

//Compilação Condicional
#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
  #define omp_get_num_threads() 1 
#endif
#define N 4096


int main(void)
{
    double **med, *medAvg;
    unsigned int *qmed;
    double start, stop;
    double max, min;

    med = (double**) malloc(N*sizeof(double*));
    qmed = (unsigned int*)malloc(N*sizeof(unsigned int));
    medAvg = (double*) malloc(N*sizeof(double));
    
    

    // carregar od dado
    start = omp_get_wtime();
    for(int i = 0; i < N; i++)
    {
        qmed[i] = 512 + rand()%(4096 - 512);
        med[i] = (double*)malloc(qmed[i]*sizeof(double));
        for(int j = 0; j < qmed[i]; j++)
        {
            med[i][j] = 15 + 20*(double)rand()/RAND_MAX;
        } 
    }
    stop = omp_get_wtime();
    printf("Tempo de carregamento de dados: %f\n", stop - start);

    // Processamento
    start = omp_get_wtime();
    #pragma omp parallel
    {
        max = 0;
        min = 35;
        #pragma omp for
        for(int i = 0; i < N; i++){
            double avg = 0;
            for(int j = 0; j < qmed[i]; j++)
            {
                if ((j > 0) && (j < (qmed[i] - 1)) && (i > 0) && (i < (N-1)))
                    med[i][j] = (med[i][j-1] + med[i][j] + med[i][j+1] + med[i-1][j] + med[i+1][j])/5;
                avg += med[i][j]/35;
                if(max < med[i][j])
                {
                    max = med[i][j];
                }else if(min < med[i][j]){
                    min = med[i][j];
                }
            }
            medAvg[i] = avg/qmed[i];
        }
    }
    stop = omp_get_wtime();
    printf("Tempo de processamento: %f\n", stop - start);

    // resultados
    start = omp_get_wtime();
    printf("medAvg[0] = %f\n", medAvg[0]);
    printf("medAvg[%d] = %f\n", N-1,medAvg[N-1]);
    printf("Valor máximo: %f\n", max);
    printf("Valor mínimo: %f\n", min);
    stop = omp_get_wtime();
    printf("Tempo de saída: %f\n", stop - start);
    free(medAvg);
    for(int i = 0; i < N; i++)
        free(med[i]);
    free(med);
    free(qmed);

    #pragma omp parallel num_threads(20)
    {
        int i = omp_get_thread_num();
        vet[i]*= 2;
    }
    
    return(0);
}

