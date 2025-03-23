#makefile

NAME	=	so_long
NAME_BONUS	=	so_long_bonus

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	./lib
LIBMLX	=	./MLX42
LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADER	=	-I ./lib/include -I $(LIBMLX)/build

SRCS	=	src/main.c \
			src/validate.c \
			src/free_and_errors.c \
			src/init_map.c \
			src/so_long.c \
			src/handle.c \
			src/flood_fill.c \

SRCS_BONUS	=	bonus/main_bonus.c \
				bonus/validate_bonus.c \
				bonus/free_and_errors_bonus.c \
				bonus/init_map_bonus.c \
				bonus/so_long_bonus.c \
				bonus/handle_bonus.c \
				bonus/flood_fill_bonus.c \

OBJS	=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

RM		=	rm -rf

all: libft libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< ${HEADER}

bonus: libmlx libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT) fclean

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long

.PHONY: all clean fclean re
