/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:57:04 by msukri            #+#    #+#             */
/*   Updated: 2022/07/06 16:12:06 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_dir(t_game *g, int dir)
{
	t_player	*pl;

	pl = g->player;
	if (g->move < INT_MAX)
		g->move++;
	ft_putstr_fd("Current move: ", 1);
	ft_putnbr_fd(g->move, 1);
	ft_putstr_fd("\n", 1);
	while (pl)
	{
		g->next_dir = dir;
		pl = pl->next;
	}
}

int	key_hook(int key, t_game *g)
{
	if (key == KEY_Q || key == ESC)
	{
		ft_putstr_fd("Give up already?\n", 1);
		end_game(g);
	}
	if (key == KEY_W && g->next_dir != N)
		new_dir(g, N);
	if (key == KEY_S && g->next_dir != S)
		new_dir(g, S);
	if (key == KEY_A && g->next_dir != W)
		new_dir(g, W);
	if (key == KEY_D && g->next_dir != E)
		new_dir(g, E);
	return (0);
}
