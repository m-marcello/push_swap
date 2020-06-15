# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell      #+#    #+#                  #
#    Updated: 2020/06/11 15:53:03 by mmarcell      ########   odam.nl          #
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

LIBFT_PATH := libft/
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := hdrs
INCLUDES := -I $(HDRS_PATH) -I $(LIBFT_PATH)
HDRS := $(HDRS_PATH)/share.h $(HDRS_PATH)/check.h $(HDRS_PATH)/pu_sw.h

PLUS := $$(tput setaf 2)+$$(tput sgr0)
MINUS := $$(tput setaf 1)-$$(tput sgr0)

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJS_CHECK) $(OBJS_SHARE)
	@$(CC) $^ -L$(LIBFT_PATH) -lft -o $@
	@echo " ${PLUS} $@"

$(NAME2): $(LIBFT) $(OBJS_PU_SW) $(OBJS_SHARE)
	@$(CC) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS) | objs
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<

objs:
	@mkdir -p $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@rm -rf $(LIBFT_PATH)/objs
	@rm -rf objs

fclean: clean
	@rm -fv $(LIBFT) | sed "s/^/ $(MINUS) /"
	@rm -fv $(NAME1) | sed "s/^/ $(MINUS) /"
	@rm -fv $(NAME2) | sed "s/^/ $(MINUS) /"

re: fclean all

FORCE:

.PHONY: all clean fclean re
