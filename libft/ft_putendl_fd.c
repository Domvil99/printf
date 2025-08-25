#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*

int main(void)
{
    char str[] = "Hola Mundo";
    int fd = 1; // 1 es el descriptor de archivo para stdout

    ft_putendl_fd(str, fd);

    return 0;
}
    #include "libft.h"

int	main(void)
{
    ft_putendl_fd("Hola, mundo!", 1);
    return (0);
}
*/
