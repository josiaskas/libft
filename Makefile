# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 20:02:38 by jkasongo          #+#    #+#              #
#    Updated: 2021/05/21 20:28:06 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#source
SRCS = ft_printf.c
#objs
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))


all : $(NAME)

$(NAME) : $(OBJS_PREFIXED)
	 ar rc -o $(NAME).a $^
	 ranlib $(NAME).a

bonus : $(OBJS_PREFIXED)
	@echo "bonus"

$(OBJS_DIR)%.o : %.c ft_printf.h 
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	@rm -rf $(OBJS_DIR)
	@echo "erasing objects"

fclean : clean
	@rm -f $(NAME).a
	@echo "erasing executable"

re: fclean all

help	:
	@echo "all $(NAME) clean fclean re \033[0;32m help\033[0;39m"

.PHONY	: all clean fclean re bonus  help
