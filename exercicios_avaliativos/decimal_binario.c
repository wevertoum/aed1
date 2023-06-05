#include <stdio.h>

void decimalParaBinario(int decimal) {
    if (decimal > 0) {
        decimalParaBinario(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimal;
    scanf("%d", &decimal);
    decimalParaBinario(decimal);
    return 0;
}
