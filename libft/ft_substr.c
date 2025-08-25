#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
/*
int main(void)
{
    const char *str = "Hola Mundo";
    char *sub;

    sub = ft_substr(str, 5, 5);
    if (sub)
    {
        printf("Subcadena: %s\n", sub);
        free(sub); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al crear la subcadena.\n");
    }

    return 0;
}
   #include "libft.h"
#include <stdio.h>

int	main(void)
{
    char *original = "Hola, mundo!";
    char *sub1 = ft_substr(original, 5, 5);
    char *sub2 = ft_substr(original, 20, 5);

    printf("Subcadena (5,5): %s\n", sub1);
    printf("Subcadena (fuera de límites): %s\n", sub2);

    free(sub1);
    free(sub2);
    return (0);
} 
*/