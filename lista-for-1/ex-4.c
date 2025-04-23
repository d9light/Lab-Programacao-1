#include <stdio.h>

int main() {
    int n, divisores = 0;

    printf("Digite um valor para ver se eh primo:\n");
    scanf("%d", &n);

    // Verifica se o número é menor que 2 (não é primo)
    if (n < 2) {
        printf("%d nao eh primo.\n", n);
        if (n > 0) {
            printf("Divisores: 1");
            if (n != 1) printf(", %d", n);
            printf("\n");
        }
        return 0;
    }

    // Verifica divisores
    printf("Divisores: 1");
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            printf(", %d", i);
            divisores++;
        }
    }
    printf(", %d\n", n);

    // Verifica se é primo (tem apenas 2 divisores: 1 e ele mesmo)
    if (divisores == 0) {
        printf("%d eh primo.\n", n);
    } else {
        printf("%d nao eh primo (tem %d divisores alem de 1 e ele mesmo).\n", n, divisores);
    }

}
