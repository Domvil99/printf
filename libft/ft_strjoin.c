#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(len);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(joined + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (joined);
}
/*
int main(void)
{
    char *str1 = "Hola";
    char *str2 = " Mundo";
    char *result;

    result = ft_strjoin(str1, str2);
    if (result)
    {
        printf("Cadena unida: %s\n", result);
        free(result); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al unir las cadenas.\n");
    }

    return 0;
}

#include "libft.h"
#include <stdio.h>

int	main(void)
{
    char *s1 = "Hola, ";
    char *s2 = "mundo!";
    char *joined = ft_strjoin(s1, s2);

    if (!joined)
        printf("Error en strjoin\n");
    else
        printf("Cadena concatenada: %s\n", joined);

    free(joined);
    return (0);
}
*/