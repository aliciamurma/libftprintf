/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:51:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:37:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int c)
{
	int				cont;
	char			*str;
	int				ret;

	str = "0123456789abcdef";
	cont = 0;
	ret = 0;
	if (c >= 16)
	{
		ret = ft_print_x(c / 16);
		if (ret == -1)
			return (-1);
		cont = cont + ret;
		ret = ft_print_x(c % 16);
		if (ret == -1)
			return (-1);
		cont = cont + ret;
	}
	else
	{
		if (write (1, &str[c], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_print_xmay(unsigned int c)
{
	int				cont;
	char			*str;
	int				ret;

	str = "0123456789ABCDEF";
	cont = 0;
	ret = 0;
	if (c >= 16)
	{
		ret = ft_print_xmay(c / 16);
		if (ret == -1)
			return (-1);
		cont = cont + ret;
		ret = ft_print_xmay(c % 16);
		if (ret == -1)
			return (-1);
		cont = cont + ret;
	}
	else
	{
		if (write (1, &str[c], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}
