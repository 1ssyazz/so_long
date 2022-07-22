/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:21:31 by msukri            #+#    #+#             */
/*   Updated: 2022/07/22 20:21:32 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *g)
{
	if (g->map)
		ft_free_matrix(&g->map);
	free_img(g);
	ft_putstr_fd("Move made: ", 1);
	ft_putnbr_fd(g->move, 1);
	ft_putchar_fd('\n', 1);
	if (!g->player)
		ft_putstr_fd("GRATS\n", 1);
	free_player(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	mlx_destroy_window(g->mlx, g->mlx_win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
	return (0);
}

void	ft_check_game(t_game *g)
{
	if (!(g->frames % g->g_rate))
		ft_refresh_pl(g);
	if (g->next_dir != 0)
		ft_next_dir(g);
	if (!g->map_grid->collectible && !g->map_grid->player)
	{
		ft_putstr_fd("ONE PUNCH ALL IT TAKES!\n", 1);
		end_game(g);
	}
}

void	ft_newgame(t_game *g, char **map, t_map *map_grid)
{
	g->move = 0;
	g->width = map_grid->column * SIZE;
	g->height = map_grid->row * SIZE;
	g->map_grid = map_grid;
	g->map = map;
	g->sprites = ft_init_sprites(g);
	g->player = NULL;
	ft_init_player(g, map);
	g->next_dir = 0;
	ft_pl_image(g);
	g->g_rate = REFRESH_RATE;
	g->refresh = 1;
	g->frames = 1;
	mlx_loop_hook(g->mlx, ft_refresh, (void *)g);
	mlx_hook(g->mlx_win, 17, 0, end_game, (void *)g);
	mlx_key_hook(g->mlx_win, key_hook, (void *)g);
	mlx_loop(g->mlx);
}

void	init_game(char **map, t_map map_grid)
{
	t_game	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, map_grid.column * SIZE, \
		map_grid.row * SIZE, "One Punch Man!");
	ft_newgame(&g, map, &map_grid);
}
