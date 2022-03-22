/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:10:31 by emadriga          #+#    #+#             */
/*   Updated: 2022/03/22 21:35:00 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define KEY_ESC 53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

static	int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

static void	render_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


static void	render_pixels(t_data	*img, int **matrix_colors)
{
	int			x;
	int			y;

	y = 0;
	while (y < RESOLUTION)
	{
		x = 0;
		while (x < HORIZ_RESOLUTION)
		{
			render_pixel(img, x, y, matrix_colors[x][y]);
			x++;
		}
		y++;
	}
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	return (0);
}

void	render_image_on_mlx(int	**matrix_colors)
{
	t_vars	v;
	int		endian;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, HORIZ_RESOLUTION, RESOLUTION, "miniRT test");
	v.img.img = mlx_new_image(v.mlx, HORIZ_RESOLUTION, RESOLUTION);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, \
	&v.img.line_length, &endian);
	render_pixels(&v.img, matrix_colors);
	mlx_put_image_to_window(v.mlx, v.win, v.img.img, 0, 0);
	mlx_key_hook(v.win, key_hook, &v);
	mlx_hook(v.win, 17, 1L << 17, close_window, &v);
	mlx_loop(v.mlx);
}
