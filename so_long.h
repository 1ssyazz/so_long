/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:47:25 by msukri            #+#    #+#             */
/*   Updated: 2022/06/21 11:57:00 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 1000
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_colour
{
	int	a;
	int	r;
	int	g;
	int	b;
}				t_colour;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program
{
	void		*mlx;
	t_window	mlx_win;
	t_image		img;
	t_vector	img_position;
}				t_program;

t_window	ft_new_window(void *mlx, int width, int height, char *name);
int			ft_close(void);
t_image		ft_new_image(void *mlx, char *path);
int			ft_input(int key, void *param);
void		turn_img_to_color(t_image *img, int colour); //, t_colour colour);
t_colour	new_colour(int a, int r, int g, int b);
void		turn_pixel_to_colour(char *pixel, t_colour colour);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int			ft_update(void *param);

int			main(void);
int			create_trgb(int t, int r, int g, int b);

#endif
