# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/09 18:53:43 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ../srcs/mini_srcs
include ./srcs/tests_mini_srcs

NAME := test

OBJS := $(MINI_SOURCES:%=../objs/%.o)
TESTS_OBJS := $(TESTS_MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a

INCLUDES := -I $(LIBFT_PATH)
HDRS :=

PLUS = \033[38;5;40m+\033[0;00m
MINUS = \033[38;5;160m-\033[0;00m

all: $(NAME)

$(NAME): $(TESTS_OBJS) $(OBJS)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo " ${PLUS} $@"

%.o: %.c $(HDRS)
	@$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)
	@echo " ${PLUS} $@"

clean:
	@rm -fv $(TESTS_OBJS) | sed -e $$'s/^/ $(MINUS) /'

fclean: clean
	@rm -fv $(NAME)
	@echo " ${MINUS} ${NAME}"

re: fclean all

.PHONY: all clean fclean re
