#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int main(void)
{
    char dest[20] = "Hola";
    const char *src = " Mundo";
    size_t size = sizeof(dest);

    size_t result = ft_strlcat(dest, src, size);
    printf("Cadena resultante: %s\n", dest);
    printf("Longitud total: %zu\n", result);

    return 0;
}

#include <stdio.h>

int	main(void)
{
    char dst[20] = "Hola";
    char src[] = ", mundo!";
    size_t len = ft_strlcat(dst, src, sizeof(dst));

    printf("Después de strlcat: %s\n", dst);
    printf("Longitud combinada: %zu\n", len);

    return (0);
}
*/