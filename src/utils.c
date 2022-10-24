/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:23:58 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:25:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

int	ft_putstr(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
		return (-1);
	while (s[cont] != '\0')
	{
		if (ft_putchar(s[cont]) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}
