#include <stdio.h>

#include <stdio.h>

void torre_hanoi(int discos, char origem, char auxiliar, char destino) {
    if (discos == 1) {
        printf("(%c, %c)\n", origem, destino);
        return;
    }
    torre_hanoi(discos - 1, origem, destino, auxiliar);
    printf("(%c, %c)\n", origem, destino);
    torre_hanoi(discos - 1, auxiliar, origem, destino);
}

int main() {
    int discos;
    scanf("%d",&discos);
    torre_hanoi(discos, 'O', 'A', 'D');
    return 0;
}