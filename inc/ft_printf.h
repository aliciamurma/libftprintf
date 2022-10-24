/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:33:13 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 15:40:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

# define SPECIFIERS "cspdiuxX%"

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
int		ft_putnumber(int n);
int		ft_strlen(char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_uns_itoa(unsigned int n);

int		ft_print_c(int c);
int		ft_print_s(char *c);
int		ft_print_x(unsigned int c);
int		ft_print_xmay(unsigned int c);
int		ft_print_d_i(int c);
int		ft_print_u(unsigned int c);
int		ft_print_p(void *p);

#endif
