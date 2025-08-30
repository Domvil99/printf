#include <unistd.h>    /* write() */
#include <stdlib.h>    /* NULL */
#include "libft/libft.h" /* ft_strlen() */
#include "ft_printf.h"

int print_reverse(va_list args, t_format f)
{
	char	*str;
	int		str_len;
	int		effective_len;
	int		padding;
	int		printed;
	int		i;

	/* Obtener la cadena y manejar NULL */
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	/* Longitud real y ajustada por precisión */
	str_len = (int)ft_strlen(str);
	if (f.has_precision && f.precision < str_len)
		effective_len = f.precision;
	else
		effective_len = str_len;

	padding = 0;
	printed = 0;

	/* Espacios antes si no hay alineación izquierda */
	if (!f.left_align)
	{
		while (padding++ < f.width - effective_len)
			printed += write(1, " ", 1);
	}

	/* Imprime en orden inverso */
	i = effective_len - 1;
	while (i >= 0)
	{
		printed += write(1, &str[i], 1);
		--i;
	}

	/* Espacios después si hay alineación izquierda */
	if (f.left_align)
	{
		while (padding++ < f.width - effective_len)
			printed += write(1, " ", 1);
	}

	return (printed);
}