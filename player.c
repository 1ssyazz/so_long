/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:26:52 by msukri            #+#    #+#             */
/*   Updated: 2022/07/05 15:27:45 by msukri           ###   ########.fr       */
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
}
