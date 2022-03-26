/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:21 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/26 18:12:20 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
*	Here we'll get the exact point where the ray collided with each figure, 
*	the normal vector of the collision point and the resulting color.
! 	The resulting color is not implemented yet.
*/

static t_figure_point	get_plane_point(t_vectors ray, t_item plane, t_item alight)
{
	t_vectors		plane_vectors;
	t_figure_point	result;
	int			t;

	plane_vectors.dir = plane.orient;
	plane_vectors.loc = plane.loc;
	t = get_the_t(ray, plane_vector2equation(plane_vectors));
	result.loc = v_v_sum(v_i_mult(plane.orient, t), plane.loc);
	result.dir = plane.orient;
	result.color = alight2fig(plane.color, alight.color, alight.brightness);
	return (result);
}

static t_figure_point	get_sphere_point(t_vectors ray, t_item sphere, t_item alight)
{
	t_figure_point	result;

	result.loc = v_v_sum(v_i_mult(ray.dir, get_ray_sphere_distance(ray, \
	sphere)), ray.loc);
	result.dir = v_v_sub(sphere.loc, result.loc);
	result.color = alight2fig(sphere.color, alight.color, alight.brightness);
	return (result);
}

/*
*	This function gets the list of items and the ray being evaluated when
*	there's at least one collision. It will return the closest collision
*	point, along with the normal vector and the color of the figure involved
*	mixed with the color and brightness of the ALIGHT.

!		Warning:
TODO	We're not checking if the closest figure to a vector is in front or behind the camera.
*/
t_figure_point	get_closest_fig_point(t_vectors ray, t_itemlist *items)
{
	t_figure_point	new_point;
	t_figure_point	top_point;
	t_item			item_alight;
	int				ctrl;

	ctrl = 0;
	item_alight = get_item_by_type(&items, ALIGHT);
	while (items)
	{
		if (items->content->type == SPHERE && touches_sphere(ray, *(items->content)))
			new_point = get_sphere_point(ray, *(items->content), item_alight);
		else if (items->content->type == PLANE && touches_plane(ray, *(items->content)))
			new_point = get_plane_point(ray, *(items->content), item_alight);
		if (!ctrl || getmodule(v_v_sub(new_point.loc, ray.loc)) < getmodule(v_v_sub(top_point.loc, ray.loc)))
		{
			top_point = new_point;
			ctrl = 1;
		}
		if (items->next == NULL)
			break ;
		items = items->next;
	}
	return (top_point);
}
