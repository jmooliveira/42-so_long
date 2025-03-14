/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:02:07 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/14 19:04:59 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*validate.c*/

#include "so_long.h"

// check .ber == 4 chars

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

// void	ft_validate_map(t_game *game)
// {

// }
