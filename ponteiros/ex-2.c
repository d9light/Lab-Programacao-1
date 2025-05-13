/******************************************************************************

Faça uma função que receba um número N como parâmetro por valor e 2 inteiros p1
e p2, por referência. A função deve retornar em p1 o maior número primo menor que
N e em p2 o menor número primo maior que N.

*******************************************************************************/
#include <stdio.h>

void maiorPrimoEmenorPrimo(int valor, int *p1, int *p2){
    int i;
    int cont;
    
    for(i = 1; i <= valor; i++){
       
        if(valor % i == 0){
            
            cont++;
        }
    }
    if(cont == 2){
        
        for(i = 1; i<= valor ; i++){
            if(valor % i == 0 ){
               if(*p1 < i){
                   *p1 = i;
               }
              else if(*p2 > i ){
                  *p2 = i;
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
    
    maiorPrimoEmenorPrimo(num1,*p1,*p2);
        
    printf("O valor de N:%d\n", num1);
    printf("o maior número primo menor que N:%d\no menor número primo maior que N:%d\n", p1, p2);

    
    }
