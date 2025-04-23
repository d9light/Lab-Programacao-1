#include <stdio.h>

/*
2) Leia 20 valores, encontre e escreva o maior deles.

 *
 */

int main() {

    int n = 0;
    int maior = 0;

    printf("Digite 20 numeros, para retornar o maior:\n");

    for (int i = 0; i < 20; i++) {
      scanf("%d", &n);

        if (n > maior) {
            maior = n;
        }
}
    printf("Maior: %d", maior);
}
