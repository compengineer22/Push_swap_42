# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 16:23:36 by hsrour            #+#    #+#              #
#    Updated: 2026/03/17 17:42:46 by hsrour           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS  = -Wall -Wextra -Werror

NAME    = push_swap

SRC     = main.c \
	handle/handle_less.c \
	handle/handler.c \
	handle/handler2.c \
	handle/input_handle.c \
	helpers/free_stack.c \
	helpers/ft_printf.c \
	helpers/ft_puthex.c \
	helpers/ft_putnbru.c \
	helpers/ft_split.c \
	helpers/list_helper.c \
	helpers/ft_atoi.c \
	helpers/ft_putchar.c \
	helpers/ft_putnbr.c \
	helpers/ft_putstr.c \
	helpers/ft_strlen.c \
	helpers/math.c \
	operations/push_functions.c \
	operations/rotate_functions.c \
	operations/reverse_rotate_functions.c \
	operations/swap_functions.c \
	sorting/bench.c \
	sorting/complex.c \
	sorting/medium.c \
	sorting/medium_helper.c \
	sorting/simple.c

OBJ     = $(SRC:.c=.o)

# 🔥 ADD THIS
INCLUDES = -I.

INC     = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
