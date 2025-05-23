#include <stdio.h>

/*
Leia a matrícula e 3 notas de 10 alunos. Para cada um, calcule a
média ponderada (pesos 4, 3 e 3), mostre a matrícula, as 3 notas, a
média e uma mensagem "APROVADO" se a média for maior ou
igual a 7 e "REPROVADO“, caso contrário.

 *
 */

float calculaMedia(float n1, float n2, float n3) {

    float media = 0;
    media = (n1 * 4 + n2 * 3 + n3 * 3) / 10.0;
    return (float)media;
}

void verificaAprovocao(float media) {

    if (media >= 7) {
        printf("Aprovado \n");
    }
    else {
        printf("Reprovado \n");
    }

}

int main() {
    int m;
    float n1,n2,n3;
    float media = 0;

    printf("Calcule sua media:\n");

    for (int i = 0; i <= 10; i++) {
        printf("Digite sua matricula: ");
        scanf("%d", &m);

        printf("Digite sua nota 1: ");
        scanf("%f", &n1);

        printf("Digite sua nota 2: ");
        scanf("%f", &n2);

        printf("Digite sua nota 3: ");
        scanf("%f", &n3);

        printf("Sua Matricula: %d\n",m);
        media = calculaMedia(n1,n2,n3);
        printf("Media do aluno: %.2f\n",media);
        verificaAprovocao(media);
    }
}
