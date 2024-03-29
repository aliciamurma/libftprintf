/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:58:14 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:23:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_what_is(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_print_c(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_print_p(va_arg(ptr, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_d_i(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_print_u(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_print_x(va_arg(ptr, unsigned int)));
	else if (c == 'X')
		return (ft_print_xmay(va_arg(ptr, int)));
	if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		cont;
	int		cont_s;
	int		ret;

	cont = 0;
	cont_s = 0;
	va_start(ptr, str);
	while (str[cont_s] != '\0')
	{
		if (str[cont_s] == '%' && str[cont_s + 1])
		{
			ret = ft_what_is(ptr, str[cont_s + 1]);
			if (ret == -1)
				return (-1);
			cont = cont + ret;
			cont_s += 2;
		}
		else
		{
			if (write (1, &str[cont_s], 1) == -1)
				return (-1);
			cont++;
			cont_s++;
		}
	}
	va_end(ptr);
	return (cont);
}
