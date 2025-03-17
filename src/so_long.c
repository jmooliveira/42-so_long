/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:32 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/17 17:18:53 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long.c*/

#include "so_long.h"

void	ft_so_long(t_game *game)
{
	t_image	*image;

	image = ft_calloc(1, sizeof(t_image));
	game->mlx = mlx_init(game->map->width * 64, game->map->height * 64, "so_long", false);
	ft_upload_images(game);
	ft_put_image(game);
	mlx_loop(game->mlx);
}

void	ft_upload_images(t_game *game)
{
	game->img->texture_floor = mlx_load_png("../assets/grasss.png");
	game->img->image_floor = mlx_texture_to_image(game->mlx, game->img->texture_floor);
	mlx_delete_texture(game->img->texture_floor);
}

void	ft_put_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			mlx_image_to_window(game->mlx, game->img->image_floor, i * 64, j *64);
			j++;
		}
		i++;
	}
}
