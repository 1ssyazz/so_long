SRC_MAIN	=	./main.c \
				./colour.c \
				./window.c \
				./hooks.c \
				./image.c

OBJS_MAIN	=	${SRC_MAIN:.c=.o}

INCLUDE		=	./so_long.h \
				./mlx_linux

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc -g3

RM			=	rm -f
LEAKS		=	valgrind --leak-check=full --show-leaks-kinds=all -s -q

NAME		=	so_long

all:		${NAME}

${NAME}:	${OBJS_MAIN}
				${CC} ${OBJS_MAIN} ${CFLAGS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

%.o		:	%.c
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
				${RM} ${OBJS_MAIN}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re