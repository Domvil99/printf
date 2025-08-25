#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
}

/*
int main(void)
{
    char str[] = "Hola Mundo";
    int fd = 1; // 1 es el descriptor de archivo para stdout

    ft_putstr_fd(str, fd);

    return 0;
}

#include "libft.h"

int	main(void)
{
    ft_putstr_fd("Hola, mundo!\n", 1);
    return (0);
}
*/