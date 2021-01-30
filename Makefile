# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:52:43 by agautier          #+#    #+#              #
#    Updated: 2021/01/30 15:40:05 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_atoi_base.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_div_mod.c \
			ft_fibonacci.c \
			ft_find_next_prime.c \
			ft_free.c \
			ft_get_whitespaces.c \
			ft_ilen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_is_prime.c \
			ft_isprint.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_latoi.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putlnbr.c \
			ft_putlstr.c \
			ft_putnbr_base.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstr_non_printable.c \
			ft_putulnbr_base.c \
			ft_putunbr_base.c \
			ft_range.c \
			ft_recursive_factorial.c \
			ft_recursive_power.c \
			ft_rev_int_tab.c \
			ft_sort_int_tab.c \
			ft_split.c \
			ft_split_charset.c \
			ft_sqrt.c \
			ft_strcapitalize.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_str_is_alpha.c \
			ft_str_is_lowercase.c \
			ft_str_is_numeric.c \
			ft_str_is_printable.c \
			ft_str_is_uppercase.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlchr.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strlowcase.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strtrim.c \
			ft_strupcase.c \
			ft_substr.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_ultimate_div_mod.c \
			ft_ultimate_range.c \
			get_next_line.c
OBJ		=	$(SRC:.c=.o)
HEADER	=	header
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
