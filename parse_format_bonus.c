#include "libft.h"
#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%' ||
			c == 'b' || c == 'n' || c == 'r');
}

int	parse_format(const char *format, t_format *f)
{
	int	i = 0;

	*f = (t_format){0, 0, 0, 0, 0, 0, 0, 0, 0};

	while (is_flag(format[i]))
	{
		if (format[i] == '-')
			f->left_align = 1;
		else if (format[i] == '0')
			f->zero_pad = 1;
		else if (format[i] == '+')
			f->plus = 1;
		else if (format[i] == ' ')
			f->space = 1;
		else if (format[i] == '#')
			f->hash = 1;
		i++;
	}

	while (ft_isdigit(format[i]))
	{
		f->width = f->width * 10 + (format[i] - '0');
		i++;
	}

	if (format[i] == '.')
	{
		f->has_precision = 1;
		i++;
		while (ft_isdigit(format[i]))
		{
			f->precision = f->precision * 10 + (format[i] - '0');
			i++;
		}
	}

	if (is_type(format[i]))
	{
		f->type = format[i];
		i++;
	}

	return (i);
}