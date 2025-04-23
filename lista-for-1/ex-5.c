#include <stdio.h>

int main() {
    float s = 0;

    for (int n = 1; n <= 50; n++) {
        float termo = (2.0 * n - 1) / n;
        s += termo;
    }

    printf("Soma  = %.4f\n", s);
}
