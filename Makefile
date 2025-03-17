#makefile

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	./lib
LIB		=	$(LIBFT)/libft.a

LIBMLX	=	./mlx
LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADER	=	-I ./lib/include -I $(LIBMLX)/build

SRCS	=	src/main.c \
			src/validate.c \
			src/free_and_errors.c \
			src/init_map.c \
			src/so_long.c \
			src/utils.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< ${HEADER}

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
