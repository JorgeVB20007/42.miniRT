/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_collision_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:17:25 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/16 20:26:53 by jvacaris         ###   ########.fr       */
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
	/*
	*	For this one, we just need to check the distance between a line formed 
	*	by the camera vector and the central point of the sphere. 
	*	If the distance is smaller than the radius of the sphere, return 1. 
	*	Otherwise, return 0.
	*/

// ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//
	sphere.type = 0;								//
	return (0);										//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

int	touches_cylinder(t_vectors ray, t_item cylinder)
{
	/*
	TODO	No idea how to check this one yet, specially when the cylinder
	TODO	is not parallel/perpendicular to the ray :(
			- Jorge
	*/

// ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//
	cylinder.type = 0;								//
	return (0);										//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

int	touches_plane(t_vectors ray, t_item plane)
{
	/*
	*	Check
	?	https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
	*	under the section "Algebraic Form"
	*/

// ~~~~ Useless stuff to make the complier happy ~~~~
	ray.loc.x = 0;									//
	plane.type = 0;									//
	return (0);										//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
