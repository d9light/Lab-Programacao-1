#include<stdio.h>

/*
3) Faça um programa que chame uma função que leia 200 números inteiros e
imprima a quantidade de pares, sua média, a quantidade de ímpares e seu
somatório.

*/

int calculaPares(){

    int n = 200;
    int count1;
    int totalImpares = 0;
    float media = 0, totalPares;
    
    for(int i = 1; i<=200; i++){
        
        if(i%2 == 0){

           count1++;
        
            media = media + i;
            
            totalPares = media / count1;
        
        }
        else{
             totalImpares = totalImpares + i;

        }

    }
 printf("Total pares:%d\n",count1);
 printf("A media das somas dos numeros pares:%f\n", totalPares);
 printf("Total de soma de imapres:%d\n",totalImpares);
}

int main(){

calculaPares();

}
