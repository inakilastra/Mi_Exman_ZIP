#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')  // Recorro el argumento
        i++;                // Aumento el contador        
    return (i - 1);         // Devuelvo el contador - 1 para obviar el cierre
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)                      // Si hay 2 argumentos
    {
        i = ft_strlen(argv[1]);         // Obtengo el tamaño del argumento, sin cierre
        while (argv[1][i] != '\0')      // Recorro el argumento en orden inverso
        {
            write(1, &argv[1][i], 1);   // Escribo el carácter
            i--;                        // Retrocedo el contador
        }
    }
    write(1, "\n", 1);                  // Escribo siempre un salto de linea
    return (0);
}

/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the string in reverse
followed by a newline.
If the number of parameters is not 1, the program displays a newline.
-------------------------------------------------- ------------------------------
Escribe un programa que tome una cadena y la muestre al revés
seguido de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea.

Examples:
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/