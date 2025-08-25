#include "ft_printf.h"

static char	*ft_utoa(unsigned int n)
{
	int		len = 1;
	unsigned int tmp = n;
	while (tmp /= 10)
		len++;
	char *str = malloc(len + 1);
	if (!str)
		return NULL;
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return str;
}

int	print_unsigned(va_list args, t_format f)
{
	unsigned int	n = va_arg(args, unsigned int);
	char			*str = ft_utoa(n);
	int				num_len = ft_strlen(str);
	int				zero_pad = 0;
	int				total = 0;

	if (f.has_precision && f.precision == 0 && n == 0)
	{
		free(str);
		str = "";
		num_len = 0;
	}

	if (f.has_precision && f.precision > num_len)
		zero_pad = f.precision - num_len;

	if (!f.has_precision && f.zero_pad && !f.left_align && f.width > num_len)
		zero_pad = f.width - num_len;

	int full_len = num_len + zero_pad;
	int space_pad = (f.width > full_len) ? f.width - full_len : 0;

	if (!f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	while (zero_pad-- > 0)
		write(1, "0", 1);

	if (num_len > 0)
		write(1, str, num_len);

	if (f.left_align)
		while (space_pad-- > 0)
			write(1, " ", 1);

	total = (f.width > full_len) ? f.width : full_len;
	free(str);
	return total;
}