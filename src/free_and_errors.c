/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:19 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/17 14:58:10 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*errors.c*/

#include "so_long.h"

void	ft_message_error(const char *msg)
{
	ft_putstr_fd(msg, 0);
	exit(1);
}

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

	i = 0;
	while (i < ptr_len)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free_game_final(t_game *game)
{
	ft_free_map(game->map->map, ft_ptrlen(game->map->map));
	free(game->player);
	free(game->map);
	free(game);
	ft_printf("\nTHATS ALL FOLKS! %d\n", 86);
	exit (0);
}
