# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 11:42:13 by jemorais          #+#    #+#              #
#    Updated: 2025/02/11 19:59:46 by jemorais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Wunreachable-code -Ofast

LIBFT	=	./lib/libft
LIBMLX	=	./MLX42

LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HDRS	=	-I lib/include -I $(LIBMLX)/include

SRCS	=	src/so_long.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all: libmlx libft $(NAME)

libmlx:
	cmake -S $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) ${NAME}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all bonus

.PHONY: all clean fclean re libft
