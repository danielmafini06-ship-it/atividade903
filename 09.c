#include <stdio.h>

int chamadas = 0;
int comparacoes = 0;

void quicksort(int vetor[], int inicio, int fim) {
    chamadas++;
    if (inicio < fim) {
        int pivo = vetor[fim];
        int i = (inicio - 1);
        for (int j = inicio; j < fim; j++) {
            comparacoes++;
            if (vetor[j] <= pivo) {
                i++;
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
        int temp = vetor[i + 1];
        vetor[i + 1] = vetor[fim];
        vetor[fim] = temp;
        int pi = i + 1;
        quicksort(vetor, inicio, pi - 1);
        quicksort(vetor, pi + 1, fim);
    }
}
int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    quicksort(vetor, 0, n - 1);
    printf("Chamadas recursivas: %d\n", chamadas);
    printf("Comparacoes: %d\n", comparacoes);

    return 0;
}
