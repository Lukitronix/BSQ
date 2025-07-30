#include "bsq.h"

void	ft_putstr(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (*(str + i))
			i++;
		write(1, str, i);
	}
}

void		ft_putnbr(int nbr)
{
	int	count;
	int	temp;

	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	temp = nbr;
	count = 1;
	while ((temp /= 10))
		count *= 10;
	while (count)
	{
		ft_putchar((nbr / count) + '0');
		nbr %= count;
		count /= 10;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}