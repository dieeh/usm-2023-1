#include "funcioneshelper.h"

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

    mazo fila1, fila2, fila3, fila4;
    mazo mazoj1, mazoj2, mazoj3, mazoj4;

    init_mazo(&fila1);
    init_mazo(&fila2);
    init_mazo(&fila3);
    init_mazo(&fila4);

    init_mazo(&mazoj1);
    init_mazo(&mazoj2);
    init_mazo(&mazoj3);
    init_mazo(&mazoj4);

    push(&fila1, pop(&mazo_cartas));
    push(&fila2, pop(&mazo_cartas));
    push(&fila3, pop(&mazo_cartas));
    push(&fila4, pop(&mazo_cartas));

    carta mano_jugador1[10], mano_jugador2[10], mano_jugador3[10], mano_jugador4[10];

    for (int i = 0; i < 10; i++)
    {
        push(&mazoj1, pop(&mazo_cartas));
        push(&mazoj2, pop(&mazo_cartas));
        push(&mazoj3, pop(&mazo_cartas));
        push(&mazoj4, pop(&mazo_cartas));
    }

    carta temp[MAX_SIZE] = transfer(&mazoj1);
    for (int i = 0; i < 10; i++)
    {
        mano_jugador1[i] = temp[i];
    }
    carta temp2[MAX_SIZE] = transfer(&mazoj2);
    for (int i = 0; i < 10; i++)
    {
        mano_jugador2[i] = temp2[i];
    }
    carta temp3[MAX_SIZE] = transfer(&mazoj3);
    for (int i = 0; i < 10; i++)
    {
        mano_jugador3[i] = temp3[i];
    }
    carta temp4[MAX_SIZE] = transfer(&mazoj4);
    for (int i = 0; i < 10; i++)
    {
        mano_jugador4[i] = temp4[i];
    }

    int players = 4;
    int pid;
    int pipePH[players][2];
    int pipeHP[players][2];
    for (int i = 0; i < players; i++)
    {
        if (pipe(pipePH[i]) == -1)
        {
            printf("Error creando el pipe\n");
            return 1;
        }
        if (pipe(pipeHP[i]) == -1)
        {
            printf("Error creando el pipe\n");
            return 1;
        }
    }
    int identificador = 0;
    for (int i = 0; i < players; i++)
    {
        pid = fork();
        identificador += 1;
        if (pid == -1)
        {
            printf("Error creando los procesos\n");
            return 2;
        }
        else if (pid == 0)
        {
            break;
        }
    }

    if (pid != 0)
    {
        for (int i = 0; i < players; i++)
        {
            close(pipePH[i][0]);
            close(pipeHP[i][1]);
        }
    }
    else
    {
        for (int i = 0; i < players; i++)
        {
            close(pipePH[i][1]);
            close(pipeHP[i][0]);
        }
    }

    return 0;
}
