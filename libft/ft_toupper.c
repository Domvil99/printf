#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int main(void)
{
    char lower = 'a';
    char upper = 'A';

    printf("ft_toupper('%c') = '%c'\n", lower, ft_toupper(lower));
    printf("ft_toupper('%c') = '%c'\n", upper, ft_toupper(upper));

    return 0;
}
*/
/*
#include <stdio.h>

int	main(void)
{
    printf("ft_toupper('a') = %c\n", ft_toupper('a'));   // 'A'
    printf("ft_toupper('z') = %c\n", ft_toupper('z'));   // 'Z'
    printf("ft_toupper('A') = %c\n", ft_toupper('A'));   // 'A' (sin cambio)
    printf("ft_toupper('1') = %c\n", ft_toupper('1'));   // '1' (sin cambio)
    return (0);
}
*/

