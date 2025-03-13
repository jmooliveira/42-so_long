/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:09:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/03/13 18:32:23 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*so_long.h*/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/include/libft.h"
# include "../lib/include/ft_printf.h"
// # include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define EXIT_INVALID_FILE -1

 typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_image
{
	/* data */
}	t_image;

typedef struct s_player
{
	/* data */
}	t_player;

typedef struct s_game
{
	void		*mlx;
	t_map		*map;
	t_image		*img;
	t_player	*player;
}	t_game;

// valgrind --leak-check=full --track-origins=yes ./so_long *.ber

void	ft_validate_input_file(char *file);

void	ft_errors(t_game *game, short error_num);

#endif
