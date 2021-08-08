# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 02:21:09 by jkasongo          #+#    #+#              #
#    Updated: 2021/08/07 22:06:47 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Librairie personnel pour les projets en C
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

#source
SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memccpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
		ft_strrev.c \
		ft_atoi.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strndup.c ft_isspace.c\
		 ft_lstadd_back.c ft_lstclear.c ft_lstlast.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstdelone.c \
		ft_lstiter.c ft_lstmap.c ft_lstsize.c\
		ft_printf.c ft_parse_arg_type.c ft_parse_flag.c\
		ft_parse_precision.c ft_parse_width.c \
		ft_printf_utils.c ft_printf_itoa.c ft_solve_char.c\
		ft_solve_str.c ft_solve_pointer.c ft_solve_int.c\
		ft_solve_unsigned.c ft_solve_hexadecimal.c ft_solve_pourcentage.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@echo "libft.a builded"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

help:
	@echo "all $(NAME) clean fclean re \033[0;32m help\033[0;39m"

.PHONY:		all clean fclean re help
