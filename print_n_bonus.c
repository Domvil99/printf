#include "ft_printf.h"

int	print_n(va_list args, int printed_so_far)
{
	int	*ptr = va_arg(args, int *);
	if (ptr)
		*ptr = printed_so_far;
	return 0;
}