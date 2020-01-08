# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 13:24:28 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 
SRC_FILES =
OBJ_FILES = $(SRC_FILES:%.c=%.o)
HDR_FILES =
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.c $(HDR_FILES) $(LIBFT)
	$(CC) -c $(CFLAGS) -o $@ $< -I./libft $(LIBFT)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ_FILES)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

test: $(OBJ_FILES) $(LIBFT)
	$(CC) -o $@ $^

.PHONY: all clean fclean re
