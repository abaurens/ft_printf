# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2019/01/10 15:09:26 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =   gcc
RM          =   rm -rf
CP          =   cp -rf
LINKER      =   gcc
NAME        =   ft_printf
LIBFT		=	./libft/libft.a
LIBBNUM		=	./libbignum/libbnum.a
SRCD        =   srcs
OBJD        =   objs

SRC         =   main.c	\
				\
				ft_printf.c		\
				ft_fprintf.c	\
				ft_sprintf.c	\
				ft_snprintf.c	\
				ft_asprintf.c	\
				ft_dprintf.c	\
				\
				convert/char.c					\
				convert/string.c				\
				convert/length.c				\
				convert/integer.c				\
				convert/percent.c				\
				convert/pointer.c				\
				convert/strerror.c				\
				convert/u_integer.c				\
				convert/double_hexa.c			\
				convert/double_compact.c		\
				convert/u_integer_hexa.c		\
				convert/wide_character.c		\
				convert/u_integer_octal.c		\
				convert/double_floating.c		\
				convert/u_integer_binary.c		\
				convert/double_scientific.c		\
				convert/iso_formated_date.c		\
				convert/non_printable_string.c	\
				convert/wide_character_string.c	\
				\
				core/core.c								\
				core/buffer.c							\
				core/big_num.c							\
				core/unicode.c							\
				core/ft_error.c							\
				core/parse_args.c						\
				core/list_manager.c						\
				core/float_round.c						\
				core/floating_point.c					\
				core/parser_functions.c					\
				core/argument_manager.c					\
				core/tostr_conv/ft_ldtoa.c				\
				core/tostr_conv/printf_lltoa.c			\
				core/tostr_conv/padded_lltoa.c			\
				core/tostr_conv/padded_ulltoa.c			\
				core/tostr_conv/padded_ulltoa_bin.c		\
				core/tostr_conv/padded_ulltoa_hexa.c	\
				core/tostr_conv/padded_ulltoa_octal.c

CFLAGS      +=  -I./includes -W -Wall -Wextra -Werror

OBJ         :=  $(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC         :=  $(addprefix $(SRCD)/,$(SRC))

CFLAGS      +=  -I$(dir $(LIBBNUM))includes -I$(dir $(LIBFT))includes
LDFLAGS     +=  -L$(dir $(LIBBNUM)) -lbnum -L$(dir $(LIBFT)) -lft

$(NAME):    $(LIBFT) $(LIBBNUM) $(OBJ)
	$(LINKER) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBFT):
	@make -C $(dir $(LIBFT))

$(LIBBNUM):
	@make -C $(dir $(LIBBNUM))

objs/%.o:   $(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

all:    $(NAME)

cleanlib:
	@make -C $(dir $(LIBFT)) clean
	@make -C $(dir $(LIBBNUM)) clean

cleand:
	$(RM) $(OBJD)

clean:	cleanlib cleand

fcleanlib:
	@make -C $(dir $(LIBFT)) fclean
	@make -C $(dir $(LIBBNUM)) fclean

fcleand:	cleand
	$(RM) $(NAME)

fclean:	fcleanlib fcleand

red:	fcleand all

relib:	fcleanlib all

re: fclean all

.PHONY: all clean fclean re
