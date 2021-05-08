# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 02:21:09 by jkasongo          #+#    #+#              #
#    Updated: 2021/05/07 22:22:31 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Librairie personnel pour les projets en C
NAME = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#source
SRCS = $(wildcard ft_*.c)

#bonus source
BONUS_SRCS = $(wildcard ft_*_bonus.c)
#test source
TEST_SRCS = $(wildcard test_*.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)
OBJS_TEST = $(TEST_SRCS:.c=.o)

#quelques args
.PHONY	: all clean fclean re test help

all	: $(NAME)

#linking objects
$(NAME)	: $(OBJS)
	ar rc $(NAME).a $^
	ranlib $(NAME).a

bonus	: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME)_bonus.a $^
	ranlib $(NAME)_bonus.a

%.o	: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	@rm -f *.o
	@echo "cleaning objects"

fclean	: clean
	@rm -f $(NAME).a $(NAME)_bonus.a $(NAME)
	@rm -f test
	@echo "erasing  executable"

re	: fclean all

#run a test
test: fclean all $(OBJS_TEST)
	@$(CC) $(CFLAGS) -o test $(OBJS_TEST) -L. -lft
	@chmod 555 test
	@echo "making a test with the library"
	./test

help	:
	@echo "all $(NAME) clean fclean re \033[0;32mtest help\033[0;39m"
