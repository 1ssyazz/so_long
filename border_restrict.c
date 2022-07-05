/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_restrict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:54:22 by msukri            #+#    #+#             */
/*   Updated: 2022/07/05 15:07:05 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_legal_move(t_game *g, t_player *pl)
{
	pl->legal.north = !ft_strchr("1", g->map[pl->pos.y - 1][pl->pos.x]);
	pl->legal.south = !ft_strchr("1", g->map[pl->pos.y + 1][pl->pos.x]);
	pl->legal.west = !ft_strchr("1", g->map[pl->pos.y][pl->pos.x - 1]);
	pl->legal.east = !ft_strchr("1", g->map[pl->pos.y][pl->pos.x + 1]);
}

int	is_legal(t_player *pl, int dir)
{
	if (dir == N && pl->legal.north)
		return (1);
	if (dir == S && pl->legal.south)
		return (1);
	if (dir == W && pl->legal.west)
		return (1);
	if (dir == E && pl->legal.east)
		return (1);
	if (dir == DIR)
		return (1);
	return (0);
}
