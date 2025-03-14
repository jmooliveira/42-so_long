/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:19 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/14 18:51:21 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*errors.c*/

#include "so_long.h"

void	ft_message_error(const char *msg)
{
	ft_putstr_fd(msg, 0);
	exit(1);
}

void	ft_message_error_and_free(t_game *game, const char *msg)
{
	ft_putstr_fd(msg, 0);
	free(game->map);
	free(game);
	exit(2);
}

void	ft_free_game(t_game *game)
{
	ft_free_map(game->map->map, ft_ptrlen(game->map->map));
	free(game->map);
	free(game);
	ft_printf("\nTHATS ALL FOLKS! %d\n", 86); // SAI
	exit (0);
}

void	ft_free_map(char **ptr, int	ptr_len)
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

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
