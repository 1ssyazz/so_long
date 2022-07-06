/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:01:34 by msukri            #+#    #+#             */
/*   Updated: 2022/07/06 16:16:48 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_pl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl)
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.black, \
			pl->win_pos.x, pl->win_pos.y);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.saitama, \
			pl->win_pos.x, pl->win_pos.y);
		if (!pl->moving)
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.saitama, \
				pl->pos.x * SIZE, pl->pos.y * SIZE);
		pl = pl->next;
	}
}

void	ft_refresh_pl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl)
	{
		if (pl->win_pos.x < pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x++;
		if (pl->win_pos.x > pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x--;
		if (pl->win_pos.y < pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y++;
		if (pl->win_pos.y > pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y--;
		if (pl->win_pos.x == pl->pos.x * SIZE && \
				pl->win_pos.y == pl->pos.y * SIZE)
			pl->moving = 0;
		pl = pl->next;
	}
	ft_put_pl(g);
}

void	ft_next_dir(t_game *g)
{
	t_player	*pl;
	int			n_pl;

	pl = g->pl;
	n_pl = g->map_grid->player;
	while (pl)
	{
		if (!pl->moving)
		{
			ft_legal_move(g, pl);
			if (g->next_dir && is_legal(pl, g->next_dir))
				pl->dir = g->next_dir;
			move_pl(pl->dir, g, pl);
		}
	}
}	

void	move_pl(int dir, t_game *g, t_player *pl)
{
	t_vector	new;

	if (pl)
	{
		if (dir == N && ft_strchr("0CE", g->map[pl->pos.y - 1][pl->pos.x]))
			new = ft_vector(pl->pos.x, pl->pos.y - 1);
		else if (dir == S && ft_strchr("0CE", g->map[pl->pos.y + 1][pl->pos.x]))
			new = ft_vector(pl->pos.x, pl->pos.y + 1);
		else if (dir == W && ft_strchr("0CE", g->map[pl->pos.y][pl->pos.x - 1]))
			new = ft_vector(pl->pos.x - 1, pl->pos.y);
		else if (dir == E && ft_strchr("0CE", g->map[pl->pos.y][pl->pos.x + 1]))
			new = ft_vector(pl->pos.x + 1, pl->pos.y);
		else
			new = ft_vector(0, 0);
		if (g->map[new.y][new.x] == 'C')
			g->map_grid->collectible--;
		if (new.x && new.y)
			ft_update_pos(ft_vector(pl->pos.x, pl->pos.y), new, g);
	}
}

int	ft_update_pos(t_vec old, t_vec	new, t_game *g)
{
	t_player	*pl;
	int			hide;

	pl = g->pl;
	hide = 0;
	if (g->map[new.y][new.x] == 'E')
	{
		if (g->map_grid->collectible)
			return (1);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprites.black, \
			old.x * SIZE, old.y * SIZE);
		hide = ft_free_pl(g, old);
	}
	while (!hide && pl)
	{
		if (pl->pos.x == old.x && pl->pos.y == old.y)
		{
			pl->pos = ft_vector(new.x, new.y);
			pl->moving = 1;
		}
		pl = pl->next;
	}
	ft_memset(&g->map[new.y][new.x], g->map[old.y][old.x], !hide);
	ft_memset(&g->map[old.y][old.x], '0', 1);
	return (1);
}
