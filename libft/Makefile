# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 19:33:18 by dkovalen          #+#    #+#              #
#    Updated: 2017/03/24 15:35:31 by dkovalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

HEADER =			./libft_functions/includes/libft.h
PRINTF_SRC_HEADER =	./printf_functions/includes

SRCO_libft_functions			= 	./libft_functions/ft_lstiter.o	./libft_functions/ft_putendl.o	./libft_functions/ft_strdup.o	./libft_functions/ft_strnequ.o ./libft_functions/ft_lstmap.o	./libft_functions/ft_putendl_fd.o	./libft_functions/ft_strequ.o					\
						./libft_functions/ft_strnew.o ./libft_functions/ft_atoi.o	./libft_functions/ft_lstnew.o	./libft_functions/ft_putnbr.o	./libft_functions/ft_striter.o	./libft_functions/ft_strnstr.o ./libft_functions/ft_bzero.o	./libft_functions/ft_memalloc.o	./libft_functions/ft_putnbr_fd.o		\
						./libft_functions/ft_striteri.o	./libft_functions/ft_strrchr.o ./libft_functions/ft_isalnum.o	./libft_functions/ft_memccpy.o	./libft_functions/ft_putstr.o	./libft_functions/ft_strjoin.o ./libft_functions/ft_strjoin2.o	./libft_functions/ft_strsplit.o ./libft_functions/ft_isalpha.o					\
						./libft_functions/ft_memchr.o	./libft_functions/ft_putstr_fd.o	./libft_functions/ft_strlcat.o	./libft_functions/ft_strstr.o ./libft_functions/ft_isascii.o	./libft_functions/ft_memcmp.o	./libft_functions/ft_reduce.o	./libft_functions/ft_strlcpy.o	./libft_functions/ft_strsub.o \
						./libft_functions/ft_isdigit.o	./libft_functions/ft_memcpy.o	./libft_functions/ft_strcat.o	./libft_functions/ft_strlen.o	./libft_functions/ft_strtrim.o ./libft_functions/ft_isprint.o	./libft_functions/ft_memdel.o	./libft_functions/ft_strchr.o	./libft_functions/ft_strmap.o			\
						./libft_functions/ft_tolower.o ./libft_functions/ft_itoa.o	./libft_functions/ft_memmove.o	./libft_functions/ft_strclr.o	./libft_functions/ft_strmapi.o	./libft_functions/ft_toupper.o ./libft_functions/ft_lstadd.o	./libft_functions/ft_memset.o	./libft_functions/ft_strcmp.o		\
						./libft_functions/ft_strncat.o ./libft_functions/ft_lstdel.o	./libft_functions/ft_putchar.o	./libft_functions/ft_strcpy.o	./libft_functions/ft_strncmp.o ./libft_functions/ft_lstdelone.o	./libft_functions/ft_putchar_fd.o	./libft_functions/ft_strdel.o	./libft_functions/ft_strncpy.o


PRINTF_COMPILED =	./printf_functions/create_type.o ./printf_functions/create_type_adds.o ./printf_functions/adress_wch.o ./printf_functions/str_c.o ./printf_functions/w_chars.o ./printf_functions/ft_printf.o ./printf_functions/itoa_bases_counts.o ./printf_functions/itoa_bases.o ./printf_functions/int_plus.o\
					./printf_functions/int_space.o ./printf_functions/print_int.o ./printf_functions/print_int_dot_small.o ./printf_functions/print_int_dot.o ./printf_functions/colors.o ./printf_functions/print_memory.o

all: $(NAME)

$(NAME): $(PRINTF_COMPILED)
	@ make -C ./libft_functions
	@ar rc $(NAME) $(PRINTF_COMPILED) $(SRCO_libft_functions)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(PRINTF_COMPILED): %.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $< -I $(PRINTF_SRC_HEADER)
clean:
	@-/bin/rm -f $(PRINTF_COMPILED)
	@-/bin/rm -f $(SRCO_libft_functions)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
