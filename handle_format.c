#include "ft_printf.h"

int	handle_format(const char *format, va_list args, int *i)
{
	t_format	f;
	int			len;

	len = 0;
	*i += parse_format(format, &f);

	if (f.type == 'c')
		len += print_char(args, f);
	else if (f.type == 's')
		len += print_str(args, f);
	else if (f.type == 'd' || f.type == 'i')
		len += print_int(args, f);
	else if (f.type == 'u')
		len += print_unsigned(args, f);
	else if (f.type == 'x' || f.type == 'X')
		len += print_hex(args, f);
	else if (f.type == 'p')
		len += print_pointer(args, f);
	else if (f.type == '%')
		len += write(1, "%", 1);

	return (len);
}