/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:49:52 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/17 15:03:36 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*init.c*/

#include "so_long.h"

void	ft_init_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	*aux;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error_and_free_map(game, ERR_OPEN);
	line = ft_strdup("");
	while (42)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			break ;
		tmp = ft_strjoin(line, aux);
		free(aux);
		free(line);
		line = tmp;
	}
	close(fd);
	game->map->map = ft_split(line, '\n');
	free(line);
	ft_set_map(game);
}

void	ft_set_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map->map[i] != NULL)
	{
		j = 0;
		while (game->map->map[i][j] != '\0' && game->map->map[i][j] != '\n')
		{
			c = game->map->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E'
				&& c != 'P' && c != '\n')
				ft_message_error_and_free_game(game, ERR_INVALID_CHAR);
			ft_set_char(game, c, i, j);
			j++;
		}
		i++;
	}
	if (game->map->collectable < 1 || game->map->exit != 1
		|| game->map->player != 1)
		ft_message_error_and_free_game(game, ERR_INVALID_MAP);
}

void	ft_set_char(t_game *game, char c, int i, int j)
{
	if (c == 'C')
		game->map->collectable++;
	if (c == 'P')
	{
		game->map->player++;
		game->player->player_x = i;
		game->player->player_y = j;
	}
	if (c == 'E')
	{
		game->map->exit++;
		game->map->exit_x = i;
		game->map->exit_y = j;
	}
}
