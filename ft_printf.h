#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_format
{
	int		left_align;
	int		zero_pad;
	int		width;
	int		precision;
	int		has_precision;
	int		plus;
	int		space;
	int		hash;
	char	type;
}	t_format;

int	ft_printf(const char *format, ...);
int	handle_format(const char *format, va_list args, int *i);
int	parse_format(const char *format, t_format *f);
int	print_char(va_list args, t_format f);
int	print_str(va_list args, t_format f);
int	print_int(va_list args, t_format f);

#endif