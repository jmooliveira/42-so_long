/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:02:07 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/19 17:58:55 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*validate.c*/

#include "so_long.h"

void	ft_validate_input_file(char *file)
{
	int	len_file;
	int	fd;

	len_file = ft_strlen(file);
	if (len_file < 4 || !ft_strnstr(file, ".ber", len_file))
		ft_message_error(ERR_EXT);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error(ERR_OPEN);
	close(fd);
}

void	ft_validate_map(t_game *game)
{
	game->map->height = ft_ptrlen(game->map->map);
	game->map->width = ft_strlen(game->map->map[0]);
	if (!ft_check_line_size(game))
		ft_message_error_and_free_game(game, ERR_LINE_SIZE);
	if (!ft_limits_map(game))
		ft_message_error_and_free_game(game, ERR_MAP_OPEN);
	if (game->map->height == game->map->width)
		ft_message_error_and_free_game(game, ERR_SQUARE_MAP);
	if ((game->map->height * game->map->width) < 15)
		ft_message_error_and_free_game(game, ERR_TOO_SHORT);
}

bool	ft_check_line_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
			j++;
		if (j != game->map->width)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_limits_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if ((i == 0 || i == game->map->height - 1 || j == 0
					|| j == game->map->width - 1)
				&& game->map->map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
