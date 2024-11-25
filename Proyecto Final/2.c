#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

//Dominguez Lira Estefani Michalle
//Rodriguez Rodriguez Erick Tadeo

typedef struct {
    char elementos[MAX][MAX];
    int cima;
} Pila;

void inicializarPila(Pila *pila) {
    pila->cima = -1;
}

int pilaLlena(Pila *pila) {
    return pila->cima == MAX - 1;
}

int pilaVacia(Pila *pila) {
    return pila->cima == -1;
}

void apilar(Pila *pila, const char *elemento) {
    if (pilaLlena(pila)) {
        printf("La pila está llena.\n");
    } else {
        pila->cima++;
        strcpy(pila->elementos[pila->cima], elemento);
    }
}

char *desapilar(Pila *pila) {
    if (pilaVacia(pila)) {
        printf("La pila está vacía.\n");
        return NULL;
    } else {
        return pila->elementos[pila->cima--];
    }
}

char *consultarCima(Pila *pila) {
    if (pilaVacia(pila)) {
        printf("La pila está vacía.\n");
        return NULL;
    } else {
        return pila->elementos[pila->cima];
    }
}

int precedencia(char operador) {
    switch (operador) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int esNumero(char c) {
    return isdigit(c) || c == '.';
}

void imprimirEstado(const char *expresion, Pila *pila, const char *resultado, int paso) {
    printf("\nPaso %d:\n", paso);
    printf("Operación usada:\t%s\n", expresion);
    printf("Pila:\t\t\t");
    for (int i = 0; i <= pila->cima; i++) {
        printf("%s ", pila->elementos[i]);
    }
    if (pilaVacia(pila)) {
        printf("(vacía)");
    }
    printf("\nOperacion:\t\t%s\n", resultado);
}

void imprimirEstadoPrefija(const char *expresion, Pila *pila, const char *resultado, int paso) {
    printf("\nPaso %d:\n", paso);
    printf("Operacion usada:\t%s\n", expresion);
    printf("Pila:\t\t\t");
    for (int i = pila->cima; i >= 0; i--) {
        printf("%s ", pila->elementos[i]);
    }
    if (pilaVacia(pila)) {
        printf("(vacía)");
    }
    printf("\nOperacion:\t\t%s\n", resultado);
}

void infijaAPostfijaPasoAPaso(const char *infija, char *postfija) {
    Pila pila;
    inicializarPila(&pila);
    int i = 0, j = 0, paso = 1;
    char simbolo;
    char procesada[MAX] = "";

    while ((simbolo = infija[i++]) != '\0') {
        strncat(procesada, &simbolo, 1);

        if (esNumero(simbolo)) {
            postfija[j++] = simbolo;
        } else if (simbolo == '(') {
            apilar(&pila, "(");
        } else if (simbolo == ')') {
            while (!pilaVacia(&pila) && strcmp(consultarCima(&pila), "(") != 0) {
                postfija[j++] = desapilar(&pila)[0];
            }
            desapilar(&pila);
        } else if (esOperador(simbolo)) {
            while (!pilaVacia(&pila) && precedencia(consultarCima(&pila)[0]) >= precedencia(simbolo)) {
                postfija[j++] = desapilar(&pila)[0];
            }
            char temporal[2] = {simbolo, '\0'};
            apilar(&pila, temporal);
        }

        postfija[j] = '\0';
        imprimirEstado(procesada, &pila, postfija, paso++);
    }

    while (!pilaVacia(&pila)) {
        postfija[j++] = desapilar(&pila)[0];
        imprimirEstado(procesada, &pila, postfija, paso++);
    }
    postfija[j] = '\0';
}

void invertirCadena(char *cadena) {
    int len = strlen(cadena);
    for (int i = 0; i < len / 2; i++) {
        char temp = cadena[i];
        cadena[i] = cadena[len - i - 1];
        cadena[len - i - 1] = temp;
    }
}

void cambiarParentesis(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '(') {
            cadena[i] = ')';
        } else if (cadena[i] == ')') {
            cadena[i] = '(';
        }
    }
}

void infijaAPrefijaPasoAPaso(const char *infija, char *prefija) {
    char invertida[MAX], postfija[MAX];
    strcpy(invertida, infija);

    // Invertir la expresión infija
    invertirCadena(invertida);
    cambiarParentesis(invertida);

    // Convertir a postfija
    Pila pila;
    inicializarPila(&pila);
    int i = 0, j = 0, paso = 1;
    char simbolo;
    char procesada[MAX] = "";

    while ((simbolo = invertida[i++]) != '\0') {
        strncat(procesada, &simbolo, 1);

        if (esNumero(simbolo)) {
            postfija[j++] = simbolo;
        } else if (simbolo == '(') {
            apilar(&pila, "(");
        } else if (simbolo == ')') {
            while (!pilaVacia(&pila) && strcmp(consultarCima(&pila), "(") != 0) {
                postfija[j++] = desapilar(&pila)[0];
            }
            desapilar(&pila);
        } else if (esOperador(simbolo)) {
            while (!pilaVacia(&pila) && precedencia(consultarCima(&pila)[0]) >= precedencia(simbolo)) {
                postfija[j++] = desapilar(&pila)[0];
            }
            char temporal[2] = {simbolo, '\0'};
            apilar(&pila, temporal);
        }

        postfija[j] = '\0';
        imprimirEstadoPrefija(procesada, &pila, postfija, paso++);
    }

    while (!pilaVacia(&pila)) {
        postfija[j++] = desapilar(&pila)[0];
        imprimirEstadoPrefija(procesada, &pila, postfija, paso++);
    }
    postfija[j] = '\0';

    // Invertir la salida postfija para obtener la prefija
    strcpy(prefija, postfija);
    invertirCadena(prefija);
}

// Evaluar expresiones en notación postfija
double evaluarPostfija(const char *postfija) {
    Pila pila;
    inicializarPila(&pila);
    char operando[10];

    for (int i = 0; postfija[i] != '\0'; i++) {
        if (esNumero(postfija[i])) {
            operando[0] = postfija[i];
            operando[1] = '\0';
            apilar(&pila, operando);
        } else if (esOperador(postfija[i])) {
            double b = atof(desapilar(&pila));
            double a = atof(desapilar(&pila));
            double resultado;

            switch (postfija[i]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': resultado = a / b; break;
                case '^': resultado = pow(a, b); break;
            }

            sprintf(operando, "%.2lf", resultado);
            apilar(&pila, operando);
        }
    }

    return atof(desapilar(&pila));
}

// Evaluar expresiones en notación prefija
double evaluarPrefija(const char *prefija) {
    Pila pila;
    inicializarPila(&pila);
    char operando[10];
    int len = strlen(prefija);

    for (int i = len - 1; i >= 0; i--) {
        if (esNumero(prefija[i])) {
            operando[0] = prefija[i];
            operando[1] = '\0';
            apilar(&pila, operando);
        } else if (esOperador(prefija[i])) {
            double a = atof(desapilar(&pila));
            double b = atof(desapilar(&pila));
            double resultado;

            switch (prefija[i]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': resultado = a / b; break;
                case '^': resultado = pow(a, b); break;
            }

            sprintf(operando, "%.2lf", resultado);
            apilar(&pila, operando);
        }
    }

    return atof(desapilar(&pila));
}

int main() {
    char infija[MAX], postfija[MAX], prefija[MAX];

    printf("Notacion infija: ");
    scanf("%s", infija);

    printf("\n-----Proceso postfija----\n");
    infijaAPostfijaPasoAPaso(infija, postfija);
    printf("\nNotacion postfija final: %s\n", postfija);
    printf("Resultado de la expresión postfija: %.2lf\n", evaluarPostfija(postfija));

    printf("\n----- Proceso prefija-----\n");
    infijaAPrefijaPasoAPaso(infija, prefija);
    printf("\nNotación prefija final: %s\n", prefija);
    printf("Resultado de la expresión prefija: %.2lf\n", evaluarPrefija(prefija));

    return 0;
}
