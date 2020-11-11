# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:52:43 by agautier          #+#    #+#              #
#    Updated: 2020/11/11 14:42:09 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRC			= $(wildcard src/*.c)
OBJ			= $(SRC:.c=.o)
HEADER		= header
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
PRINTF		= ft_printf
PRINTFLIB	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PRINTF)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)
	rm $(NAME)
	mv $(PRINTF)/$(PRINTFLIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	make clean -C $(PRINTF)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
