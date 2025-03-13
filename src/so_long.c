/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:32 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/13 18:32:19 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long.c*/

#include "so_long.h"

// void	ft_init(t_game *game)
// {
// 	game = ft_calloc(1, sizeof(t_game));
// }

int	main(int n_args, char **file)
{
	t_game	*game;

	if (n_args != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 0);
	ft_validate_input_file(file[1]);

	game = ft_calloc(1, sizeof(t_game));
	// ft_init(game);
	ft_printf("exit: %d\n", 5);
	return (0);
}

void	ft_validate_input_file(char *file)
{
	int	len_file;

	len_file = ft_strlen(file);
	if (len_file < 4 || !ft_strnstr(file, ".ber", ft_strlen(file)))

		// ft_errors(game, EXIT_INVALID_FILE);
	// ft_putstr_fd(("Error\nInvalid e	xtention\n"), 0);
}
