#include "ft_printf_bonus.h"

int	print_reverse(t_format f, va_list args)
{
	char	*str;
	int		str_len;
	int		effective_len;
	int		padding;
	int		printed;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	// Convertimos ft_strlen a int para evitar conflictos de tipo
	str_len = (int)ft_strlen(str);
	if (f.precision >= 0 && f.precision < str_len)
		effective_len = f.precision;
	else
		effective_len = str_len;

	padding = 0;
	printed = 0;

	// Si no hay flag '-', imprimimos espacios antes
	if (!f.minus)
	{
		while (padding++ < f.width - effective_len)
			printed += write(1, " ", 1);
	}

	// Imprimimos la cadena en orden inverso, respetando la precisión
	for (int i = effective_len - 1; i >= 0; i--)
		printed += write(1, &str[i], 1);

	// Si hay flag '-', imprimimos espacios después
	if (f.minus)
	{
		while (padding++ < f.width - effective_len)
			printed += write(1, " ", 1);
	}

	return (printed);
}