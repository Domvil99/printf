#include "ft_printf.h"

int	print_char(va_list args, t_format f)
{
	char	c = (char)va_arg(args, int);
	int		len = 1;
	int		padding = (f.width > 1) ? f.width - 1 : 0;

	if (!f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);

	write(1, &c, 1);

	if (f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);

	return (len + ((f.width > 1) ? f.width - 1 : 0));
}