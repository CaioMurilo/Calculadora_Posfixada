#include <stdio.h>
#include "expressao.h"

int main() {
    char expressao[TAMANHO_MAX];
    printf("Digite a expressao posfixada: ");
    fgets(expressao, TAMANHO_MAX, stdin);

    double resultado = avaliar_expressao_posfixada(expressao);

    printf("Resultado: %.2lf\n", resultado);

    return 0;
}
