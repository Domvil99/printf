#include "ft_printf.h"
/*
int main(void)
{
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hola Domvil");
    ft_printf("Pointer: %p\n", (void *)0x1234abcd);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 3000000000);
    ft_printf("Hex lower: %x\n", 255);
    ft_printf("Hex upper: %X\n", 255);
    ft_printf("Percent: %%\n");
    return 0;
} 
*/
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // %c - Caracteres
    ft_printf("Char: [%c]\n", 'A');
    ft_printf("Char NULL: [%c]\n", '\0');

    // %s - Strings
    ft_printf("String: [%s]\n", "Hola Domvil");
    ft_printf("Empty string: [%s]\n", "");
    ft_printf("NULL string: [%s]\n", (char *)NULL);

    // %p - Punteros
    int x = 42;
    ft_printf("Pointer: [%p]\n", &x);
    ft_printf("NULL pointer: [%p]\n", NULL);

    // %d / %i - Enteros con signo
    ft_printf("Decimal positivo: [%d]\n", 123);
    ft_printf("Decimal negativo: [%d]\n", -123);
    ft_printf("INT_MAX: [%d]\n", INT_MAX);
    ft_printf("INT_MIN: [%d]\n", INT_MIN);
    ft_printf("Integer: [%i]\n", 456);

    // %u - Enteros sin signo
    ft_printf("Unsigned: [%u]\n", 3000000000U);
    ft_printf("Unsigned 0: [%u]\n", 0);
    ft_printf("UINT_MAX: [%u]\n", UINT_MAX);

    // %x / %X - Hexadecimal
    ft_printf("Hex lower: [%x]\n", 255);
    ft_printf("Hex upper: [%X]\n", 255);
    ft_printf("Hex 0: [%x]\n", 0);
    ft_printf("Hex UINT_MAX: [%X]\n", UINT_MAX);

    // %% - Porcentaje
    ft_printf("Percent: [%%]\n");

    return 0;
}