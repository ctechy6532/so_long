# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 04:30:58 by ctechy            #+#    #+#              #
#    Updated: 2022/08/26 04:31:00 by ctechy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

SRC		=	ft_printf.c \
			ft_putchar.c \
			ft_print_dec.c \
			ft_print_string.c \
			ft_print_dec_un.c \
			ft_get_len.c \
			ft_print_hex.c \
			ft_print_ptr.c \

OBJS = ${SRC:.c=.o}

$(NAME) : ${OBJS}
		gcc $(CFLAGS) -c $(SRC)
		@ar rc ${NAME} ${OBJS}

all : $(NAME)
		@echo "building"

clean :
		@${RM} ${OBJS}
		@echo "clean all files *.0"

fclean : clean
		@${RM} ${NAME}
		@echo "clean libftprintf.a"

re : fclean all

.PHONY : all clean fclean re
