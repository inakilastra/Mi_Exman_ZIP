#include <unistd.h>
#include <stdio.h>

void ft_print_nbr(int i)
{
    char    *digits;

    digits = "0123456789";
    if (i > 9)                      // Si el número es mayor de 9 
        ft_print_nbr(i / 10);       // Lo divido y llamo recursivamente a la misma función
    write(1, &digits[i % 10], 1);   // Cuando es un sólo número escribo la posición del string que coincide "i"
}

/*
Ejemplo de ft_print_nbr
Para  ft_print_nbr(123)

Paso 01 123 mayor de 9 lo divido entre 10 --> 12,3 y llamo de nuevo a la función luego continuara con i = 123.
Paso 02 12 (12,3 en int es 12) mayor de 9 lo divido entre 10 --> 1,2 y llamo de nuevo a la función luego continuara con i = 12.
Paso 03 1 (1,2 en int es 1) menor de 9 -- > write(1, &digits[1 % 10], 1) el resto de la división es "1".

La función regresa a la llamada anterior (con i = 12) --> write(1, &digits[12 % 10], 1) el resto de la división es "2".

La función regresa a la llamada anterior (con i = 123) --> write(1, &digits[123 % 10], 1) el resto de la división es "3".

*/

int main(void)
{
    int i;

    i = 1;
    while (i < 101)                     // Si el contador e menor de 101, tambíen sirve if (i <= 100)
    {
        if ((i % 15) == 0)              // Si el número es múltiplo de 3 y múltiplo de 5, en su lugar imprime 'fizzbuzz'.
            write(1, "fizzbuzz", 8);
        else if ((i % 5) == 0)          // Si el número es múltiplo de 5, en su lugar imprime "buzz".
            write(1, "buzz", 4);
        else if ((i % 3) == 0)          // Si el número es múltiplo de 4, en su lugar imprime 'fizz'.
            write(1, "fizz", 4);
        else
            ft_print_nbr(i);            // LLamo a la función para imprimir el número
        write(1, "\n", 1);              // Escribo siempre un salto de linea
        i++;                            // Aumento el contador
    }
    return (0);
}

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.
--------------------------------------------------------------------------------
Escribe un programa que imprima los números del 1 al 100, cada uno separado por un
nueva línea.
Si el número es múltiplo de 3, en su lugar imprime 'fizz'.
Si el número es múltiplo de 5, en su lugar imprime "buzz".
Si el número es múltiplo de 3 y múltiplo de 5, en su lugar imprime 'fizzbuzz'.

Example:
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
*/