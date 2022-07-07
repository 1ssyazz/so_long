/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:24 by msukri            #+#    #+#             */
/*   Updated: 2022/07/07 15:56:22 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	ft_init_sprites(t_game *g)
{
	int	size;

	size = SIZE;
	g->sprites.wall = mlx_xpm_file_to_image(g->mlx, \
		"images/walls.xpm", &size, &size);
	g->sprites.mosquito = mlx_xpm_file_to_image(g->mlx, \
		"images/mosquito.xpm", &size, &size);
	g->sprites.exit = mlx_xpm_file_to_image(g->mlx, \
		"images/exit.xpm", &size, &size);
	g->sprites.saitama = mlx_xpm_file_to_image(g->mlx, \
		"images/saitamarm.xpm", &size, &size);
	g->sprites.black = mlx_xpm_file_to_image(g->mlx, \
		"images/black.xpm", &size, &size);
	return (g->sprites);
}
