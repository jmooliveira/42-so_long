/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:09:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/16 21:26:22 by jeff             ###   ########.fr       */
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
# define ERR_INVALID_CHAR "Error\nInvalid Char\n"
# define ERR_MAP_OPEN "Error\nMap Open\n"
# define ERR_INVALID_MAP "Error\nInvalid Map: verify E, P or C\n"
# define ERR_SQUARE_MAP "Error\nSquare Map\n"
# define ERR_SQUARE_MAP "Error\nSquare Map\n"
# define ERR_TOO_SHORT "Error\nMap Too Short"
# define ERR_LINE_SIZE "Error\nDifferent Line Size "

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		collectable;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		mov;
}	t_map;

typedef struct s_image
{
	/* data */
}	t_image;

typedef struct s_player
{
	int		player_x;
	int		player_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_image		*img;
	t_player	*player;
}	t_game;


void	ft_validate_input_file(char *file);
void	ft_validate_map(t_game *game);
bool	ft_check_line_size(t_game *game);

void	ft_init_map(t_game	*game, char *file);
char	*get_next_line(int fd);
void	ft_set_map(t_game *game);
void	ft_set_char(t_game *game, char c, int i, int j);
bool	ft_limits_map(t_game *game);

void	ft_message_error(const char *msg);
void	ft_message_error_and_free_map(t_game *game, const char *msg);
void	ft_free_game_final(t_game *game);
void	ft_free_map(char **ptr, int	ptr_len);
void	ft_message_error_and_free_game(t_game *game, const char *msg);

int		ft_ptrlen(char **ptr);

#endif

// valgrind --leak-check=full --track-origins=yes ./so_long *.ber
