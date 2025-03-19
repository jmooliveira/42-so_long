/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:19 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/19 20:12:04 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*errors.c*/

#include "so_long.h"

void	ft_message_error_and_free_map(t_game *game, const char *msg)
{
	ft_putstr_fd(msg, 0);
	free(game->player);
	free(game->map);
	free(game);
	exit(2);
}

void	ft_message_error_and_free_game(t_game *game, const char *msg)
{
	ft_putstr_fd(msg, 0);
	ft_free_map(game->map->map, ft_ptrlen(game->map->map));
	free(game->player);
	free(game->map);
	free(game);
	exit(2);
}

void	ft_free_map(char **ptr, int ptr_len)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (i < ptr_len)
	{
		if (ptr[i])
			free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free_game(t_game *game)
{
	if (!game || !game->img)
		return ;
	if (game->copy_map)
		ft_free_map(game->copy_map, ft_ptrlen(game->copy_map));
	if (game->map)
	{
		ft_free_map(game->map->map, ft_ptrlen(game->map->map));
		free(game->map);
	}
	if (game->player)
		free(game->player);
	if (game->img)
	{
		ft_cleanup_game(game);
		free(game->img);
	}
	free(game);
	exit(0);
}

void	ft_cleanup_game(t_game *game)
{
	if (!game->img)
		return ;
	mlx_delete_image(game->mlx, game->img->image_floor);
	mlx_delete_image(game->mlx, game->img->image_wall);
	mlx_delete_image(game->mlx, game->img->image_player);
	mlx_delete_image(game->mlx, game->img->image_collect);
	mlx_delete_image(game->mlx, game->img->image_exit);
	mlx_delete_image(game->mlx, game->img->image_final_exit);
	mlx_terminate(game->mlx);
	game->mlx = NULL;
}

