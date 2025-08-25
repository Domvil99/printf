#include "ft_printf.h"

int	print_str(va_list args, t_format f)
{
	char	*str = va_arg(args, char *);
	int		len;
	int		padding;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (f.has_precision && f.precision < len)
		len = f.precision;

	padding = (f.width > len) ? f.width - len : 0;

	if (!f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);

	write(1, str, len);

	if (f.left_align)
		while (padding-- > 0)
			write(1, " ", 1);

	return (len + ((f.width > len) ? f.width - len : 0));
}