/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:20:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:39:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digits(int n)
{
	int	d;

	d = 0;
	if (n < 0)
	{
		d++;
		while (n <= -1)
		{
			n /= 10;
			d++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= 10;
			d++;
		}
	}
	return (d);
}

static void	ft_transform_number(char *num, int digits, int n)
{
	int	i;

	i = 0;
	num[digits] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		i++;
	}
	while (i < digits)
	{
		if (n < 0)
			num[digits - i] = -(n % 10) + '0';
		else
			num[digits - i - 1] = (n % 10) + '0';
		i++;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*num;

	if (n == 0)
		digits = 1;
	else
		digits = ft_get_digits(n);
	num = (char *)malloc(sizeof(char) * (digits + 1));
	if (num == NULL)
		return (NULL);
	ft_transform_number(num, digits, n);
	return (num);
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
