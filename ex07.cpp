#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10

int main()
{
    int vector1[SIZE], vector2[SIZE];
    int sum = 0;
    long long product = 1;

    for (int i = 0; i < SIZE; i++)
    {
        vector1[i] = rand() % 10 + 1; // Valores entre 1 e 10
        vector2[i] = rand() % 10 + 1; // Valores entre 1 e 10
    }

    printf("Vector1: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", vector1[i]);
    }
    printf("\n");

    printf("Vector2: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", vector2[i]);
    }
    printf("\n");

#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 0; i < SIZE; i++)
            {
                sum += vector1[i];
            }
            printf("Sum of vector1 elements: %d\n", sum);
        }

#pragma omp section
        {
            for (int i = 0; i < SIZE; i++)
            {
                product *= vector2[i];
            }
            printf("Product of vector2 elements: %lld\n", product);
        }
    }

    return 0;
}
