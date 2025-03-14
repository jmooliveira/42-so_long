/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:49:52 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/14 19:17:11 by jemorais         ###   ########.fr       */
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
		ft_message_error_and_free(game, ERR_OPEN);
	line = ft_strdup("");
	while (42)
	{
		aux = get_next_line(fd);
		if(aux == NULL)
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
	int	i;
	int	j;

	(void)game;
	while (game->map->map[i][j] != '\0' && game->map->map[i][j] != '\n')
	{

	}
}
