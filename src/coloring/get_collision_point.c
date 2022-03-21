/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:21 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/21 22:54:32 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Here we'll get the exact point where the ray collided with each figure, 
*	the normal vector of the collision point and the resulting color.
! 	The resulting color is not implemented yet.
*/
t_figure_point	get_plane_point(t_vectors ray, t_item plane)
{
	t_vectors		plane_vectors;
	t_figure_point	result;
	int			t;

	plane_vectors.dir = plane.orient;
	plane_vectors.loc = plane.loc;
	t = get_the_t(ray, plane_vector2equation(plane_vectors));
	result.loc = v_v_sum(v_i_mult(plane.orient, t), plane.loc);
	result.dir = plane.orient;
	return (result);
}

t_figure_point	get_sphere_point(t_vectors ray, t_item sphere)
{
	t_figure_point	result;

	result.loc = v_v_sum(v_i_mult(ray.dir, get_ray_sphere_distance(ray, \
	sphere)), ray.loc);
	result.dir = v_v_sub(sphere.loc, result.loc);
	return (result);
}
