# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/01/31 12:45:59 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME1 := checker
NAME2 := push_swap

OBJS_SHARE := $(MINI_SOURCES_SHARE:%=objs/%.o)
OBJS_CHECK := $(MINI_SOURCES_CHECK:%=objs/%.o) objs/check_main.o 
OBJS_PU_SW := $(MINI_SOURCES_PU_SW:%=objs/%.o) objs/pu_sw_main.o
OBJS := $(OBJS_CHECK) $(OBJS_PU_SW) $(OBJS_SHARE)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := hdrs
INCLUDES := -I $(HDRS_PATH) -I $(LIBFT_PATH)
HDRS := $(HDRS_PATH)/share.h $(HDRS_PATH)/check.h $(HDRS_PATH)/pu_sw.h

PLUS := \033[38;5;40m+\033[0;00m
MINUS := \033[38;5;160m-\033[0;00m

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJS_CHECK) $(OBJS_SHARE) # REMOVE -g FLAG
	@$(CC) -g -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

$(NAME2): $(LIBFT) $(OBJS_PU_SW) $(OBJS_SHARE) # REMOVE -g FLAG
	@$(CC) -g -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS) # REMOVE -g FLAG
	@$(CC) -g -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " ${PLUS} $@"

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH) | sed -e $$'s/^/$(LIBFT_PATH): /'

clean: lclean
	@make clean -C $(LIBFT_PATH) | sed -e $$'s/^/$(LIBFT_PATH): /'

lclean:
	@rm -fv $(OBJS) | sed -e $$'s/^/ $(MINUS) /'

fclean: clean lfclean
	@rm -fv $(LIBFT) | sed -e $$'s/^/ $(MINUS) /'

lfclean: lclean
	@rm -fv $(NAME1) | sed -e $$'s/^/ $(MINUS) /'
	@rm -fv $(NAME2) | sed -e $$'s/^/ $(MINUS) /'

re: fclean all

lre: lfclean all

FORCE:

test: $(OBJS) $(LIBFT) FORCE
	@make test -C tests | sed -e $$'s/^/.\/tests /'

.PHONY: all clean fclean re FORCE
