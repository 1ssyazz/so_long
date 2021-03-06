/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:04:58 by msukri            #+#    #+#             */
/*   Updated: 2022/07/21 14:37:10 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_pl(t_game *g, t_vec	old)
{
	t_player	*temp;
	t_player	*prev;

	temp = g->player;
	prev = NULL;
	g->map_grid->player--;
	while (temp)
	{
		if (temp->pos.x == old.x && temp->pos.y == old.y)
		{
			mlx_destroy_image(g->mlx, temp->sprite);
			if (!prev)
				return (free_first_pl(g));
			if (prev && !temp->next)
				return (free_last_pl(g));
			prev->next = temp->next;
			free(temp);
			temp = NULL;
			return (1);
		}
		prev = temp;
		temp = temp->next;
	}
	return (1);
}

int	free_first_pl(t_game *g)
{
	t_player	*pl;

	pl = g->player;
	if (pl->next)
		g->player = pl->next;
	else
		g->player = NULL;
	free(pl);
	pl = NULL;
	return (1);
}

int	free_last_pl(t_game *g)
{
	t_player	*pl;

	pl = g->player;
	while (pl->next->next)
		pl = pl->next;
	free(pl->next);
	pl->next = NULL;
	return (1);
}

int	free_img(t_game *g)
{
	t_player	*pl;

	pl = g->player;
	while (pl)
	{
		mlx_destroy_image(g->mlx, pl->sprite);
		pl = pl->next;
	}
	mlx_destroy_image(g->mlx, g->sprites.wall);
	mlx_destroy_image(g->mlx, g->sprites.mosquito);
	mlx_destroy_image(g->mlx, g->sprites.exit);
	mlx_destroy_image(g->mlx, g->sprites.black);
	return (0);
}

void	free_player(t_game *g)
{
	t_player	*pl;

	while (g->player)
	{
		pl = g->player;
		g->player = g->player->next;
		free(pl);
		pl = NULL;
	}
}
