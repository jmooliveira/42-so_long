/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:52:49 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/21 19:21:26 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*flood_fill.c*/

#include "so_long_bonus.h"

void	ft_flood_fill(t_game *game)
{
	ft_copy_map(game);
	flood_fill(game, game->player->player_x, game->player->player_y);
	ft_verify_flood_fill(game);
}

void	ft_copy_map(t_game *game)
{
	int	i;
	int	j;

	game->copy_map = ft_calloc(game->map->height + 1, sizeof(char *));
	i = 0;
	while (game->map->map[i])
	{
		game->copy_map[i] = ft_calloc(game->map->width + 1, sizeof(char));
		j = 0;
		while (game->map->map[i][j])
		{
			game->copy_map[i][j] = game->map->map[i][j];
			j++;
		}
		game->copy_map[i][j] = '\0';
		i++;
	}
	game->copy_map[i] = NULL;
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= (game->map->width - 1)
		|| y >= (game->map->height - 1))
		return ;
	if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'X')
		return ;
	if (game->copy_map[y][x] == '0' || game->copy_map[y][x] == 'C'
		|| game->copy_map[y][x] == 'E'
			|| game->copy_map[y][x] == 'P')
	{
		game->copy_map[y][x] = 'X';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

void	ft_verify_flood_fill(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copy_map[i])
	{
		j = 0;
		while (game->copy_map[i][j])
		{
			if (game->copy_map[i][j] == 'E')
				ft_error_flood(game, ERR_NO_PATH);
			if (game->copy_map[i][j] == 'C')
				ft_error_flood(game, ERR_NO_PATH);
			j++;
		}
		i++;
	}
}

void	ft_error_flood(t_game *game, const char *msg)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		free(game->copy_map[i]);
		i++;
	}
	free(game->copy_map);
	ft_putstr_fd(msg, 0);
	ft_free_map(game->map->map, ft_ptrlen(game->map->map));
	free(game->player);
	free(game->map);
	free(game);
	exit(2);
}
