/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:29:11 by msukri            #+#    #+#             */
/*   Updated: 2022/07/05 13:54:23 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*mlx;

	mlx = (t_program *)param;
	mlx_clear_window(mlx->mlx, mlx->mlx_win.reference);
	//mlx_destroy_image(mlx->mlx, &mlx->img);
	if (key == 65363)
		mlx->img_position.x += mlx->img.size.x;
	else if (key == 65361)
		mlx->img_position.x -= mlx->img.size.x;
	else if (key == 65364)
		mlx->img_position.y += mlx->img.size.y;
	else if (key == 65362)
		mlx->img_position.y -= mlx->img.size.y;
	else if (key == 114)
		turn_img_to_color(&mlx->img, create_trgb(0, 255, 0, 0));
	else if (key == 103)
		turn_img_to_color(&mlx->img, create_trgb(0, 0, 255, 0));
	else if (key == 98)
		turn_img_to_color(&mlx->img, create_trgb(0, 0, 0, 255));
	else if (key == 110)
		mlx->img = ft_new_image(mlx->mlx, "images/blur.xpm");
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win.reference,
		mlx->img.reference, mlx->img_position.x, mlx->img_position.y);
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*prg;
	static int	frame;

	prg = (t_program *)param;
	frame++;
	if (frame == ANIMATION_FRAMES)
		prg->img_position.y += 5;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		prg->img_position.y -= 5;
		frame = 0;
	}
	mlx_put_image_to_window(prg->mlx, prg->mlx_win.reference,
		prg->img.reference, prg->img_position.x, prg->img_position.y);
	return (0);
}
