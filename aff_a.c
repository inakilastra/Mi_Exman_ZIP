#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 2)                  // Si no hay 2 argumentos
        write(1, "a", 1);           // Escribo "a"
    else
    {
        while (argv[1][i] != '\0')  // Recorro el argumento
        {
            if (argv[1][i] == 'a')  // Si hay "a" en el argumento
            {
                write(1, "a", 1);   // Escribo "a"
                break ;             // Salgo del bucle, ya que si hubiera varias "a" pintaria varias
            }
            i++;
        }
    }
    write(1, "\n", 1);              // Escribo un salto de linea
    return (0);
}

/*
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the first 'a' 
character it encounters in it, followed by a newline. If there are no 
'a' characters in the string, the program just writes a newline. 
If the number of parameters is not 1, the program displays 'a' 
followed by a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome un string y muestre el primer cáracter 'a'
que encuentre en él, seguido de una nueva línea. si no hay
caracteres 'a' en el string, el programa simplemente escribe una nueva línea.
Si el número de parámetros no es 1, el programa muestra 'a'
seguido de una nueva línea.

Example:
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/