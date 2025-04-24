
#include<stdio.h>

int soma(int n){

    int total ;
    total = 0;

    for(int i=0; i<n ; i++){

        total = total + i;

    }

    return total;
}

int main(){

    int n  ;
    n = 0;
    printf("Defina o valor de N:\n ");
        scanf("%d",&n);

    int total = soma(n);

    printf("O total da soma é:%d", total);
}
