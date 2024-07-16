#include <unistd.h>

int main(void)
{
    write(1, "z\n", 2); // Escribo siempre "z" y un salto de linea
    return (0);
}

// NO TE OLVIDES EN ESTE CASO DE PONER "2" O PONERLO ASI
// write(1, "z", 1);
// write(1, "\n", 1);

/*
Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the first 'z'
character it encounters in it, followed by a newline. If there are no
'z' characters in the string, the program writes 'z' followed
by a newline. If the number of parameters is not 1, the program displays
'z' followed by a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre la primera 'z'
carácter que encuentra en él, seguido de una nueva línea. si no hay
caracteres 'z' en la cadena, el programa escribe 'z' seguido
por una nueva línea. Si el número de parámetros no es 1, el programa muestra
'z' seguida de una nueva línea.

Example:
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
z$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
*/