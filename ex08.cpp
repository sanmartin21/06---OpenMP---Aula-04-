#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 4

void multiplicacao_matrizes(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < SIZE / 2; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    C[i][j] = 0;
                    for (int k = 0; k < SIZE; k++)
                    {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }

#pragma omp section
        {
            for (int i = SIZE / 2; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    C[i][j] = 0;
                    for (int k = 0; k < SIZE; k++)
                    {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    // Inicializa as matrizes A e B com valores aleatórios
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Imprime a matriz A
    printf("Matriz A:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Imprime a matriz B
    printf("Matriz B:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Multiplica as matrizes A e B
    multiplicacao_matrizes(A, B, C);

    // Imprime a matriz resultante C
    printf("Matriz C (Resultante):\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}