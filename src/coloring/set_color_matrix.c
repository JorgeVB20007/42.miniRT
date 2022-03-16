/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:04:24 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/16 20:27:05 by jvacaris         ###   ########.fr       */
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

t_colors	**set_color_matrix(t_itemlist *items, t_coords **v_matrix)
{
	t_colors	**c_matrix;
	int			ctr;

	c_matrix = malloc(sizeof(t_coords *) * RESOLUTION * (16 / 9));
	ctr = 0;
	while (ctr < RESOLUTION * (16 / 9))
	{
		c_matrix[ctr] = malloc(sizeof(t_coords) * RESOLUTION);
		ctr++;
	}
	
// ~~~~ Useless stuff to make the complier happy ~~~~
		items = NULL;								//
		v_matrix = NULL;							//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	return (c_matrix);
}
