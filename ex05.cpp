#include <omp.h>
#include <stdio.h>

int main() {
    // Exemplo de vetor
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(int);
    int soma_total = 0;

    // Diretiva para paralelizar o loop e realizar a redução da soma
    #pragma omp parallel for reduction(+:soma_total)
    for(int i = 0; i < tamanho; i++) {
        soma_total += vetor[i];
    }

    printf("A soma total do vetor é: %d\n", soma_total);

    return 0;
}
