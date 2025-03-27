# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 13:24:11 by kel-bahr          #+#    #+#              #
#    Updated: 2025/01/05 09:48:55 by kel-bahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putaddress.c ft_putchar.c ft_putstr.c ft_puthexa.c ft_putnbr.c ft_putunbr.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
