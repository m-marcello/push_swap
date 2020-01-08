# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 17:32:32 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ../srcs/mini_srcs
include ./srcs/tests_mini_srcs

NAME := test

OBJS := $(MINI_SOURCES:%=../objs/%.o)
TESTS_OBJS := $(TESTS_MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

HDRS :=

LIBFT_PATH := ../libft
LIBFT := $(LIB_PATH)/libft.a

all: $(NAME)
	@echo $(TESTS_OBJS)

$(NAME): $(TESTS_OBJS) $(OBJS)
	$(CC) -o $@ $^ -lcriterion $(LIBFT)

%.o: %.c $(HDRS)
	$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)

clean:
	rm -f $(TESTS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
