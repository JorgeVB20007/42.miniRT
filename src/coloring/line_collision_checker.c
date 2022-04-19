/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/19 21:35:44 by jvacaris         ###   ########.fr       */
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
	float		m;
	t_vectors	p_prime;
	t_coords	nothing;

	if (!get_the_m(ray, cylinder, &m, &nothing))
			return (0);
	if (lid_collision(ray, cylinder, &p_prime))
		return (1);
	p_prime.loc = v_v_sum(ray.loc, v_f_mult(ray.dir, m));
	if (powf(getmodule(v_v_sub(p_prime.loc, cylinder.loc)), 2.0) > powf(cylinder.height / 2.0, 2.0) + powf(cylinder.diameter / 2.0, 2.0))
		return (0);
	return (1);
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
