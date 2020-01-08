# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 19:28:54 by mmarcell      ########   odam.nl          #
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

all: $(NAME)

$(NAME): $(TESTS_OBJS) $(OBJS)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo " --> compiled $@"

%.o: %.c $(HDRS)
	@$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)

clean:
	@rm -fv $(TESTS_OBJS)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re
