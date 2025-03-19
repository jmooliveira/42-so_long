/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:05:47 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/19 20:13:11 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long_2.c*/

#include "so_long.h"

void	ft_handle_collectable(t_game *game, int n_x, int n_y)
{
	int	i;

	i = 0;
	while (i < game->map->collectable)
	{
		if (game->img->image_collect->instances[i].x == n_x
			&& game->img->image_collect->instances[i].y == n_y)
		{
			game->img->image_collect->instances[i].enabled = false;
			game->map->collectable_now--;
			break ;
		}
		i++;
	}
	if (game->map->collectable_now == 0)
		mlx_image_to_window(game->mlx, game->img->image_final_exit,
			game->map->exit_x * 64, game->map->exit_y * 64);
}

void	ft_key_handle(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_move_player(game, 0, -1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_move_player(game, 0, 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_move_player(game, -1, 0);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_move_player(game, 1, 0);
}

void	ft_handle_exit(t_game *game)
{
	mlx_close_window(game->mlx);
	ft_printf("You won in %d moves!\n", ++game->map->mov);
	ft_free_game(game);
	exit(0);
}

void	ft_update_player_position(t_game *game, int x, int y)
{
	if (game->map->map[y][x] != 'E')
		game->map->map[y][x] = '0';
	game->player->player_x = x;
	game->player->player_y = y;
	if (game->map->map[y][x] != 'E')
		game->map->map[y][x] = 'P';
}

void	ft_update_player_texture(t_game *game, int x, int y)
{
	if (game->img->texture_player != NULL
		&& game->img->image_player->instances != NULL)
	{
		game->img->image_player->instances[0].x = x * 64;
		game->img->image_player->instances[0].y = y * 64;
	}
}
