# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 20:02:38 by jkasongo          #+#    #+#              #
#    Updated: 2021/05/23 14:31:35 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
INCLUDES = -I./includes

#source
SRCS_DIR = sources/
SRCS = ft_printf.c
SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) re -C ./libft
	@cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS_PREFIXED)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_PREFIXED)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

help	:
	@echo "all $(NAME) clean fclean re \033[0;32m help\033[0;39m"

.PHONY	: all clean fclean re bonus  help
