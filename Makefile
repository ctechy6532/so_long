CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm -f
SRC =	srcs/so_long.c \
		srcs/map_init.c \
		srcs/img.c \
		srcs/error.c \
		srcs/move.c \
		srcs/check_path.c \
		srcs/count.c \
		srcs/check_map.c \
		srcs/check_map_utils.c \


OBJS = ${SRC:.c=.o}
LIBFT = make -C libft/
PRINTF = make -C printf/
HEADER = -I./includes -I./libft -I./printf
MLX = -lmlx -framework OpenGL -framework AppKit  $^ -o $@

.c.o :
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : ${OBJS}
		@$(LIBFT)
		@$(PRINTF)
		@$(CC) $(MLX) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)
clean :
		@${RM} ${OBJS} libft/*.o printf/*.o
		@echo "clean all files *.o"

fclean : clean
		@${RM} ${NAME} libft/*.o libft/*.a printf/*.o printf/*.a
		@echo "clean libft.a libftprintf.a"

re : fclean all

.PHONY : all clean fclean re