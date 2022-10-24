# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = libftprintf.a


SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = printf.c print_chars.c print_numbers.c print_voidpt.c print_hexa.c utils.c ft_itoa.c
INC = -I $(INC_DIR)
	  
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP             = $(addsuffix .d, $(basename $(OBJ)))

CC = gcc

CFLAGS 			= -Werror -Wall -Wextra -MMD $(INC)
RM_DIR          = rm -rf
MKDIR           = mkdir -p

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c Makefile
	@$(MKDIR) $(dir $@)
	@gcc -c -g $(CFLAGS) -o $@ $<
	@echo "Compiling..."

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ) $(HEADER)
	@ar -crs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

PHONY: clean re fclean all
