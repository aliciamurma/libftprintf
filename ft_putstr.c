/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:06:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/05/31 10:04:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
		return (0);
	while (s[cont] != '\0')
	{
		ft_putchar(s[cont]);
		cont++;
	}
	return (cont);
}
