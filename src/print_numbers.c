/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:56:23 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:38:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(int c)
{
	char	*str;
	int		cont;

	str = ft_itoa(c);
	cont = ft_putstr(str);
	free(str);
	return (cont);
}

int	ft_print_u(unsigned int c)
{
	char	*str;
	int		cont;

	str = ft_uns_itoa(c);
	cont = ft_putstr(str);
	free(str);
	return (cont);
}
