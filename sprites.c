/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:24 by msukri            #+#    #+#             */
/*   Updated: 2022/07/21 16:09:38 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	ft_init_sprites(t_game *g)
{
	int	size;

	size = SIZE;
	g->sprites.wall = mlx_xpm_file_to_image(g->mlx, \
		"images/wall32.xpm", &size, &size);
	g->sprites.mosquito = mlx_xpm_file_to_image(g->mlx, \
		"images/mosquito32.xpm", &size, &size);
	g->sprites.exit = mlx_xpm_file_to_image(g->mlx, \
		"images/exit32.xpm", &size, &size);
	g->sprites.black = mlx_xpm_file_to_image(g->mlx, \
		"images/black32.xpm", &size, &size);
	return (g->sprites);
}
