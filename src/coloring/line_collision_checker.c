/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/21 23:22:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	In this file, we're just gonna check whether a line collides with one of
*	the shapes or not.
!	We're not checking the point nor the angle of such collision yet.
*/
static int	touches_sphere(t_vectors ray, t_item sphere)
{
	if (line_sphere_collisionsnum(ray, sphere) == 0)
		return (0);
	if (get_ray_sphere_distance(ray, sphere) < 0.0)
		return (0);
	else
		return (1);
}

static int	touches_cylinder(t_vectors ray, t_item cylinder)
{
	/*
	TODO	No idea how to check this one yet, specially when the cylinder
	TODO	is not parallel/perpendicular to the ray :(
			- Jorge
	*/

//! ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//!
	cylinder.type = 0;								//!
	return (0);										//!
//! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

static int	touches_plane(t_vectors ray, t_item plane)
{
	t_vectors	plane_vectors;
	int			result;

	plane_vectors.dir = plane.orient;
	plane_vectors.loc = plane.loc;
	result = line_plane_correlation(ray, plane_vector2equation(plane_vectors));
	if (!result)
		return (1);
	else
		return (0);
	/*
	//	Turn plane from vector and point form to equation
	//	https://www.youtube.com/watch?v=M5JQvPGueMI

	*	Intersection plane-line
	?	https://www.youtube.com/watch?v=Is_wLo6yhxE
	*/


}

int	check4collisions(t_coords vector, t_itemlist *items)
{
	t_vectors	ray;
	t_item		cam;

	ray.dir = vector;
	cam = get_item_by_type(&items, CAMERA);
	ray.loc = cam.loc;
	while (items)
	{
		if (items->content->type == SPHERE)
		{
			if (touches_sphere(ray, *(items->content)))
			{
				return(1);
			}
		}
		else if (items->content->type == CYLINDER)
		{
			if (touches_cylinder(ray, *(items->content)))
				return(1);
		}
		else if (items->content->type == PLANE)
		{
			if (touches_plane(ray, *(items->content)))
				return(1);
		}
		if (items->next == NULL)		// TODO Unsure if it's needed.
			break;						// TODO Unsure if it's needed
		items = items->next;
	}
	return (0);
}
