/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/20 23:11:20 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	In this file, we're just gonna check whether a line collides with one of
*	the shapes or not.
!	We're not checking the point nor the angle of such collision yet.
*/
int	touches_sphere(t_vectors ray, t_item sphere)
{
	if (line_sphere_collisionsnum(ray, sphere) == 0)
		return (0);
	if (get_ray_sphere_distance(ray, sphere) < 0.0)
		return (0);
	else
		return (1);
}

int	touches_cylinder(t_vectors ray, t_item cylinder)
{
	t_coords	result;

	if (cylinder_wall(ray, cylinder, &(result)))
		return (1);
	else if (cylinder_lid(ray, cylinder, &result, NULL))
		return (1);
	return (0);
}
	
/*
*	Intersection plane-line
?	https://www.youtube.com/watch?v=Is_wLo6yhxE
*/
int	touches_plane(t_vectors ray, t_item plane)
{
	t_vectors	plane_vectors;
	int			result;

	plane_vectors.dir = turn2unit(plane.orient);
	plane_vectors.loc = plane.loc;
	result = line_plane_correlation(ray, plane_vector2equation(plane_vectors));
	if (!result)
		return (1);
	else
		return (0);
}

int	check4collisions(t_coords vector, t_item *items, t_item	cam)
{
	t_vectors	ray;
	int			touches;

	ray.dir = turn2unit(vector);
	ray.loc = cam.loc;
	touches = 0;
	while (items)
	{
		if (items->type == SPHERE)
			touches += touches_sphere(ray, *(items));
		else if (items->type == CYLINDER)
			touches += touches_cylinder(ray, *(items));
		else if (items->type == PLANE)
			touches += touches_plane(ray, *(items));
		items = items->next;
	}
	return (touches);
}
