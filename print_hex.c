#include "ft_printf.h"

static void	put_hex(unsigned int n, int upper)
{
	char *base = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, upper);
	write(1, &base[n % 16], 1);
}

static int	count_digits_hex(unsigned int n)
{
	int count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return count;
}

int	print_hex(va_list args, t_format f)
{
	unsigned int	n = va_arg(args, unsigned int);
	int				digits = (f.has_precision && f.precision == 0 && n == 0) ? 0 : count_digits_hex(n);
	int				zero_pad = (f.has_precision && f.precision > digits) ? f.precision - digits : 0;
	int				prefix = (f.hash && n != 0) ? 2 : 0;
	int				total_len = digits + zero_pad + prefix;
	int				space_pad = (f.width > total_len) ? f.width - total_len : 0;

	if (!f.left_align && (!f.zero_pad || f.has_precision))
		while (space_pad-- > 0)
			write(1, " ", 1);

	if (prefix)
		write(1, f.type == 'x' ? "0x" : "0X", 2);

	if (!f.left_align && f.zero_pad && !f.has_precision)
		while (space_pad-- > 0)
			write(1, "0", 1);

	while (zero_pad-- > 0)
		write(1, "0", 1);

	if (digits > 0)
		put_hex(n, f.type == 'X');

	if (f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	return (f.width > total_len) ? f.width : total_len;
}