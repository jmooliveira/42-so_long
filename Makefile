# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 11:42:13 by jemorais          #+#    #+#              #
#    Updated: 2025/02/10 19:56:29 by jemorais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
#BONUS	=

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	./lib/libft
LIBMLX	=	./mlx

LIBS	=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HDRS	=	-I $(LIBFT)/include -I $(LIBMLX)/build -I include

SRCS	=	src/so_long.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all: libmlx libft $(NAME)

libmlx:
	cmake -S $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HDRS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

#bonus:
#$()
#	$

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all bonus

#bonus:

.PHONY: all clean fclean re libft bonus
