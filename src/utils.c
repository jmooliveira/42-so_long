/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:53:52 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/17 14:54:07 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*utils.c*/

#include "so_long.h"

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
