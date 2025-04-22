#include <stdio.h>

/*
 *Você foi contratado para fazer um programa para calcular os dois dígitos verificadores
do número de Registro Individual (RI) de uma empresa. Seu programa deve ler um número RI
constituído por 9 dígitos. A leitura deve ser feita em uma única variável (do tipo inteiro ou inteiro
longo), não podendo ser usado um vetor, o que ocasionará a necessidade de uma quantidade
grande variáveis. Na sequência, seu programa deve calcular os dois dígitos verificadores do
número RI. Para tanto, o número RI deve ser desmembrado em 9 algarismos de 1 dígito cada.
Ao final, seu programa deve imprimir o RI contendo o dígito verificador.

 *
 */


int main() {

    long int ri;
    int a1, a2, a3, a4, a5, a6, a7 , a8 , a9;
    int soma1, soma2, div, div2;

        printf("Digite um numero RI (9 digitos): ");
        scanf("%ld", &ri);

            a1 = ri / 100000000;
            a2 = (ri / 10000000) % 10;
            a3 = (ri / 1000000) % 10;
            a4 = (ri / 100000) % 10;
            a5 = (ri / 10000) % 10;
            a6 = (ri / 1000) % 10;
            a7 = (ri / 100) % 10;
            a8 = (ri / 10) % 10;
            a9 = ri % 10;


        soma1 = a1 * 1 + 2 *a2 + 3 *a3 + 4 *a4 + 5 *a5 + 6 * a6 + 7 * a7 + 8 * a8 + 9 * a9;

        div = soma1 % 11;

        if (div == 10)
            div = 0;

        soma2 = a1 * 0 + a2 * 1 + a3 * 2 + a4 * 3 + a5 * 4 + a6 * 5 + a7 * 6 + a8 * 7 + a9 * 8 + div * 9;

        div2 = soma2 % 11;
        
        if (div2 == 10)
            div2 = 0;

        printf("Código do RI: %ld/%d%d", ri , div ,div2);

}