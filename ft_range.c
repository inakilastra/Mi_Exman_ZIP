#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// IMPORTANTE Se "castea" a long los int porque el tamaño entre -2147483648 y 2147483647 es long
int *ft_range(int start, int end)           

{
    int     *range;
    long    len;
    int     i;

    i = 0;
    if (start > end)                            // Si start es mayor que end
        len = (long)start - (long)end + 1;      // "len" start - end + 1 (este "+ 1" es para que se incluya start y end)
                                                // Ejemplo 3 - 1 = 2 sin embargo falta por incluir un número 3,2,1 son "3"
    if (end > start)                            // Si end es mayor que start
        len = (long)end - (long)start + 1;
    range = (int *)malloc(sizeof(int) * len);   // reservo memoria para los 11 carácteres y el cierre
    if (!range)                                 // Protego el malloc
        return (NULL);
    if (start == end)                           // Si start y end son iguales
        range[i] = start;                       // Asigno start (o end) y paso a devorver, en el caso de los "int" no es necesario el cierre
    else                                        // Si start y end no son iguales
    {
        while (i < len)                         // Recorro el contador "i" mientras sea menor que el tamaño "len"
        {
            if (start > end)                    // Si start es mayor que end
                range[i++] = start--;           // Asigno start y le resto 1 aumento el contador "i" despues de asignar
            else
                range[i++] = start++;           // Asigno start y le sumo 1 aumento el contador "i" despues de asignar
        }
    }   
    return (range);
}

/* 
int main(int argc, char **argv)
{
    int     *myrange;
    int     i;
    int     start;
    int     end;
    int     len;

    int     *numbers;
    numbers = ft_range(0, 0);
    printf("%d, ", numbers[0]);
    printf("%d, ", numbers[1]);
    printf("%d\n", numbers[2]);

    (void)argc;
    i = 0;
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    if (start > end)
        len = start - end + 1;
    else
        len = end - start + 1;
    myrange = ft_range(start, end);
    printf("start %d end %d\n", start, end);
    while (i < len)
    {
        printf("%d, ", myrange[i]);
        i++;
    }     
    return (0);
}
*/

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int     *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
--------------------------------------------------------------------------------
Escribe la siguiente función:
int *ft_range(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros, llenarla con números consecutivos
valores que comienzan al principio y terminan al final (¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/