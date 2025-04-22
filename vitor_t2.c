#include <stdio.h>

/*
 * Código   Plano         Valor (R$)
 * 101      Mensal        41,90
 * 102      Trimestral    115,00
 * 103      Semestral     310,50
 * 104      Anual         599,99
 */

int  calcularPontosEBonus(float valorTotal, int quantPlanos, int ehClienteFidelizado) {
    int pontos;

    if (ehClienteFidelizado) {
        pontos = (int)(valorTotal / 40) * 10;
    } else {
        pontos = (int)(valorTotal / 50) * 7;
    }

    int planosBonus = 0;
    if (quantPlanos <= 5) {
        planosBonus = pontos / 50;
    }

    printf("Pontos acumulados: %d\n", pontos);
    if (planosBonus > 0) {
        printf("Parabens! Voce ganhou %d plano(s) mensal(is) de bonus!\n", planosBonus);
    }
    return planosBonus;
}

float calculavalorBruto(float valor, int quantPlanos) {

    float valorBruto;
    valorBruto = valor * quantPlanos;

    return valorBruto;

}

int calculaDias(int dias,int bonus) {


    if (bonus != 0) {


        bonus = bonus * 30;

    }

    return dias + bonus;

}

float calculaMediaMes(int dias, float valor) {

    int mes = dias /30;

    return valor / mes;

}

float calculaMediaDias(int dias, float valor) {

    return valor / dias;
}

float cliente(int dias, float valor) {
    int quantPlanos;
    char cliente;
    float valorDesconto, valorTotal = 0.0f;
    char tempo;
    int ehClienteFidelizado = 0;


    printf("Quantidade de unidades do plano: \n");
    scanf("%d", &quantPlanos);
    dias *= quantPlanos;

    if (quantPlanos > 0) {
        printf("Voce ja e cliente? (S/N)\n");
        scanf(" %c", &cliente);

        if (cliente == 'N' || cliente == 'n') {
            printf("Gostaria de se tornar cliente com fidelidade de 1 ano? (S/N)\n");
            scanf(" %c", &tempo);

            if (tempo == 'N' || tempo == 'n') {
                // Cliente novo SEM fidelidade
                if (quantPlanos == 1) {
                    valorTotal = valor;
                }
                else if (quantPlanos == 2) {
                    valorDesconto = valor * 0.95;
                    valorTotal = valor + valorDesconto;
                }
                else if (quantPlanos == 3) {
                    valorDesconto = valor * 0.94;
                    valorTotal = valor + valorDesconto;
                    valorDesconto = valor * 0.925;
                    valorTotal += valorDesconto;
                }
                else if (quantPlanos == 4) {
                    valorDesconto = valor * 0.9;
                    valorTotal = valor + (valorDesconto * 3);
                }
                else if (quantPlanos == 5) {
                    valorDesconto = valor * 0.875;
                    valorTotal = valorDesconto * 5;
                }
                else if (quantPlanos > 5) {
                    valorTotal = valor + (valor * (quantPlanos - 1)) * 1.075;
                }
            }
            else if (tempo == 'S' || tempo == 's') {

                ehClienteFidelizado = 1;
                valor = 599.99;
                dias = 360;
                dias *= quantPlanos;
                printf("Seu plano foi alterado para 1 Ano:\n");

                if (quantPlanos == 1) {
                    valorTotal = valor;
                }
                else if (quantPlanos == 2) {
                    valorDesconto = valor * 0.9;
                    valorTotal = valor + valorDesconto;
                }
                else if (quantPlanos == 3) {
                    valorDesconto = valor * 0.88;
                    valorTotal = valor + valorDesconto;
                    valorDesconto = valor * 0.85;
                    valorTotal += valorDesconto;
                }
                else if (quantPlanos == 4) {
                    valorDesconto = valor * 0.8;
                    valorTotal = valor + (valorDesconto * 3);
                }
                else if (quantPlanos == 5) {
                    valorDesconto = valor * 0.75;
                    valorTotal = valorDesconto * 5;
                }
                else if (quantPlanos > 5) {
                    valorTotal = valor + (valor * (quantPlanos - 1)) * 1.05;
                }
            }
        }
        else if (cliente == 'S' || cliente == 's') {

            ehClienteFidelizado = 1;

            if (quantPlanos == 1) {
                valorTotal = valor;
            }
            else if (quantPlanos == 2) {
                valorDesconto = valor * 0.9;
                valorTotal = valor + valorDesconto;
            }
            else if (quantPlanos == 3) {
                valorDesconto = valor * 0.88;
                valorTotal = valor + valorDesconto;
                valorDesconto = valor * 0.85;
                valorTotal += valorDesconto;
            }
            else if (quantPlanos == 4) {
                valorDesconto = valor * 0.8;
                valorTotal = valor + (valorDesconto * 3);
            }
            else if (quantPlanos == 5) {
                valorDesconto = valor * 0.75;
                valorTotal = valorDesconto * 5;
            }
            else if (quantPlanos > 5) {
                valorTotal = valor + (valor * (quantPlanos - 1)) * 1.05;
            }
        }
        else {
            printf("Opcao invalida! Digite S ou N.\n");
            return 0;
        }

       float  valorBruto = calculavalorBruto(valor, quantPlanos);
        if(quantPlanos > 5) {
            printf("O valor total do plano com as taxas eh: %.2f\n", valorTotal);

        }else {
            printf("O valor total do plano com desconto eh: %.2f\n", valorTotal);
        }

        printf("O valor bruto eh: %.2f\n", valorBruto);

            int planoBonus = calcularPontosEBonus(valorTotal, quantPlanos, ehClienteFidelizado);
            int diasTotal = calculaDias(dias,planoBonus);

        printf("Total de dias com bonus: %d\n" , diasTotal);
        printf("Total de dias sem bonus: %d\n", dias);

            float mediaMes = calculaMediaMes(dias, valorTotal);
            float mediaDias = calculaMediaDias(dias, valorTotal);

        printf("Valor da media por mes: %.2f\n", mediaMes);
        printf("Valor da media por dia: %.2f\n", mediaDias);



        return valorTotal;
    }
    else {
        printf("Quantidade de planos deve ser maior que zero!\n");
        return 0.0f;
    }
}

int main(void) {
    int escolha = 0;
    float valor = 0 ;
    int dias = 0 ;

    printf("Digite o código do plano telefônico: (101-104)\n");
    scanf("%d", &escolha);


    switch (escolha) {
        case 101:
            printf("Plano Mensal selecionado. \n");
            valor = 41.90;
            dias = 30;
            cliente(dias , valor);

        break;
        case 102:
            printf("Plano Trimestral selecionado.\n");
            valor = 115;
            dias = 90;
            cliente(dias , valor);

        break;
        case 103:
            printf("Plano Semestral selecionado. \n");
            valor = 310.50;
            dias = 180;
            cliente(dias , valor);

        break;
        case 104:
            printf("Plano Anual selecionado. \n");
            valor = 599.99;
            dias = 360;
            cliente(dias, valor);

        break;
        default:
            printf("Código Incorreto\n");
    }


    return 0;
}
