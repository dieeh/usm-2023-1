#include "sevienencositas.h"

/**
 * void shuffle(carta *array, size_t n)
 *
 * Ordena los N elementos del ARRAY en orden aleatorio.
 * Solo es efectivo si N es mucho más pequeño que RAND_MAX;
 * si este no es el caso, use un mejor generador
 * de numeros aleatorios.
 */
void shuffle(carta *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            carta t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Funcion para inicializar el mazo
void init_mazo(mazo *s)
{
    s->top = -1;
}

// Funcion para chequear si el mazo está vacío
bool is_empty(mazo *s)
{
    return s->top == -1;
}

// Funcion para chequear si el mazo está lleno
bool is_full(mazo *s)
{
    return s->top == MAX_SIZE - 1;
}

// Funcion para chequear cuantos elementos hay en el mazo
int how_many(mazo *s)
{
    return (s->top) + 1;
}

// Funcion para meter un item al mazo
void push(mazo *s, carta c)
{
    if (is_full(s))
    {
        printf("Error: mazo is full\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = c;
}

// Funcion para sacar un item del mazo
carta pop(mazo *s)
{
    if (is_empty(s))
    {
        printf("Error: mazo is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

// Funcion para ver el último elemento del mazo
carta peek(mazo *s)
{
    if (is_empty(s))
    {
        printf("Error: mazo is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}