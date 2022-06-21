/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:22:08 by msukri            #+#    #+#             */
/*   Updated: 2022/06/21 12:11:54 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main(void)
{
	t_program	mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = ft_new_window(mlx.mlx, 1920, 1080, "One Punch!!!");
	mlx.img = ft_new_image(mlx.mlx, "images/saitamarm.xpm");
	mlx.img_position.x = 0;
	mlx.img_position.y = 0;
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win.reference, mlx.img.reference,
		mlx.img_position.x, mlx.img_position.y);
	mlx_key_hook(mlx.mlx_win.reference, *ft_input, &mlx);
	mlx_loop_hook(mlx.mlx, *ft_update, &mlx);
	mlx_loop(mlx.mlx);
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);
	// for (int i = 0; i < 1000; i++)
	// {
	// 	my_mlx_pixel_put(&img, i, i, create_trgb(0, 255, 0, 0));
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
