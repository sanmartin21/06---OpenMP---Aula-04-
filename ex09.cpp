#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100
#define TARGET 42

int main()
{
    int array[SIZE];
    int pos = -1;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
    }

    printf("Vetor:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    omp_set_num_threads(4);

#pragma omp parallel shared(pos)
    {
#pragma omp for
        for (int i = 0; i < SIZE; i++)
        {
            if (array[i] == TARGET)
            {
#pragma omp critical
                {
                    if (pos == -1)
                    {
                        pos = i;
                    }
                }
            }
        }

#pragma omp single
        {
            if (pos != -1)
            {
                printf("Valor %d encontrado na posição %d\n", TARGET, pos);
            }
            else
            {
                printf("Valor %d não encontrado no vetor\n", TARGET);
            }
        }
    }

    return 0;
}
