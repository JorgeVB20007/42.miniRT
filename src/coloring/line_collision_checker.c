/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/18 21:06:54 by jvacaris         ###   ########.fr       */
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
	t_coords	vector_point2point;
	t_coords	vector_crossproduct;
	float		distance;

	vector_point2point = v_v_sub(ray.loc, sphere.loc);
	vector_crossproduct = v_v_cross_product(vector_point2point, ray.dir);
	distance = getmodule(vector_crossproduct) / getmodule(ray.dir);
	if (distance <= sphere.diameter / 2)
		return (1);
	else
		return (0);

	/*
	*	For this one, we just need to check the distance between a line formed 
	*	by the camera vector and the central point of the sphere. 
	*	If the distance is smaller than the radius of the sphere, return 1. 
	*	Otherwise, return 0.
	*/
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
	/*
	*	Check
	?	https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
	*	under the section "Algebraic Form"
	*/

//! ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//!
	plane.type = 0;									//!
	return (0);										//!
//! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
				return(1);
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
