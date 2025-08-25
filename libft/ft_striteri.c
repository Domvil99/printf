#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main(void)
{
 s   char str[] = "Hola Mundo";
    ft_striteri(str, ft_toupper);
    printf("Cadena después de ft_striteri: %s\n", str);
    return 0;
}
#include "libft.h"
#include <stdio.h>

void	to_upper(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int	main(void)
{
    char str[] = "hola, mundo!";
    ft_striteri(str, to_upper);
    printf("String modificada: %s\n", str);
    return (0);
}    
*/