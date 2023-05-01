#ifndef sevienencositas_H
#define sevienencositas_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 100

typedef struct carta
{
    int numero;
    int puntos;
} carta;

typedef struct mazo
{
    carta data[MAX_SIZE];
    int top;
} mazo;

/**
 * void shuffle(carta *array, size_t n)
 *
 * Ordena los N elementos del ARRAY en orden aleatorio.
 * Solo es efectivo si N es mucho más pequeño que RAND_MAX;
 * si este no es el caso, use un mejor generador
 * de numeros aleatorios.
 */
void shuffle(carta *array, size_t n);

// Funcion para inicializar el mazo
void init_mazo(mazo *s);

// Funcion para chequear si el mazo está vacío
bool is_empty(mazo *s);

// Funcion para chequear si el mazo está lleno
bool is_full(mazo *s);

// Funcion para chequear cuantos elementos hay en el mazo
int how_many(mazo *s);

// Funcion para meter un item al mazo
void push(mazo *s, carta c);

// Funcion para sacar un item del mazo
carta pop(mazo *s);

// Funcion para ver el último elemento del mazo
carta peek(mazo *s);

#endif