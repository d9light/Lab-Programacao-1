#include <stdio.h>

/*
*Gere e escreva os números ímpares dentro de um intervalo digitado
pelo usuário. O programa deve exibir também a soma destes
números.
 *
 */

int main() {

    int n = 0, m = 0 ;
    int soma = 0;

    printf("Digite aonde comeca o intevalo:\n");
    scanf("%d", &n);

    printf("Digite aonde acaba o intevalo:\n");
    scanf("%d", &m);

    for (int i = n; i <= m; i++) {
        if (i % 2 != 0) {
            printf("Numeros Impares:%d\n", i);
            soma = soma + i;
        }

    }
        printf("Soma = %d\n", soma);
}
