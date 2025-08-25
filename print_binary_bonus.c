#include "ft_printf.h"

static void	put_binary(unsigned int n)
{
	if (n >= 2)
		put_binary(n / 2);
	write(1, (n % 2) ? "1" : "0", 1);
}

int	print_binary(va_list args, t_format f)
{
	unsigned int	n = va_arg(args, unsigned int);
	unsigned int	tmp = n;
	int				digits = (n == 0) ? 1 : 0;
	int				zero_pad = 0;
	int				total = 0;

	while (tmp)
	{
		tmp /= 2;
		digits++;
	}

	if (f.has_precision && f.precision > digits)
		zero_pad = f.precision - digits;

	int	full_len = digits + zero_pad;
	int	space_pad = (f.width > full_len) ? f.width - full_len : 0;

	if (!f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	while (zero_pad-- > 0)
		write(1, "0", 1);

	if (digits > 0)
		put_binary(n);

	if (f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	total = (f.width > full_len) ? f.width : full_len;
	return total;
}