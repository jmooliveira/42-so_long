/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:52:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/14 18:58:35 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*main.c*/

#include "so_long.h"

int	main(int n_args, char **file)
{
	t_game	*game;

	if (n_args != 2)
		ft_message_error(ERR_ARGS);
	ft_validate_input_file(file[1]);
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(t_map));
	ft_init_map(game, file[1]);
	ft_validate_map(game);

	ft_free_game(game);
}
