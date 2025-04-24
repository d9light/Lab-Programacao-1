#include<stdio.h>
#include<math.h>
/*
5) Faça um programa que chame uma função que leia 20 números e imprima a
soma dos números cujos quadrados são menores que 225.

*/

int somasQuadrados(){

    int v, soma;
    soma = 0;
    printf("Digite 20 numeros:\n");

    for(int i = 0; i < 20 ; i++ ) {
        scanf("%d",& v);

        if (pow(v,2) < 225 ) {
            printf("O quadrado eh %2.f\n", pow(v,2));
            printf("O quadro eh menor que 255, o valor eh %d\n", v);
            soma = soma + v;
        }
        else {
            printf("Eh maior que 255.\n");
        }

    }
    printf("Soma total eh = %d\n", soma);

}

int main(){

    somasQuadrados();
}
