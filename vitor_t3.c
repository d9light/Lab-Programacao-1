#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

int rodada_jogador1 = 1;
int rodada_jogador2 = 1;
int pontuacao = 999;
int pontuacao2 = 999;
int jogador_atual = 1;


void exibirCabecalho() {
    printf("\n");
    printf("========================================\n");
    printf("| Down to zero |\n");
    printf("========================================\n");
}

void exibirDados(int d1, int d2, int d3, int num_dados) {
    printf("\nValores dos dados:\n");
    printf("Dado 1: %d\n", d1);

    if (num_dados >= 2) {
        printf("Dado 2: %d\n", d2);
    }

    if (num_dados == 3) {
        printf("Dado 3: %d\n", d3);
    }
    printf("\n");
}

int sorteioNumero() {
    int num = 0;
    num = (rand() % 6) + 1;
    return num;
}

int organizaNumero(int d1, int d2, int d3, int num_dados) {
    if (num_dados == 2) {
        int comb1 = d1 * 10 + d2;
        int comb2 = d2 * 10 + d1;

        printf("\nCombinacoes possiveis com 2 dados:\n");
        printf("1. %d\n", comb1);
        printf("2. %d\n", comb2);
        printf("\nEscolha uma das combinacoes (1 ou 2): ");

        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1) {
            return comb1;
        } else {
            return comb2;
        }
    }
    else {
        int combinacoes1 = d1 * 100 + d2 * 10 + d3;
        int combinacoes2 = d1 * 100 + d3 * 10 + d2;
        int combinacoes3 = d2 * 100 + d1 * 10 + d3;
        int combinacoes4 = d2 * 100 + d3 * 10 + d1;
        int combinacoes5 = d3 * 100 + d1 * 10 + d2;
        int combinacoes6 = d3 * 100 + d2 * 10 + d1;

        printf("\nCombinacoes possiveis com 3 dados:\n");
        printf("1. %d\n", combinacoes1);
        printf("2. %d\n", combinacoes2);
        printf("3. %d\n", combinacoes3);
        printf("4. %d\n", combinacoes4);
        printf("5. %d\n", combinacoes5);
        printf("6. %d\n", combinacoes6);
        printf("\nEscolha uma das combinacoes (1 a 6): ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: return combinacoes1;
            case 2: return combinacoes2;
            case 3: return combinacoes3;
            case 4: return combinacoes4;
            case 5: return combinacoes5;
            case 6: return combinacoes6;
            default: return combinacoes1;
        }
    }
}

int diminuiPontuacao(int num1) {
    int total;

    if (jogador_atual == 1) {
        total = pontuacao - num1;

        if (total >= 0) {
            pontuacao = total;
            if (pontuacao == 0)
            return 1;
        }
    }
    else if (jogador_atual == 2)
    {
        total = pontuacao2 - num1;
        if (total >= 0) {
            pontuacao2 = total;
            if (pontuacao2 == 0)
            return 1;
        }
    }

    return 0;
}

void trocaJogador() {
    if (jogador_atual == 1) {
        jogador_atual = 2;
        rodada_jogador1 = rodada_jogador1 + 1;
    } else {
        jogador_atual = 1;
        rodada_jogador2 = rodada_jogador2 + 1;
    }
}

void exibirPlacar() {
    printf("\n");
    printf("+---------------------+\n");
    printf("|      PLACAR        |\n");
    printf("+---------------------+\n");
    printf("| Jogador 1: %d |\n", pontuacao);
    printf("| Jogador 2: %d |\n", pontuacao2);
    printf("+---------------------+\n");
    printf("\n");
}

int jogarRodada() {
    int d1, d2, d3 = 0;
    int num_dados = 3;
    int total = 0;
    int organizado;

    exibirCabecalho();
    exibirPlacar();

    if (rodada_jogador1 == 1 || rodada_jogador2 == 1) {
        printf("Vez do JOGADOR %d (Rodada Inicial)\n", jogador_atual);

        d1 = sorteioNumero();
        d2 = sorteioNumero();
        d3 = sorteioNumero();

        exibirDados(d1, d2, d3, 3);
        organizado = organizaNumero(d1, d2, d3, num_dados);
        printf("\nCombinacao escolhida: %d\n", organizado);
        total = diminuiPontuacao(organizado);
        trocaJogador();

    }
    else {
        printf("Vez do JOGADOR %d (Rodada %d)\n", jogador_atual,
               (jogador_atual == 1) ? rodada_jogador1 : rodada_jogador2);

        printf("\nQuantos dados deseja jogar?\n");
        printf("1. Jogar 1 dado\n");
        printf("2. Jogar 2 dados\n");
        printf("3. Jogar 3 dados\n");
        printf("\nEscolha: ");

        scanf("%d", &num_dados);

        switch (num_dados) {
            case 1:
                d1 = sorteioNumero();
                exibirDados(d1, 0, 0, 1);
                printf("Valor do dado: %d\n", d1);
                total = diminuiPontuacao(d1);
                break;

            case 2:
                d1 = sorteioNumero();
                d2 = sorteioNumero();
                exibirDados(d1, d2, 0, 2);
                organizado = organizaNumero(d1, d2, 0, num_dados);
                printf("\nCombinacao escolhida: %d\n", organizado);
                total = diminuiPontuacao(organizado);
                break;

            case 3:
                d1 = sorteioNumero();
                d2 = sorteioNumero();
                d3 = sorteioNumero();
                exibirDados(d1, d2, d3, 3);
                organizado = organizaNumero(d1, d2, d3, num_dados);
                printf("\nCombinacao escolhida: %d\n", organizado);
                total = diminuiPontuacao(organizado);
                break;
        }

        if (total == 1) {
            exibirCabecalho("FIM DE JOGO");
            printf("\nPARABENS! Jogador %d venceu!\n", jogador_atual);
            return 1;
        }

        trocaJogador();
    }
    return 0;
}

int maiorCombinacaoTresDados(int d1, int d2, int d3) {
    int comb1 = d1 * 100 + d2 * 10 + d3;
    int comb2 = d1 * 100 + d3 * 10 + d2;
    int comb3 = d2 * 100 + d1 * 10 + d3;
    int comb4 = d2 * 100 + d3 * 10 + d1;
    int comb5 = d3 * 100 + d1 * 10 + d2;
    int comb6 = d3 * 100 + d2 * 10 + d1;
    int maior = comb1;

    if (comb2 > maior) maior = comb2;
    if (comb3 > maior) maior = comb3;
    if (comb4 > maior) maior = comb4;
    if (comb5 > maior) maior = comb5;
    if (comb6 > maior) maior = comb6;

    return maior;
}

int escolhaMaisProximaDoValor(int pontuacao2, int d1, int d2, int d3, int num_dados) {
    int proxima = -1;

    if (num_dados == 3) {
        int comb1 = d1 * 100 + d2 * 10 + d3;
        int comb2 = d1 * 100 + d3 * 10 + d2;
        int comb3 = d2 * 100 + d1 * 10 + d3;
        int comb4 = d2 * 100 + d3 * 10 + d1;
        int comb5 = d3 * 100 + d1 * 10 + d2;
        int comb6 = d3 * 100 + d2 * 10 + d1;

        if (comb1 <= pontuacao2 && comb1 > proxima) proxima = comb1;
        if (comb2 <= pontuacao2 && comb2 > proxima) proxima = comb2;
        if (comb3 <= pontuacao2 && comb3 > proxima) proxima = comb3;
        if (comb4 <= pontuacao2 && comb4 > proxima) proxima = comb4;
        if (comb5 <= pontuacao2 && comb5 > proxima) proxima = comb5;
        if (comb6 <= pontuacao2 && comb6 > proxima) proxima = comb6;
    }
    else if (num_dados == 2) {
        int comb1 = d1 * 10 + d2;
        int comb2 = d2 * 10 + d1;

        // Verifica combinações de 2 dados
        if (comb1 <= pontuacao2 && comb1 > proxima) proxima = comb1;
        if (comb2 <= pontuacao2 && comb2 > proxima) proxima = comb2;
    }
    else if (num_dados == 1) {

        if (d1 <= pontuacao2) {
            proxima = d1;
        }
    }

    return (proxima == -1) ? 0 : proxima;
}

int jogarRodadaComBot() {
    int d1 = 0, d2 = 0, d3 = 0;
    int num_dados = 3;
    int total = 0;
    int organizado = 0;
    int proxima = 0;

    exibirCabecalho("JOGO DE DADOS");
    exibirPlacar();

    if (rodada_jogador1 == 1) {
        printf("Vez do JOGADOR %d (Rodada Inicial)\n", jogador_atual);

        d1 = sorteioNumero();
        d2 = sorteioNumero();
        d3 = sorteioNumero();

        exibirDados(d1, d2, d3, 3);
        organizado = organizaNumero(d1, d2, d3, num_dados);
        printf("\nCombinacao escolhida: %d\n", organizado);
        total = diminuiPontuacao(organizado);


        trocaJogador();
    }
    else if (rodada_jogador2 == 1) {
        printf("Vez do ROBO (Rodada Inicial)\n");
        d1 = sorteioNumero();
        d2 = sorteioNumero();
        d3 = sorteioNumero();

        exibirDados(d1, d2, d3, 3);
        int maior_combinacao = maiorCombinacaoTresDados(d1, d2, d3);

        printf("\nCombinacao escolhida pelo robo: %d\n", maior_combinacao);
        total = diminuiPontuacao(maior_combinacao);

        sleep(5);
        trocaJogador();
    }
    else {
        if (jogador_atual == 1) {
            printf("Vez do JOGADOR %d (Rodada %d)\n", jogador_atual, rodada_jogador1);

            printf("\nQuantos dados deseja jogar?\n");
            printf("1. Jogar 1 dado\n");
            printf("2. Jogar 2 dados\n");
            printf("3. Jogar 3 dados\n");
            printf("\nEscolha: ");

            scanf("%d", &num_dados);

            switch (num_dados) {
                case 1:
                    d1 = sorteioNumero();
                    exibirDados(d1, 0, 0, 1);
                    printf("Valor do dado: %d\n", d1);
                    total = diminuiPontuacao(d1);
                    break;
                case 2:
                    d1 = sorteioNumero();
                    d2 = sorteioNumero();
                    exibirDados(d1, d2, 0, 2);
                    organizado = organizaNumero(d1, d2, 0, num_dados);
                    printf("\nCombinacao escolhida: %d\n", organizado);
                    total = diminuiPontuacao(organizado);
                    break;
                case 3:
                    d1 = sorteioNumero();
                    d2 = sorteioNumero();
                    d3 = sorteioNumero();
                    exibirDados(d1, d2, d3, 3);
                    organizado = organizaNumero(d1, d2, d3, num_dados);
                    printf("\nCombinacao escolhida: %d\n", organizado);
                    total = diminuiPontuacao(organizado);
                    break;
            }

            if (total == 1) {
                exibirCabecalho("FIM DE JOGO");
                printf("\nPARABENS! Jogador %d venceu!\n", jogador_atual);
                return 1;
            }

        }
        else {
            printf("Vez do ROBO (Rodada %d)\n", rodada_jogador2);

            if (pontuacao2 >= 200) {
                num_dados = 3;
                printf("O robo escolheu jogar 3 dados\n");
            }
            else if (pontuacao2 > 10) {
                num_dados = 2;
                printf("O robo escolheu jogar 2 dados\n");
            }
            else {
                num_dados = 1;
                printf("O robo escolheu jogar 1 dado\n");
            }

            switch (num_dados) {
                case 1:
                    d1 = sorteioNumero();
                    exibirDados(d1, 0, 0, 1);
                    printf("Valor do dado: %d\n", d1);
                    diminuiPontuacao(d1);
                    printf("Pontuacao do Robo: %d\n", pontuacao2);
                    break;
                case 2:
                    d1 = sorteioNumero();
                    d2 = sorteioNumero();
                    exibirDados(d1, d2, 0, 2);
                    proxima = escolhaMaisProximaDoValor(pontuacao2, d1, d2, d3, num_dados);
                    printf("\nCombinacao escolhida pelo robo: %d\n", proxima);
                    diminuiPontuacao(proxima);
                    printf("Pontuacao do Robo: %d\n", pontuacao2);
                    break;
                case 3:
                    d1 = sorteioNumero();
                    d2 = sorteioNumero();
                    d3 = sorteioNumero();
                    exibirDados(d1, d2, d3, 3);
                    proxima = escolhaMaisProximaDoValor(pontuacao2, d1, d2, d3, num_dados);
                    printf("\nCombinacao escolhida pelo robo: %d\n", proxima);
                    diminuiPontuacao(proxima);
                    printf("Pontuacao do Robo: %d\n", pontuacao2);
                    break;
            }

            if (total == 1) {
                exibirCabecalho("FIM DE JOGO");
                printf("\nO ROBO venceu!\n");
                return 1;
            }


        }
        sleep(5);
        trocaJogador();
    }
    return 0;
}

void exibirMenuInicial() {
    exibirCabecalho();
    printf("\nBem-vindo ao Jogo de Dados 999!\n");
    printf("O objetivo e reduzir sua pontuacao exatamente para 0.\n");
    printf("\nEscolha o modo de jogo:\n");
    printf("1. Jogar contra o computador\n");
    printf("2. Jogador vs Jogador\n");
    printf("\nDigite sua escolha (1 ou 2): ");
}

int main() {
    srand(time(NULL) );

    int escolha;

    exibirMenuInicial();
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: {
            int vencedor = 0;
            while(1) {
                vencedor = jogarRodadaComBot();
                if (vencedor != 0) {
                    break;
                }
            }
            break;
        }
        case 2: {
            int vencedor = 0;
            int jogador_atual = 1;

            while(1) {
                vencedor = jogarRodada();
                if (vencedor != 0) {
                    break;
                }
            }
            break;
        }
        default:
            printf("Opcao invalida! O jogo sera encerrado.\n");
            break;
    }

    printf("\nObrigado por jogar!\n");
    return 0;
}