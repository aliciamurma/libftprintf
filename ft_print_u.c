/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:50:53 by amurcia-          #+#    #+#             */
/*   Updated: 2022/05/30 14:47:26 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int c)
{
	char	*str;
	int		cont;

	str = ft_uns_itoa(c);
	cont = ft_putstr(str);
	free(str);
	return (cont);
}
