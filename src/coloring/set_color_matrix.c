/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:04:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/21 17:41:56 by jvacaris         ###   ########.fr       */
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
t_colors	**set_color_matrix(t_itemlist *items, t_coords **v_matrix)
{
	t_colors	**c_matrix;
	int			x;
	int			y;

//! ~~ Testing started ~~~~~~~~~~
//	/*	
	void	*gnrl_ptr;
	void	*win_ptr;

	gnrl_ptr = mlx_init();
	win_ptr = mlx_new_window(gnrl_ptr, HORIZ_RESOLUTION, RESOLUTION, "miniRT test");
//	*/
//! ~~~ Testing ended ~~~~~~~~~~~

	c_matrix = malloc(sizeof(t_coords *) * HORIZ_RESOLUTION);
	x = 0;
	while (x < HORIZ_RESOLUTION)
	{
		c_matrix[x] = malloc(sizeof(t_coords) * RESOLUTION);
		x++;
	}
	y = 0;
	while (y < RESOLUTION)
	{
		x = 0;
		while (x < HORIZ_RESOLUTION)
		{
			if (check4collisions(v_matrix[x][y], items))
			{

			//! ~~ Testing started ~~~~~~~~~~
//	/*
				mlx_pixel_put (gnrl_ptr, win_ptr, x, y, 16777215);
//	*/
			//! ~~~ Testing ended ~~~~~~~~~~~

				//TODO	Here we'll calculate collision point & get its color.
			}
			x++;
		}
		y++;
	}

//! ~~ Testing started ~~~~~~~~~~
//	/*
	mlx_loop(gnrl_ptr);
//	*/
//! ~~~ Testing ended ~~~~~~~~~~~

	return (c_matrix);
}
