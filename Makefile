# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 19:28:53 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME := 

OBJS := $(MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a

INCLUDES := -I $(LIBFT_PATH)
HDRS :=

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " --> compiled $@"

%.o: %.c $(HDRS)
	@$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDES)

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH)

clean:
	@rm -fv $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -fv $(NAME)
	@rm -fv $(LIBFT)

re: fclean all

FORCE:

test: $(OBJS) $(LIBFT)
	@make test -C tests

.PHONY: all clean fclean re FORCE
