#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main(void)
{
    char c = 'A';
    int fd = 1; // 1 es el descriptor de archivo para stdout

    ft_putchar_fd(c, fd);

    return 0;
}
#include "libft.h"

int	main(void)
{
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
*/