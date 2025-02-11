/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:46:56 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/11 19:58:53 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_hook(void* param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->player.y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->player.y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player.x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player.x += 5;
	mlx_image_to_window(game->mlx, game->player.image, game->player.x, game->player.y);
}

int main(int ac, char **av)
{
	t_game	*game;
	mlx_texture_t	*image;

	ac = 2; // !!!!!!!!!!!
	(void)av; // !!!!!!!!!!!

	if(ac != 2)
		return(EXIT_FAILURE, 0);

	game = malloc(sizeof(t_game));
	if(!game)
		return(EXIT_FAILURE);
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(game->window = mlx_new_image(game->mlx, 128, 128)))
	{
		mlx_close_window(game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	image = mlx_load_png("assets/Fox Sprite Sheet.png");
	game->player.image = mlx_texture_to_image(game->mlx, image);
	mlx_delete_texture(image);
	if (mlx_image_to_window(game->mlx, game->player.image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(game->mlx, ft_hook, game);

	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);

	free(game);
	return (EXIT_SUCCESS);
}
