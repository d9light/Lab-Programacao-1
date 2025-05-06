/*
Faça um programa que leia um caractere C e uma string S. O
programa deve armazenar, em um vetor V, os índices onde c1
aparece em S. Ao final, imprima o vetor.
*/

#include <stdio.h>


int main()
{
    int v[50],j = 0 ;
    char c, s[50];
    
    printf("Digite uma frase:\n");
        fgets(s, sizeof(s), stdin); 
        
    printf("Digite um caractere:\n");
    while (getchar() != '\n'); 
       c = getchar();     
        
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            v[j] = i;
            j++;
        }
    }
  printf("Índices do caractere '%c' na string: ", c);
    for (int i = 0; i < j; i++) {
        printf("%d ", v[i]);
    }

    

}
