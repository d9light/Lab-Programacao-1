/******************************************************************************

Faça um programa que leia um número N e N valores inteiros. Para cada valor lido,
chame uma função que calcule e retorne (na mesma variável) a quantidade de
divisores do mesmo.

*******************************************************************************/
#include <stdio.h>

void quantDivisores(int *valor){
    int i;
    int cont;
    for(i = 1; i <= *valor; i++){
       
        if(*valor % i == 0){
            cont++;
        }
    }
    *valor = cont;
    
}

int main()
{
    int num1,diferente;
    
    do{
    printf("Digite um um valor N:");
        scanf("%d",&num1);
    
    quantDivisores(&num1);
        
    printf("A quantidade de valores eh:%d\n", num1);
        
    printf("Gostaria de encerrar:\n(0-Para sim)");
        scanf("%d",&diferente);

    }while(diferente != 0);
        
    
    }
