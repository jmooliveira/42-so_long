/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:09:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/19 20:08:15 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long.h*/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/include/libft.h"
# include "../lib/include/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
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
# define ERR_LINE_SIZE "Error\nDifferent Line Size\n"
# define ERR_NO_PATH "Error\nNo Path Find\n"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		collectable;
	int		collectable_now;
	int		player;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		mov;
}	t_map;

typedef struct s_image
{
	mlx_texture_t	*texture_floor;
	mlx_image_t		*image_floor;
	mlx_texture_t	*texture_wall;
	mlx_image_t		*image_wall;
	mlx_texture_t	*texture_collect;
	mlx_image_t		*image_collect;
	mlx_texture_t	*texture_exit;
	mlx_image_t		*image_exit;
	mlx_texture_t	*texture_final_exit;
	mlx_image_t		*image_final_exit;
	mlx_texture_t	*texture_player;
	mlx_image_t		*image_player;
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
	char		**copy_map;
}	t_game;

// validate.c
void	ft_validate_input_file(char *file);
void	ft_validate_map(t_game *game);
bool	ft_check_line_size(t_game *game);
bool	ft_limits_map(t_game *game);
int		ft_ptrlen(char **ptr);

// init_map.c
void	ft_init_map(t_game	*game, char *file);
char	*get_next_line(int fd);
void	ft_set_map(t_game *game);
void	ft_set_char(t_game *game, char c, int i, int j);
void	ft_message_error(const char *msg);

// free_and_errors.c
void	ft_message_error_and_free_map(t_game *game, const char *msg);
void	ft_free_game(t_game *game);
void	ft_free_map(char **ptr, int ptr_len);
void	ft_message_error_and_free_game(t_game *game, const char *msg);
void	ft_cleanup_game(t_game *game);

//so_long.c
void	ft_so_long(t_game *game);
void	ft_upload_images(t_game *game, t_image *img);
void	ft_put_image(t_game *game, t_image *img);
void	ft_move_player(t_game *game, int x, int y);

//handle.c
void	ft_handle_collectable(t_game *game, int n_x, int n_y);
void	ft_key_handle(mlx_key_data_t keydata, void *param);
void	ft_handle_exit(t_game *game);
void	ft_update_player_position(t_game *game, int x, int y);
void	ft_update_player_texture(t_game *game, int x, int y);

//flood_fill.c
void	ft_flood_fill(t_game *game);
void	ft_copy_map(t_game *game);
void	flood_fill(t_game *game, int x, int y);
void	ft_verify_flood_fill(t_game *game);
void	ft_error_flood(t_game *game, const char *msg);

#endif

// valgrind --leak-check=full --track-origins=yes ./so_long *.ber
