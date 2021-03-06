# SRC_MAIN	=	./main.c \
# 				./colour.c \
# 				./window.c \
# 				./hooks.c \
# 				./image.c

SRC_MAIN	=	./main.c \
				./error.c \
				./map.c \
				./game.c \
				./sprites.c \
				./player.c \
				./render.c \
				./border_restrict.c \
				./free_pl.c \
				./key.c

SRC_GNL		=	./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c

OBJS_MAIN	=	${SRC_MAIN:.c=.o}

OBJS_GNL	=	${SRC_GNL:.c=.o}

INCLUDE		=	./so_long.h \
				./mlx_linux

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

CC			=	gcc -g3

RM			=	rm -f
LEAKS		=	valgrind --leak-check=full --show-leaks-kinds=all -s -q

NAME		=	so_long

all:		${NAME}

${NAME}:	${OBJS_MAIN} ${OBJS_GNL}
				${CC} ${OBJS_MAIN} ${OBJS_GNL} ${CFLAGS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o ${NAME}

%.o		:	%.c
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
				${RM} ${OBJS_MAIN}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re