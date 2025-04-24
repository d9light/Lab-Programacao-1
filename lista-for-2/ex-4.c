#include<stdio.h>

/*
4) Faça um programa que imprima a tabela de conversão de graus CelsiusFahrenheit para o intervalo especificado pelo usuário. O programa deve
solicitar ao usuário os limites superior e inferior do intervalo e o
decremento/incremento (ex. intervalo de 0 a 20, conversão a cada 2
“unidades”).

*/

float celsiusFahrenheit(int i){
    float total;
    total = i * 1.8 +32;
    
    printf("C: %d   F:%f\n", i ,total);
}

int main(){

int i, j;
i = 0;
j = 0;
int escolha = 0 ;
int incrimento = 0;

printf("Digite os 2 digitos do intervalo:\n");
    scanf("%d",&i);
    scanf("%d",&j);
    
printf("Digite o valor de incrimento/decremento:\n");
    scanf("%d", &incrimento);
    
    printf("Escolha:\n1-/incrimento\n2-/decremento\n");
        scanf("%d",&escolha);
        
switch(escolha){
    
    case 1:{
    for (int celsius = i; celsius <= j; celsius += incrimento) {

        celsiusFahrenheit(celsius);
    }
        
    }
    case 2:{
            for (int celsius = j; celsius >= i; celsius -= incrimento) {
                
                        celsiusFahrenheit(celsius);

    }
    
}
   
}
       
   
}
