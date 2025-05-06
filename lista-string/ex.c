/*
 Faça uma função que leia uma string, e 2 caracteres c1 e c2. A função
deve substituir todas as ocorrências do caractere c1 por c2. Ao final,
escreva as 2 strings.
*/

#include <stdio.h>

void substituirCaracter(){

    char a[10];
    char c1,c2;
    
    printf("Preencha a string:\n");
        fgets(a, sizeof(a), stdin);
        
    printf("Escolha uma letra:");
    while (getchar() != '\n'); 
    c1 = getchar();
    
    while (getchar() != '\n'); 
    printf("Escolha uma letra:");
    c2 = getchar();
        for (int i = 0; a[i] != '\0'; i++) {
          
            if (a[i] == c1) {
            
            a[i] = c2;
            
             }
}

    printf("Frase: %s", a);
}

int main()
{
    substituirCaracter();
}
