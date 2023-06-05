#include <stdio.h>
#include "conjunto.h"

void imprimeConjunto(Conjunto* conjunto) {
    int i;
    printf("{ ");
    for (i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto* conjunto1 = criaConjunto();
    Conjunto* conjunto2 = criaConjunto();
    Conjunto* conjuntoUniao;
    Conjunto* conjuntoInterseccao;

    insereElemento(conjunto1, 1);
    insereElemento(conjunto1, 2);
    insereElemento(conjunto1, 3);

    insereElemento(conjunto2, 2);
    insereElemento(conjunto2, 3);
    insereElemento(conjunto2, 4);

    printf("Conjunto 1: ");
    imprimeConjunto(conjunto1);

    printf("Conjunto 2: ");
    imprimeConjunto(conjunto2);

    int elemento = 2;
    if (pertence(conjunto1, elemento)) {
        printf("O elemento %d pertence ao conjunto 1\n", elemento);
    } else {
        printf("O elemento %d não pertence ao conjunto 1\n", elemento);
    }

    conjuntoUniao = uniao(conjunto1, conjunto2);
    printf("União dos conjuntos: ");
    imprimeConjunto(conjuntoUniao);

    conjuntoInterseccao = interseccao(conjunto1, conjunto2);
    printf("Intersecção dos conjuntos: ");
    imprimeConjunto(conjuntoInterseccao);

    return 0;
}
