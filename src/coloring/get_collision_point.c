/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:21 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/28 20:34:24 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
*	Here we'll get the exact point where the ray collided with each figure, 
*	the normal vector of the collision point and the resulting color.
! 	The resulting color is not implemented yet.
*/

static t_figure_point	get_plane_point(t_vectors ray, t_item plane)
{
	t_vectors		plane_vectors;
	t_figure_point	result;
	int			t;

	plane_vectors.dir = plane.orient;
	plane_vectors.loc = plane.loc;
	t = get_the_t(ray, plane_vector2equation(plane_vectors));
	result.loc = v_v_sum(v_f_mult(plane.orient, t), plane.loc);
	result.dir = plane.orient;
	result.color = plane.color;
	return (result);
}

static t_figure_point	get_sphere_point(t_vectors ray, t_item sphere)
{
	t_figure_point	result;

	result.loc = v_v_sum(v_f_mult(ray.dir, get_ray_sphere_distance(ray, \
	sphere)), ray.loc);
	result.dir = v_v_sub(sphere.loc, result.loc);
	result.color = sphere.color;
	return (result);
}

/*
*	This function gets the list of items and the ray being evaluated when
*	there's at least one collision. It will return the closest collision
*	point, along with the normal vector and the color of the figure involved
*	mixed with the color and brightness of the ALIGHT.
*/
t_figure_point	get_closest_fig_point(t_vectors ray, t_itemlist *items)
{
	t_figure_point	new_point;
	t_figure_point	top_point;
	t_item			item_alight;
	int				ctrl;
	t_itemlist		*items2;

	ctrl = 0;
	items2 = items;
	item_alight = get_item_by_type(&items, ALIGHT);
	while (items)
	{
		if (items->content->type == SPHERE && touches_sphere(ray, *(items->content)))
			new_point = get_sphere_point(ray, *(items->content));
		else if (items->content->type == PLANE && touches_plane(ray, *(items->content)))
			new_point = get_plane_point(ray, *(items->content));
		if (!ctrl || getmodule(v_v_sub(new_point.loc, ray.loc)) < getmodule(v_v_sub(top_point.loc, ray.loc)))
		{
			top_point = new_point;
			ctrl = 1;
		}
		if (items->next == NULL)
			break ;
		items = items->next;
	}
	calculate_reflection(&top_point, ray, items2, item_alight);
	return (top_point);
}

/**
 * @retval 0 means that no interruptions were found.
 * @retval 1 meand an interruption was found.
 */
int	find_light_interruption(t_item light, t_coords target, t_itemlist *items)
{
	t_figure_point	new_point;
	t_vectors		ray;

	ray.dir = turn2unit(v_v_sub(target, light.loc));
	ray.loc = light.loc;
	while (items)
	{
		if (items->content->type == SPHERE && touches_sphere(ray, *(items->content)))
			new_point = get_sphere_point(ray, *(items->content));
		else if (items->content->type == PLANE && touches_plane(ray, *(items->content)))
			new_point = get_plane_point(ray, *(items->content));
		if (getmodule(v_v_sub(new_point.loc, ray.loc)) + 0.01 < getmodule(v_v_sub(target, ray.loc))) //! The + 0.01 is a value to avoid float precision problems.
			return (1);
		items = items->next;
	}
	return (0);
}
