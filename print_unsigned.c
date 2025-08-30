#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

/*
 * Convierte un unsigned int a cadena decimal.
 * Devuelve NULL si falla malloc.
 */
static char *ft_utoa(unsigned int n)
{
    int             len = 1;
    unsigned int    tmp = n;
    char            *str;

    while (tmp /= 10)
        len++;
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    while (len--)
    {
        str[len] = '0' + (n % 10);
        n /= 10;
    }
    return str;
}

/*
 * Imprime un número unsigned con ancho y precisión.
 * Corrige el double-free cambiando la cadena a NULL en caso de “.0” y “0”.
 */
int print_unsigned(va_list args, t_format f)
{
    unsigned int n = va_arg(args, unsigned int);
    char         *str = ft_utoa(n);
    int          num_len = str ? ft_strlen(str) : 0;
    int          zero_pad = 0;
    int          total;
    int          full_len;
    int          space_pad;

    /* Caso especial: precisión ".0" y valor 0 → no imprimir dígitos */
    if (f.has_precision && f.precision == 0 && n == 0)
    {
        free(str);
        str = NULL;
        num_len = 0;
    }

    if (f.has_precision && f.precision > num_len)
        zero_pad = f.precision - num_len;
    else if (!f.has_precision && f.zero_pad && !f.left_align && f.width > num_len)
        zero_pad = f.width - num_len;

    full_len  = num_len + zero_pad;
    space_pad = (f.width > full_len) ? f.width - full_len : 0;

    /* Espacios antes si no hay left_align */
    if (!f.left_align)
        while (space_pad-- > 0)
            write(1, " ", 1);

    /* Ceros por precisión o zero_pad */
    while (zero_pad-- > 0)
        write(1, "0", 1);

    /* Imprime la cadena si existe */
    if (num_len > 0 && str)
        write(1, str, num_len);

    /* Espacios después si hay left_align */
    if (f.left_align)
        while (space_pad-- > 0)
            write(1, " ", 1);

    total = (f.width > full_len) ? f.width : full_len;
    free(str);
    return total;
}