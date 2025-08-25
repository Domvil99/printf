#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int main(void)
{
    const char *str1 = "dfghjkl";
    const char *str2 = "Hola Mundo";
    int result;

    result = ft_strncmp(str1, str2, 4);
    printf("Resultado de la comparación: %d\n", result);

    return 0;
}