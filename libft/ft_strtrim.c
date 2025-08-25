#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start])) // Usamos ft_strchr
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1])) // Usamos ft_strchr
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *s1 = "###Hola, mundo###";
	char *set = "#";
	char *trimmed = ft_strtrim(s1, set);

	printf("Original: \"%s\"\n", s1);
	printf("Recortado: \"%s\"\n", trimmed);

	free(trimmed);
	return (0);
}
*/

/*
#include "libft.h"
#include <stdlib.h>

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
*/

/*
int main(void)
{
    const char *str = "   Hola Mundo   ";
    const char *set = " ";
    char *result;

    result = ft_strtrim(str, set);
    if (result)
    {
        printf("Cadena original: '%s'\n", str);
        printf("Cadena recortada: '%s'\n", result);
        free(result); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al recortar la cadena.\n");
    }

    return 0;
}

#include "libft.h"
#include <stdio.h>

int	main(void)
{
    char *s1 = "  Hola, mundo!  ";
    char *set = " ";
    char *trimmed = ft_strtrim(s1, set);

    printf("String original: \"%s\"\n", s1);
    printf("String recortada: \"%s\"\n", trimmed);

    free(trimmed);
    return (0);
}
*/

