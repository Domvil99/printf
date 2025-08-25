#include "ft_printf.h"

static void	print_padding(int count, char c)
{
	while (count-- > 0)
		write(1, &c, 1);
}

int	print_int(va_list args, t_format f)
{
	int		n = va_arg(args, int);
	char	*num_str;
	int		num_len;
	int		total_len = 0;
	int		is_negative = (n < 0);
	int		sign_printed = 0;

	// Convertimos el número a string
	num_str = ft_itoa(n < 0 ? -n : n);
	num_len = ft_strlen(num_str);

	// Caso especial: número 0 y precisión 0 → no imprimir nada
	if (f.has_precision && f.precision == 0 && n == 0)
	{
		free(num_str);
		num_str = "";
		num_len = 0;
	}

	// Calculamos ceros por precisión
	int	zero_pad = 0;
	if (f.has_precision && f.precision > num_len)
		zero_pad = f.precision - num_len;

	// Si no hay precisión pero hay zero_pad y no hay alineación izquierda
	if (!f.has_precision && f.zero_pad && !f.left_align && f.width > (num_len + is_negative))
		zero_pad = f.width - num_len - is_negative;

	// Calculamos longitud total del número con ceros y signo
	int	full_len = num_len + zero_pad + is_negative;

	// Añadir espacio o + si es positivo
	if (!is_negative && (f.plus || f.space))
		full_len++;

	// Padding con espacios si no hay alineación izquierda
	if (!f.left_align && f.width > full_len)
	{
		print_padding(f.width - full_len, ' ');
		total_len += f.width - full_len;
	}

	// Imprimir signo
	if (is_negative)
		write(1, "-", 1);
	else if (f.plus)
		write(1, "+", 1);
	else if (f.space)
		write(1, " ", 1);

	sign_printed = is_negative || f.plus || f.space;
	total_len += sign_printed;

	// Imprimir ceros
	print_padding(zero_pad, '0');
	total_len += zero_pad;

	// Imprimir número (si hay algo que imprimir)
	if (num_len > 0)
	{
		write(1, num_str, num_len);
		total_len += num_len;
	}

	// Padding a la derecha si hay alineación izquierda
	if (f.left_align && f.width > full_len)
	{
		print_padding(f.width - full_len, ' ');
		total_len += f.width - full_len;
	}

	if (num_len > 0)
		free(num_str);
	return (total_len);
}