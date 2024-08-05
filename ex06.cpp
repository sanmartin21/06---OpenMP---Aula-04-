#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize_random_generator()
{
    srand(time(NULL));
}

int main()
{
    int matrix[ROWS][COLS];

    omp_set_num_threads(4);

#pragma omp parallel
    {
#pragma omp single
        {
            initialize_random_generator();
        }

#pragma omp for
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                matrix[i][j] = rand() % 100; // Valores aleatórios entre 0 e 99
            }
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
