/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:46:56 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/10 20:27:49 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	if(ac != 2)
		return (ft_putstr_fd("Error\nInvalid Args\n", STDERR_FILENO), 1);
	(void)av;
}
