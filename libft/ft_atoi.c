#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}
/*
int main(void)
{
    const char *str = "   -12345abc";
    int result = ft_atoi(str);
    printf("El número convertido es: %d\n", result); // Debería imprimir -12345
    return 0;
}
int	main(void)
{
    printf("atoi('42') = %d\n", ft_atoi("42"));
    printf("atoi('-42') = %d\n", ft_atoi("-42"));
    printf("atoi('  123') = %d\n", ft_atoi("  123"));
    printf("atoi('abc42') = %d\n", ft_atoi("abc42"));
    return (0);
}
*/