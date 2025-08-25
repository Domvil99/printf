#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    int n;

    // Flags: +, espacio, #
    ft_printf("Signo +: [%+d]\n", 42);
    ft_printf("Signo + negativo: [%+d]\n", -42);
    ft_printf("Espacio: [% d]\n", 42);
    ft_printf("Espacio negativo: [% d]\n", -42);
    ft_printf("Hex con #: [%#x]\n", 255);
    ft_printf("Hex con # y 0: [%#08x]\n", 255);
    ft_printf("Hex 0 con #: [%#x]\n", 0);

    // Flags: -, 0, ancho mínimo, precisión
    ft_printf("Left align: [%-10s]\n", "Domvil");
    ft_printf("Zero pad: [%010d]\n", 42);
    ft_printf("Width + precision: [%10.5d]\n", 42);
    ft_printf("Precision 0 y valor 0: [%.0d]\n", 0);

    // %b - Binario
    ft_printf("Binario: [%b]\n", 42);
    ft_printf("Binario 0: [%b]\n", 0);
    ft_printf("Binario UINT_MAX: [%b]\n", UINT_MAX);

    // %n - Número de caracteres impresos
    ft_printf("Antes de %n guardar posición\n", &n);
    ft_printf("Valor guardado en n: [%d]\n", n);

    // %r - String en reversa
    ft_printf("Reverse: [%r]\n", "Domvil");
    ft_printf("Reverse vacío: [%r]\n", "");
    ft_printf("Reverse NULL: [%r]\n", NULL);

    // Combinaciones complejas
    ft_printf("Mix: [%+10.5d]\n", 123);
    ft_printf("Mix hex: [%#08X]\n", 48879);
    ft_printf("Mix string: [%-20.10s]\n", "Hola desde printf");

    return 0;
}