/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:21 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/16 19:49:05 by jvacaris         ###   ########.fr       */
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
	float			t;

	plane_vectors.dir = turn2unit(plane.orient);
	plane_vectors.loc = plane.loc;
	t = get_the_t(ray, plane_vector2equation(plane_vectors));
	result.loc = v_v_sum(v_f_mult(turn2unit(ray.dir), t), ray.loc);
	result.dir = turn2unit(rotate_plane_if_needed(\
		dir_and_loc_2_vector(plane.loc, plane.orient), ray));
	result.color = plane.color;
	result.id = plane.id;
	return (result);
}

static t_figure_point	get_sphere_point(t_vectors ray, t_item sphere)
{
	t_figure_point	result;

	result.loc = v_v_sum(v_f_mult(ray.dir, get_ray_sphere_distance(ray, \
	sphere)), ray.loc);
	result.dir = v_v_sub(result.loc, sphere.loc);
	result.color = sphere.color;
	result.id = sphere.id;
	return (result);
}

/*
*	This function gets the list of items and the ray being evaluated when
*	there's at least one collision. It will return the closest collision
*	point, along with the normal vector and the color of the figure involved
*	mixed with the color and brightness of the ALIGHT.
*/
t_figure_point	get_closest_fig_point(t_vectors ray, t_item *items)
{
	t_figure_point	new_point;
	t_figure_point	top_point;
	t_item			item_alight;
	int				ctrl;
	t_item			*items2;

	ctrl = 0;
	items2 = items;
	item_alight = get_item_by_type(&items, ALIGHT);
	while (items)
	{
		if (items->type == SPHERE && touches_sphere(ray, *(items)))
			new_point = get_sphere_point(ray, *(items));
		else if (items->type == PLANE && touches_plane(ray, *(items)))
			new_point = get_plane_point(ray, *(items));
		if (!ctrl || getmodule(v_v_sub(new_point.loc, ray.loc)) < \
			getmodule(v_v_sub(top_point.loc, ray.loc)))
		{
			top_point = new_point;
			ctrl = 1;
		}
		if (items->next == NULL)
			break ;
		items = items->next;
	}
	calculate_reflection(&top_point, items2, item_alight);
	return (top_point);
}

/**
 * Here we're checking if there's an object between the light and the point
 * being evaluated. To know if there's objects in between, we check the
 * distance from the light to the first point touched. 
 * If the object we touch is closer to the light than the point evaluated, we
 * consider it an obstacle. The problem is that a slight inconsistency with
 * floats can make the beam collide decimals before it's supposed to. 
 * 
 * 
 * @retval 1 means that no interruptions were found.
 * @retval 0 means an interruption was found.
 */
int	find_light_interruption(t_item light, t_figure_point target, t_item *items)
{
	t_figure_point	new_point;
	t_vectors		ray;
	int				a;

	ray.dir = turn2unit(v_v_sub(target.loc, light.loc));
	ray.loc = light.loc;
	a = 0;
	while (items)
	{
		if (items->id != target.id)
		{
			if (items->type == SPHERE && touches_sphere(ray, *(items)))
			{
				a = 1;
				new_point = get_sphere_point(ray, *(items));
			}
			else if (items->type == PLANE && touches_plane(ray, *(items)))
			{
				a = 1;
				new_point = get_plane_point(ray, *(items));
			}
			if (a && getmodule(v_v_sub(new_point.loc, light.loc)) < getmodule(v_v_sub(target.loc, light.loc))) //! The + 0.01 is a value to avoid float precision problems.
				return (0);
		}
		items = items->next;
	}
	return (1);
}
