#include "sevienencositas.h"

int main(int argc, char const *argv[])
{
    int rondas = 10;
    carta cartas[44];

    for (int i = 0; i < 44; i++)
    {
        int numero_carta = i + 1;
        cartas[i].numero = numero_carta;

        if (numero_carta % 10 == 0)
        {
            cartas[i].puntos = 3;
        }
        else if (numero_carta % 5 == 0)
        {
            cartas[i].puntos = 2;
        }
        else if (numero_carta % 11 == 0)
        {
            cartas[i].puntos = 5;
        }
        else
        {
            cartas[i].puntos = 1;
        }
    }

    shuffle(cartas, 44);
    mazo mazo_cartas;
    init_mazo(&mazo_cartas);

    for (int i = 0; i < 44; i++)
    {
        push(&mazo_cartas, cartas[i]);
    }

    int players = 4;
    int pids[players];
    int pipes[players + 1][2];
    for (int i = 0; i < players; i++)
    {
        if (pipe(pipes[i]) == -1)
        {
            printf("Error creando el pipe\n");
            return 1;
        }
    }
    for (int i = 0; i < players; i++)
    {
        pids[i] = fork();
        if (pids[i] == -1)
        {
            printf("Error creando los procesos\n");
            return 2;
        }

        if (pids[i] == 0)
        {
            break;
        }
    }

    for (int i = 0; i < players; i++)
    {
        wait(NULL);
    }

    return 0;
}
