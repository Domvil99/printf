#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(1));  // Devuelve un puntero válido que puede pasarse a free()

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);

	ft_memset(ptr, 0, count * size);
	return (ptr);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	// Caso normal: Reserva 5 enteros
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf("Error en calloc\n");
		return (1);
	}
	printf("Caso normal:\n");
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);

	// Caso especial: count = 0
	arr = (int *)ft_calloc(0, sizeof(int));
	if (!arr)
		printf("Error en calloc (count = 0)\n");
	else
		printf("Caso count = 0: Puntero válido obtenido\n");
	free(arr);

	// Caso especial: size = 0
	arr = (int *)ft_calloc(5, 0);
	if (!arr)
		printf("Error en calloc (size = 0)\n");
	else
		printf("Caso size = 0: Puntero válido obtenido\n");
	free(arr);

	// Caso límite: malloc falla (simulación manual)
	arr = (int *)ft_calloc((size_t)-1, (size_t)-1);
	if (!arr)
		printf("Error esperado en calloc (overflow)\n");

	return (0);
}
*/


/*
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

int	main(void)
{
    int	*arr = (int *)ft_calloc(5, sizeof(int));

    if (!arr)
        printf("Error en calloc\n");
    else
    {
        for (int i = 0; i < 5; i++)
            printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return (0);
}
*/