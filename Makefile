# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 10:30:18 by amurcia-          #+#    #+#              #
#    Updated: 2022/05/30 16:39:01 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c print_chars.c ft_print_x.c ft_print_d_i.c ft_print_u.c ft_print_p.c ft_print_xmay.c utils.c ft_itoa.c

OBJ = $(SRC:%.c=%.o)

HEADER = ft_printf.h

CC = gcc
FLAGS = -Werror -Wextra -Wall

%.o : %.c
	@$(CC) ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar -crs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
