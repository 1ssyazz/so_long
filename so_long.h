/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:47:25 by msukri            #+#    #+#             */
/*   Updated: 2022/07/21 14:43:25 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define SIZE 16
# define KEY_Q 113
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define ESC 65307

# ifndef REFRESH_RATE
#  define REFRESH_RATE 100
# endif

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
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int			ft_update(void *param);

// int			main(void);

enum e_direction
{
	DIR = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

typedef struct s_legal
{
	int	north;
	int	south;
	int	west;
	int	east;
}				t_legal;

typedef struct s_map
{
	int	row;
	int	column;
	int	player;
	int	exit;
	int	collectible;
	int	enemy;	
}				t_map;

typedef struct s_error
{
	int	row;
	int	other_char;
	int	players;
	int	exits;
	int	collectibles;
	int	enemies;
	int	borders;
}				t_error;

typedef struct s_player
{
	t_vec			pos;
	t_vec			win_pos;
	int				moving;
	int				dir;
	t_legal			legal;
	struct s_player	*next;
	void			*sprite;
}				t_player;

typedef struct s_sprite
{
	void		*wall;
	void		*mosquito;
	void		*exit;
	void		*black;
}				t_sprite;

typedef struct s_game
{
	t_map		map_gridref;
	t_map		*map_grid;
	t_sprite	sprites;
	t_player	*player;
	int			move;
	int			collectible_ref;
	char		**map_ref;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	int			next_dir;
	int			g_rate;
	int			refresh;
	int			frames;
}				t_game;

int			main(int argc, char **argv);
int			map_file_checker(int argc, char **argv);
int			error(char *message, char **map_str);
char		**map_check(int fd, t_map *map_grid);
t_map		ft_map_grid(void);
t_error		ft_init_map_error(void);
void		ft_readgrid(int fd, t_map *map_grid,
				t_error *map_err, char **map_str);
void		ft_checkgrid(char *line, t_map *map_grid,
				t_error *map_err, int last);
int			ft_map_error(t_error *map_error, char **map_str);
void		init_game(char **map, t_map map_grid);
void		ft_newgame(t_game *g, char **map, t_map *map_grid);
t_sprite	ft_init_sprites(t_game *g);
t_player	*ft_new_pl(t_vec pos);
void		ft_pl_add(t_player **list, t_player *new_player);
void		ft_init_player(t_game *g, char **map);
void		ft_refresh_pl(t_game *g);
void		ft_put_pl(t_game *g);
void		ft_next_dir(t_game *g);
void		ft_legal_move(t_game *g, t_player *pl);
int			is_legal(t_player *pl, int dir);
void		move_pl(int dir, t_game *g, t_player *pl);

int			ft_refresh(t_game *g);
void		ft_check_game(t_game *g);
int			ft_update_pos(t_vec old, t_vec	new, t_game *g);
void		move_pl(int dir, t_game *g, t_player *pl);
void		ft_next_dir(t_game *g);
void		update_map(t_game *g, int x, int y);
int			key_hook(int key, t_game *g);
void		new_dir(t_game *g, int dir);

int			end_game(t_game *g);
int			ft_free_pl(t_game *g, t_vec	old);
int			free_first_pl(t_game *g);
int			free_last_pl(t_game *g);
int			free_img(t_game *g);
void		free_player(t_game *g);

void		ft_pl_image(t_game *g);

#endif
