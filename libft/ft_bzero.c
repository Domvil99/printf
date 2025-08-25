#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
int main(void)
{
    char str[50] = "Hola Mundo";
    printf("Cadena original: %s\n", str);
    ft_bzero(str, 5);
    printf("Cadena después de ft_bzero: %s\n", str);
    return 0;
}
/*
int	main(void)
{
    char str[] = "Hola Mundo!";
    printf("Antes bzero: %s\n", str);
    ft_bzero(str, 5);
    printf("Después bzero (primeros 5 bytes): %s\n", str + 2);
    return (0);
}
*/