# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/08 13:49:01 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC_TEST_FILES = criterion_test.c
OBJ_TEST_FILES = $(SRC_TEST_FILES:%.c=%.o)
HDR_FILES =
CFLAGS = 
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_TEST_FILES)
	$(CC) -o $@ $^ ../src/*.o 

%.o: %.c $(HDR_FILES) $(LIBFT)
	$(CC) -c $(CFLAGS) -o $@ $< -I../libft -lcriterion $(LIBFT)

clean:
	rm -f $(OBJ_TEST_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
