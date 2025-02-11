/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:31:14 by jemorais          #+#    #+#             */
/*   Updated: 2025/02/11 16:48:44 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 256
# define HEIGHT 256

typedef struct s_player
{
	void	*image;
	int		x;
	int		y;
} t_player;

typedef struct s_game
{
	void		*window;
	void		*mlx;
	t_player	player;
} t_game;


#endif /*SO_LONG_H*/
