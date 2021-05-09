# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 02:21:09 by jkasongo          #+#    #+#              #
#    Updated: 2021/05/09 03:56:26 by jkasongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Librairie personnel pour les projets en C
NAME = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#source
SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c\
		ft_memccpy.c ft_memmove.c ft_memchr.c\
		ft_memcmp.c ft_strlen.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strchr.c ft_strrchr.c ft_strncmp.c\
		ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_isspace.c ft_putstr.c ft_strndup.c\
		ft_free_array.c\

BONUS_SRCS = $(wildcard ft_*_bonus.c)
TEST_SRCS = $(wildcard test_*.c)

#objects
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)
TEST_DIR = test/
OBJS_TEST = $(TEST_SRCS:.c=.o)
#prefixing for space in folder while working
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS_BONUS))
OBJS_TEST_PREFIXED = $(addprefix $(TEST_DIR), $(OBJS_TEST))

#quelques args reservEs
.PHONY	: all clean fclean re bonus test help

all	: $(NAME)

#linking objects
$(NAME)	: $(OBJS_PREFIXED)
	ar rc $(NAME).a $^
	ranlib $(NAME).a

$(OBJS_DIR)%.o	: %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(TEST_DIR)%.o	: %.c libft.h
	@mkdir -p $(TEST_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus	: $(OBJS_PREFIXED) $(OBJS_BONUS_PREFIXED)
	@ar rc $(NAME).a $^
	@ranlib $(NAME).a

clean	:
	@rm -rf $(OBJS_DIR)
	@echo "cleaning objects"

fclean	: clean
	@rm -f $(NAME).a test_prog
	@rm -rf $(TEST_DIR)
	@echo "erasing  executable"

re	: fclean all

#run a test
test: fclean bonus $(OBJS_TEST_PREFIXED)
	@$(CC) $(CFLAGS) -o test_prog $(OBJS_TEST_PREFIXED) -L. -lft
	@chmod 555 test_prog
	@echo "making a test with the library"
	@./test_prog

help	:
	@echo "all $(NAME) clean fclean re \033[0;32mtest bonus help\033[0;39m"
