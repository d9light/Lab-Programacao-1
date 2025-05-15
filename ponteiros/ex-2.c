
/******************************************************************************

Faça uma função que receba um número N como parâmetro por valor e 2 inteiros p1
e p2, por referência. A função deve retornar em p1 o maior número primo menor que
N e em p2 o menor número primo maior que N.

*******************************************************************************/
#include <stdio.h>
#include<stdbool.h>


bool ehPrimo(int contador){
    int cont = 0;

    for(int i = 1 ; i <= contador; i++){
        if(contador % i == 0){
            cont++;
        }
    }
    if(cont == 2){
        return true;
    }
    else
        return false;
}

void maiorPrimoEmenorPrimo(int valor, int *p1, int *p2){
    int i,j;
    bool primo,primoj;

    for(i = 1 ; i < valor; i++){

        primo = ehPrimo(i);

        if(primo == true){

            if(i > *p1){
                *p1 = i;
            }
        }

        for(j = valor + 1; j != 0; j++){

            primoj = ehPrimo(j);
            if( primoj == true){

                if(j > valor){

                    *p2 = j;
                    break;


                }
            }
        }
    }

}
int main()
{
    int num1;
    int p1 = 0, p2 = 0;


    printf("Digite um um valor N:");
    scanf("%d",&num1);

    maiorPrimoEmenorPrimo(num1,&p1,&p2);

    printf("O valor de N:%d\n", num1);
    printf("o maior número primo menor que N:%d\no menor número primo maior que N:%d\n", p1, p2);


}
