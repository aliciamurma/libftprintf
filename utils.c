#include "ft_printf.h"

int	ft_putnumber(int n)
{
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (11);
	}	
	if (n < 0)
	{
		n = n * -1;
		if (ft_putchar('-') == -1)
			return (-1);
	}
	if (n > 9)
	{
		ft_putnumber(n / 10);
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	}
	else
		if (ft_putchar(n + '0') == -1)
			return (-1);
	return (n);
}

int	ft_strlen(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		cont++;
	return (cont);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
		return (0);
	while (s[cont] != '\0')
	{
		if (ft_putchar(s[cont]) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

static int	ft_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uns_itoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (len > 0 && n > 9)
	{
		str[len - 1] = ((n % 10) + '0');
		n = (n / 10);
		len--;
	}
	if (n >= 0 && n < 10)
		str[len - 1] = (n + '0');
	return (str);
}
