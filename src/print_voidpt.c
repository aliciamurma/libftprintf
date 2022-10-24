/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_voidpt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:56:53 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:32:01 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printp(unsigned long long p)
{
	int					cont;
	char				*str;

	str = "0123456789abcdef";
	cont = 0;
	if (p >= 16)
	{
		cont = cont + ft_printp(p / 16);
		cont = cont + ft_printp(p % 16);
	}
	else
	{
		if (write (1, &str[p], 1) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

int	ft_print_p(void *p)
{
	int	cont;

	cont = 0;
	if (!p)
		return (ft_putstr("0x0"));
	if (write (1, "0x", 2) == -1)
		return (-1);
	return (ft_printp((unsigned long long) p) + 2);
}
