/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/30 20:43:35 by jvacaris         ###   ########.fr       */
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
			//? ¿Estas 3 líneas de aqui no son necesarias?
	if (get_ray_sphere_distance(ray, sphere) < 0.0)
		return (0);
	else
			//?
		return (1);
}

int	touches_cylinder(t_vectors ray, t_item cylinder)
{
	/*
TODO		No idea how to check this one yet :(
			- Jorge
	*/

//! ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//!
	cylinder.type = 0;								//!
	return (0);										//!
//! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
