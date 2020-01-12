# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/12 17:40:26 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ../srcs/mini_srcs
include ./srcs/tests_mini_srcs

NAME := test

OBJS := $(MINI_SOURCES:%=../objs/%.o)
TESTS_OBJS := $(TESTS_MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ../libft
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := ../hdrs
INCLUDES := -I $(LIBFT_PATH) -I $(HDRS_PATH)
HDRS := $(HDRS_PATH)/share.h $(HDRS_PATH)/check.h $(HDRS_PATH)/pu_sw.h

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
	@rm -fv $(NAME) | sed -e $$'s/^/ $(MINUS) /'

re: fclean all

.PHONY: all clean fclean re
