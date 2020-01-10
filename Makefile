# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/10 13:54:08 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./srcs/mini_srcs

NAME1 := checker
NAME2 := push_swap

OBJS_SHARE := $(MINI_SOURCES_SHARE:%=./objs/%.o)
OBJS_CHECK := $(MINI_SOURCES_CHECK:%=./objs/%.o)
OBJS_PU_SW := $(MINI_SOURCES_PU_SW:%=./objs/%.o)
OBJS := $(OBJS_CHECK) $(OBJS_PU_SW) $(OBJS_SHARE)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ./libft
LIBFT_PATH_SED := .\/libft
LIBFT := $(LIBFT_PATH)/libft.a


INCLUDES := -I $(LIBFT_PATH)
HDRS :=

PLUS := \033[38;5;40m+\033[0;00m
MINUS := \033[38;5;160m-\033[0;00m

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_CHECK) $(OBJS_SHARE) $(LIBFT)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

$(NAME2): $(OBJS_PU_SW) $(OBJS_SHARE) $(LIBFT)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

./objs/%.o: ./srcs/%.c $(HDRS)
	@$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDES)
	@echo " ${PLUS} $@"

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH) | sed -e $$'s/ / $(LIBFT_PATH_SED)\//2'

clean: lclean
	@make clean -C $(LIBFT_PATH) | sed -e $$'s/ / $(LIBFT_PATH_SED)\//2'

lclean:
	@rm -fv $(OBJS) | sed -e $$'s/^/ $(MINUS) /'

fclean: clean lfclean
	@rm -fv $(LIBFT) | sed -e $$'s/^/ $(MINUS) /'

lfclean:
	@rm -fv $(NAME) | sed -e $$'s/^/ $(MINUS) /'

re: fclean all

FORCE:

test: $(OBJS) $(LIBFT)
	@make test -C tests | sed -e $$'s/1/.\/tests\//'

.PHONY: all clean fclean re FORCE
