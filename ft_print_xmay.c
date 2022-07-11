/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:51:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/04 12:24:21 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xmay(unsigned int c)
{
	int				cont;
	char			*str;

	str = "0123456789ABCDEF";
	cont = 0;
	if (c >= 16)
	{
		cont = cont + ft_print_xmay(c / 16);
		cont = cont + ft_print_xmay(c % 16);
	}
	else
	{
		write (1, &str[c], 1);
		cont++;
	}
	return (cont);
}
