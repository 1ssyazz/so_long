/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:57:39 by msukri            #+#    #+#             */
/*   Updated: 2022/06/21 11:56:40 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_colour	new_colour(int a, int r, int g, int b)
{
	t_colour	colour;

	colour.a = (char)a;
	colour.r = (char)r;
	colour.g = (char)g;
	colour.b = (char)b;
	return (colour);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	turn_pixel_to_colour(char *pixel, t_colour colour)
{
	pixel[0] = colour.b;
	pixel[1] = colour.g;
	pixel[2] = colour.r;
	pixel[3] = colour.a;
}

void	turn_img_to_color(t_image *img, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->size.y)
	{
		x = 0;
		while (x < img->size.x)
		{
			my_mlx_pixel_put(img, x, y, colour);
			//turn_pixel_to_colour(
			//	&img->pixels[x * 4 + img->line_size * y], colour);
			x++;
		}
		y++;
	}
}
