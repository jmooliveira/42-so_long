/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:44:19 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/13 18:21:14 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*errors.c*/

#include "so_long.h"

void	ft_errors(t_game *game, short error_num)
{
	if (error_num == EXIT_INVALID_FILE)
		ft_putstr_fd(("Error\nInvalid file\n"), 0);
}
