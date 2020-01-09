# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/09 18:51:03 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME1 := checker
NAME2 := push_swap

OBJS_SHARE := $(MINI_SOURCES_SHARE:%=objs/%.o)
OBJS_CHECK := $(MINI_SOURCES_CHECK:%=objs/%.o)
OBJS_PU_SW := $(MINI_SOURCES_PU_SW:%=objs/%.o)
OBJS := $(OBJS_CHECK) $(OBJS_PU_SW) $(OBJS_SHARE)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a

INCLUDES := -I $(LIBFT_PATH)
HDRS :=

PLUS = \033[38;5;40m+\033[0;00m
MINUS = \033[38;5;160m-\033[0;00m

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_CHECK) $(OBJS_SHARE) $(LIBFT)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

$(NAME2): $(OBJS_PU_SW) $(OBJS_SHARE) $(LIBFT)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS)
	@$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDES)
	@echo " ${PLUS} $@"

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH)

clean: lclean
	@make clean -C $(LIBFT_PATH)

lclean:
	@rm -fv $(OBJS) | sed -e $$'s/^/ $(MINUS) /'

fclean: clean lfclean
	@rm -fv $(LIBFT)

lfclean:
	@rm -fv $(NAME)

re: fclean all

FORCE:

test: $(OBJS) $(LIBFT)
	@make test -C tests

.PHONY: all clean fclean re FORCE
