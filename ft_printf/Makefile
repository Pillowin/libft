# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:52:43 by agautier          #+#    #+#              #
#    Updated: 2020/11/10 13:02:51 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRC			=	$(wildcard src/*.c) $(wildcard src/ft_print/*.c)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
HEADER_DIR	=	header
LIB_DIR		=	lib
LIBFT		=	ft

all: $(NAME)

$(NAME): $(OBJ)
	cp lib/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	# rm -f $(LIBFT)
	ranlib $(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test norme
