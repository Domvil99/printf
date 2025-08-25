#include "ft_printf.h"

static void	put_ptr(unsigned long n)
{
	char *base = "0123456789abcdef";
	if (n >= 16)
		put_ptr(n / 16);
	write(1, &base[n % 16], 1);
}

static int	count_digits_ptr(unsigned long n)
{
	int count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return count;
}

int	print_pointer(va_list args, t_format f)
{
	unsigned long	ptr = (unsigned long)va_arg(args, void *);
	int				digits = (f.has_precision && f.precision == 0 && ptr == 0) ? 0 : count_digits_ptr(ptr);
	int				total_len = digits + 2;
	int				space_pad = (f.width > total_len) ? f.width - total_len : 0;

	if (!f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	write(1, "0x", 2);
	if (digits > 0)
		put_ptr(ptr);

	if (f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	return (f.width > total_len) ? f.width : total_len;
}