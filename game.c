/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:21:31 by msukri            #+#    #+#             */
/*   Updated: 2022/07/05 15:27:15 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_game(t_game *g)
{
	if (!(g->frames % g->g_rate))
		ft_refresh_pl(g);
	if (g->next_dir != 0)
		ft_next_dir(g);
}

void	ft_newgame(t_game *g, char **map, t_map *map_grid)
{
	g->width = map_grid->column * SIZE;
	g->height = map_grid->row * SIZE;
	g->map_grid = map_grid;
	g->map = map;
	g->sprites = ft_init_sprites(g);
	g->player = NULL;
	ft_init_player(g, map);
	g->next_dir = 0;
	g->g_rate = REFRESH_RATE;
	g->refresh = 1;
	mlx_loop_hook(g->mlx, ft_refresh, (void *)g);
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
	mlx_loop(g.mlx);
	ft_newgame(&g, map, &map_grid);
}
