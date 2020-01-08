# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 17:35:15 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME := 

OBJS := $(MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

HDRS :=

LIBFT_PATH := ./libft
LIBFT := $(LIB_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ $(LIBFT)

%.o: %.c $(HDRS)
	$(CC) -c $(CFLAGS) -o $@ $< -I$(LIBFT_PATH)

$(LIBFT): FORCE
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

FORCE:

test: $(OBJS) $(LIBFT)
	make test -C tests

.PHONY: all clean fclean re FORCE
