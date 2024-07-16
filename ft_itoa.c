#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*
LA FUNCION STRNCPY la puedes generar desde la ayuda:
man strncpy

char *
           strncpy(char *dest, const char *src, size_t n)
           {
               size_t i;

               for (i = 0; i < n && src[i] != '\0'; i++)
                   dest[i] = src[i];
               for ( ; i < n; i++)
                   dest[i] = '\0';

               return dest;
           }

TUNEALA añadiendo "ft_" y transformando los "for" en un simple while
*/

int ft_nbrlen(int nbr)      // Función para contar los digitos del número y el signo en caso de negativo
{
    int i;

    i = 0;
    if (nbr < 0)            // Si el número es menor de 0 (negativo)
    {
        i++;                // Cuento uno por el signo negativo
        nbr = nbr * (-1);   // convierto el número en positivo
    }
    while (nbr > 0)         // Recorro el número mientras sea mayor que 0
    {
        i++;                // Cuento el digito
        nbr = nbr / 10;     // Divido el número entre 10 (me muevo entre unidades, decenas, centenas...)
    }
    return(i);              // Devuelvo el número de digitos incluyendo el signo en caso de negativo
}

char *ft_itoa(int nbr)
{
    char    *myitoa;
    int     len;

    myitoa = "";
    len = 0;
    if (nbr == -2147483648)                             // Si nbr es igual a 2147483648 (debajo tienes un truco para obtener este número)
    {
        myitoa = (char *)malloc(sizeof(char) * 12);     // reservo memoria para los 11 carácteres y el cierre
        if (!myitoa)                                    // Protego el malloc
            return (NULL);
        myitoa[11] = '\0';                              // Cierro en la última posición
        ft_strncpy(myitoa, "-2147483648", 11);          // Copio 11 los carácteres con ft_strncpy
        return (myitoa);                                // Devuelvo el puntero al string
    }
    if (nbr == 0)                                       // Si nbr es igual a 0
    {
        myitoa = (char *)malloc(sizeof(char) * 2);      // reservo memoria para el carácter y el cierre
        if (!myitoa)                                    // Protego el malloc
            return (NULL);
        myitoa[1] = '\0';                               // Cierro en la última posición
        myitoa[0] = '0';                                // Asigno el carácter "0" en la primera posición
        return (myitoa);                                // Devuelvo el puntero al string
    }    
    char *digits = "0123456789";
    len = ft_nbrlen(nbr);                               // Obtengo el número de digitos y signo para reservar el tamaño
    myitoa = (char *)malloc(sizeof(char) * (len + 1));  // reservo memoria para el tamaño y el cierre
    if(!myitoa)                                         // Protego el malloc
        return (NULL);
    myitoa[len] = '\0';                                 // Cierro en la última posición
    if (nbr < 0)                                        // Si nbr es negativo
    {
        myitoa[0] = '-';                                // Agsino el signo "-" en la primera posición
        nbr = nbr * (-1);                               // convierto el número en positivo
    }
    while (nbr > 0)                                     // Recorro el número mientras sea mayor que 0
    {
        myitoa[--len] = digits[nbr % 10];               // Primero disminuyo el contador ya que esta en la ultima posición y luego asigno el digito obtenido del resto de la división entre 10. Pri
        nbr = nbr / 10;                                 // Divido el número entre 10 (me muevo entre unidades, decenas, centenas...)
    }
    return (myitoa);
}

/* 
int main(void)
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(-2147483648));
    printf("%s\n", ft_itoa(1));
    printf("%s\n", ft_itoa(12));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-4));
    printf("%s\n", ft_itoa(-23));
    return (0);
}
*/

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
Your function must be declared as follows:
char	*ft_itoa(int nbr);
--------------------------------------------------------------------------------
Escribe una función que tome un int y lo convierta en una cadena terminada en nulo.
La función devuelve el resultado en una matriz de caracteres que debes asignar.
Su función debe declararse de la siguiente manera:
char *ft_itoa(int nbr);
*/

/*
Truco para obtener el número max INT
un "int" esta formado por 32 bits
Positivos y negativos (enteros con signo): del -2147483648 al 2147483647

En un terminal ejecuta "bc"  (Basic Calculator)
pones 2 ^ 31 y obtienes 2147483648
para salir "quit"
*/