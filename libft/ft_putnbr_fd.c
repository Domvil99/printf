#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648) // Manejo de INT_MIN
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0) // Si es negativo, imprimimos '-' y convertimos a positivo
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10) // Si es mayor o igual a 10, llamamos recursivamente a la función
		ft_putnbr_fd(n / 10, fd);
	char c = (n % 10) + '0'; // Convertimos el último dígito a carácter
	write(fd, &c, 1);
}
/*
int main(void)
{
    int fd = 1; // 1 es el descriptor de archivo para stdout
    ft_putnbr_fd(12345, fd);
    write(fd, "\n", 1); // Para nueva línea
    ft_putnbr_fd(-12345, fd);
    write(fd, "\n", 1); // Para nueva línea
    ft_putnbr_fd(-2147483648, fd);
    write(fd, "\n", 1); // Para nueva línea
    return 0;
}

#include "libft.h"

int	main(void)
{
    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);
    return (0);
}

*/


/*
#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*num_str;

	num_str = ft_itoa(n); // Convertimos el número a string
	if (!num_str)
		return; // Si falla malloc, no imprimimos nada
	ft_putstr_fd(num_str, fd); // Imprimimos la string con ft_putstr_fd
	free(num_str); // Liberamos la memoria reservada por ft_itoa
}

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648) // Manejo especial de INT_MIN
	{
		ft_putstr_fd("-2147483648", fd);
		return;
	}
	if (n < 0) // Si es negativo, imprimimos '-' y convertimos a positivo
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10) // Si el número tiene más de un dígito, lo dividimos
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd); // Imprimimos el último dígito
} 
*/