/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:26:52 by msukri            #+#    #+#             */
/*   Updated: 2022/07/21 16:09:46 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*ft_new_pl(t_vec pos)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = pos;
	player->win_pos = ft_vector(pos.x * SIZE, pos.y * SIZE);
	player->moving = 0;
	player->dir = DIR;
	player->next = NULL;
	return (player);
}

void	ft_pl_add(t_player **list, t_player *new_player)
{
	t_player	*start;

	start = *list;
	if (*list)
	{
		while (start->next)
			start = start->next;
		start->next = new_player;
	}
	else
		*list = new_player;
}

void	ft_init_player(t_game *g, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_pl_add(&g->player, ft_new_pl(ft_vector(x, y)));
			x++;
		}
		y++;
	}
}

int	ft_refresh(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	g->frames++;
	ft_check_game(g);
	if (g->refresh)
	{
		while (g->map[y])
		{
			x = 0;
			while (g->map[y][x])
			{
				update_map(g, x, y);
				x++;
			}
			y++;
		}
		g->refresh = 0;
	}
	return (0);
}

void	ft_pl_image(t_game *g)
{
	t_player	*pl;
	int			s;

	s = SIZE;
	pl = g->player;
	while (pl)
	{
		pl->sprite = mlx_xpm_file_to_image(g->mlx, \
			"images/saitamarm32.xpm", &s, &s);
		pl = pl->next;
	}
}
