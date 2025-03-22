/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:32 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/21 17:39:50 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long_1.c*/

#include "so_long.h"

void	ft_so_long(t_game *game)
{
	t_image	*image;

	image = ft_calloc(1, sizeof(t_image));
	game->img = image;
	game->mlx = mlx_init(game->map->width * 64,
			game->map->height * 64, "so_long", false);
	ft_upload_images(game, game->img);
	ft_put_image(game, game->img);
	mlx_key_hook(game->mlx, &ft_key_handle, game);
	mlx_loop(game->mlx);
}

void	ft_upload_images(t_game *game, t_image *img)
{
	img->texture_floor = mlx_load_png("./assets/grasss.png");
	img->image_floor = mlx_texture_to_image(game->mlx, img->texture_floor);
	mlx_delete_texture(img->texture_floor);
	img->texture_wall = mlx_load_png("./assets/tree1.png");
	img->image_wall = mlx_texture_to_image(game->mlx, img->texture_wall);
	mlx_delete_texture(img->texture_wall);
	mlx_resize_image(img->image_wall, 50, 64);
	img->texture_player = mlx_load_png("./assets/wolf0.png");
	img->image_player = mlx_texture_to_image(game->mlx, img->texture_player);
	mlx_delete_texture(img->texture_player);
	mlx_resize_image(img->image_player, 50, 50);
	img->texture_collect = mlx_load_png("./assets/sheep.png");
	img->image_collect = mlx_texture_to_image(game->mlx, img->texture_collect);
	mlx_delete_texture(img->texture_collect);
	mlx_resize_image(img->image_collect, 40, 32);
	img->texture_exit = mlx_load_png("./assets/exit.png");
	img->image_exit = mlx_texture_to_image(game->mlx, img->texture_exit);
	mlx_delete_texture(img->texture_exit);
	mlx_resize_image(img->image_exit, 32, 32);
	img->texture_final_exit = mlx_load_png("./assets/house.png");
	img->image_final_exit = mlx_texture_to_image(game->mlx,
			img->texture_final_exit);
	mlx_delete_texture(img->texture_final_exit);
	mlx_resize_image(img->image_final_exit, 64, 64);
}

void	ft_put_image(t_game *game, t_image *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i, game->map->map[i])
	{
		j = -1;
		while (++j, game->map->map[i][j])
		{
			mlx_image_to_window(game->mlx, img->image_floor, j * 64, i * 64);
			if (game->map->map[i][j] == '1')
				mlx_image_to_window(game->mlx, img->image_wall,
					j * 64 + 7, i * 64);
			if (game->map->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, img->image_collect,
					j * 64 + 12, i * 64 + 16);
			if (game->map->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, img->image_exit,
					j * 64 + 16, i * 64 + 16);
		}
	}
	mlx_image_to_window(game->mlx, img->image_player,
		game->player->player_x * 64 + 7, game->player->player_y * 64 + 7);
}

void	ft_move_player(t_game *game, int x, int y)
{
	int	n_x;
	int	n_y;

	n_x = game->player->player_x + x;
	n_y = game->player->player_y + y;
	if (n_x < 0 || n_y < 0 || n_x >= game->map->width
		|| n_y >= game->map->height)
		return ;
	if (game->map->map[n_y][n_x] == '1')
		return ;
	if (game->map->map[n_y][n_x] == 'C')
	{
		ft_handle_collectable(game, n_x * 64 + 12, n_y * 64 + 16);
		game->map->map[n_y][n_x] = '0';
	}
	if (game->map->map[n_y][n_x] == 'E'
			&& game->map->collectable_now == 0)
		ft_handle_exit(game);
	ft_update_player_texture(game, n_x, n_y);
	ft_update_player_position(game, n_x, n_y);
	game->map->mov++;
	ft_printf("%d moves\n", game->map->mov);
}
