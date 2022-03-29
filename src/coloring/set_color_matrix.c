/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:04:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/29 17:11:26 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
?		In this file, we'll fill each matrix pixel with its color.
TODO	We may or may not draw the pixels on the MiniLibX here. If we plan to
TODO	use multiple threads, I'd create a whole new section for "printing"
TODO	the pixels.
		- Jorge
*/

/*
*	In this function, we're creating a matrix to store the color of each pixel
*	in rgb.
*
*	For each vector, we'll:
*		*	Check if the vector collides with a figure (otherwise, we set the pixel's color to black).
*		*	Check the collision figure and a collision point.
*		*	Get a normal vector of the collision point so ve can calculate ray angles.
*		*	Apply the color mixing (color of the figure + color of the lights).
*/
int	**set_color_matrix(t_itemlist *items, t_coords **v_matrix)
{
	int				**c_matrix;
	int				x;
	int				y;
	int				collisions;
	t_figure_point	closest_point;

	c_matrix = ft_calloc(sizeof(int *), HORIZ_RESOLUTION + 1);
	x = -1;
	while (++x < HORIZ_RESOLUTION)
		c_matrix[x] = ft_calloc(sizeof(int), RESOLUTION + 1);
	y = 0;
	while (y < RESOLUTION)
	{
		x = 0;
		while (x < HORIZ_RESOLUTION)
		{
			collisions = check4collisions(v_matrix[x][y], items);
			if (collisions)
			{
				closest_point = get_closest_fig_point(dir_and_cam_2_vector(get_item_by_type(&items, CAMERA), v_matrix[x][y]), items);
				c_matrix[x][y] = rgb2int(closest_point.color);
			}
			else
				c_matrix[x][y] = 0x0;
			x++;
		}
		y++;
	}
	lst_rt_print(items);
	return (c_matrix);
}

void	free_array_colors(int ***list)
{
	int	a;

	a = 0;
	if (*list)
	{
		while ((*list)[a])
			free((*list)[a++]);
		free((*list)[a]);
		free(*list);
	}
}
