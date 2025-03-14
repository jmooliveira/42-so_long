/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:09:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/14 19:08:45 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long.h*/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/include/libft.h"
# include "../lib/include/ft_printf.h"
// # include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define EXIT_SUCCESS 0
# define ERR_ARGS "Error\nInvalid Args\n"
# define ERR_EXT "Error\nExtention Invalid\n"
# define ERR_OPEN "Error\nError Open\n"
# define ERR_UNEX "Error\nUnexpected Error\n"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_image
{
	/* data */
}	t_image;

typedef struct s_player
{
	/* data */
}	t_player;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_image		*img;
	t_player	*player;
}	t_game;

// valgrind --leak-check=full --track-origins=yes ./so_long *.ber

void	ft_validate_input_file(char *file);
void	ft_validate_map(t_game *game);

void	ft_init_map(t_game	*game, char *file);
char	*get_next_line(int fd);

void	ft_message_error(const char *msg);
void	ft_message_error_and_free(t_game *game, const char *msg);
void	ft_free_game(t_game *game);
void	ft_free_map(char **ptr, int	ptr_len);

int		ft_ptrlen(char **ptr);

void	ft_set_map(t_game *game);

#endif
