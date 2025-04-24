#include<stdio.h>


int main(){

int i = 100;
int total = 0;

for(i = 100; i <=200 ; i++){
    
    if(i % 13 != 0){
    
        total = total + i ;
        
    }
}
    printf("O total da soma dos numeros não multiplos de 13 eh:%d\n", total);

}
