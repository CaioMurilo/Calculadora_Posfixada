#include "expressao.h"

bool eh_operando(char token) {
    return (token >= '0' && token <= '9') || token == '.' || token == ',';
}

bool eh_operador(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^' || token == 's' || token == 'c' || token == 't' || token == 'l';
}

double avaliar_expressao_posfixada(const char *expressao) {
    double pilha[TAMANHO_MAX];
    int topo = -1;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char token = expressao[i];
        if (eh_operando(token)) {
            double operando;
            sscanf(&expressao[i], "%lf", &operando);
            while ((expressao[i] >= '0' && expressao[i] <= '9') || expressao[i] == '.' || expressao[i] == ',') {
                i++;
            }
            i--;
            pilha[++topo] = operando;
        } else if (eh_operador(token)) {
            if (token == 's') {
                double operando = pilha[topo--]; // Desempilha o valor para aplicar o seno
                pilha[++topo] = sin(operando * (M_PI / 180.0)); // Aplica o seno do operando em graus
            } else if (token == 'c') {
                double operando = pilha[topo--]; // Desempilha o valor para aplicar o cosseno
                pilha[++topo] = cos(operando * (M_PI / 180.0)); // Aplica o cosseno do operando em graus
            } else if (token == 't') {
                pilha[topo] = tan(pilha[topo]);
            } else if (token == 'l') {
                double operando = pilha[topo--]; // Desempilha o valor para aplicar o logaritmo
                pilha[++topo] = log10(operando); // Aplica o logaritmo na base 10 e empilha o resultado
            } else if (token == '^') {
                double operando2 = pilha[topo--]; // Desempilha o segundo operando
                double operando1 = pilha[topo--]; // Desempilha o primeiro operando
                pilha[++topo] = pow(operando1, operando2); // Aplica a potência
            } else {
                double operando2 = pilha[topo--]; // Desempilha o segundo operando
                double operando1 = pilha[topo--]; // Desempilha o primeiro operando
                switch(token) {
                    case '+':
                        pilha[++topo] = operando1 + operando2;
                        break;
                    case '-':
                        pilha[++topo] = operando1 - operando2;
                        break;
                    case '*':
                        pilha[++topo] = operando1 * operando2;
                        break;
                    case '/':
                        pilha[++topo] = operando1 / operando2;
                        break;
                }
            }
        }
    }
    return pilha[topo];
}
