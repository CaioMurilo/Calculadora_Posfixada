#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define TAMANHO_MAX 100

bool eh_operando(char token);
bool eh_operador(char token);
double avaliar_expressao_posfixada(const char *expressao);

#endif /* EXPRESSAO_H */
