#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (!needle[j + 1])
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *haystack = "Hola Mundo";
    const char *needle = "Mundo";
    char *result;

    result = ft_strnstr(haystack, needle, 10);
    if (result)
        printf("Encontrado: %s\n", result);
    else
        printf("No encontrado\n");

    return 0;
}
#include "libft.h"
#include <stdio.h>

int	main(void)
{
    char haystack[] = "Hola, mundo!";
    char needle[] = "mundo";

    char *result = ft_strnstr(haystack, needle, 12);

    if (result)
        printf("Encontrado 'mundo' en: %s\n", result);
    else
        printf("'mundo' no encontrado.\n");

    return (0);
}
*/