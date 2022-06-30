/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:21:31 by msukri            #+#    #+#             */
/*   Updated: 2022/06/30 15:16:03 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_newgame(t_game *g, char **map, t_map *map_grid)
{
	g->width = map_grid->column * SIZE;
	g->height = map_grid->row * SIZE;
	g->map_grid = map_grid;
	g->map = map;
	g->sprites = ft_init_sprites(g);
}

void	init_game(char **map, t_map map_grid)
{
	t_game	g;

	g.map_gridref = map_grid;
	g.collectible_ref = map_grid.collectible;
	g.map_ref = ft_dup_matrix(map);
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, map_grid.column * SIZE, \
		map_grid.row * SIZE, "One Punch Man!");
	//ft_newgame(&g, map, &map_grid);
}
