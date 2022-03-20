/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtos.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/19 19:53:10 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTOS_H
# define DTOS_H

//?	To store coordinates in x,y,z.
typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

//?	To store vectors with their coordinates (loc) & its direction (dir).
typedef struct s_vectors
{
	t_coords	loc;
	t_coords	dir;
}	t_vectors;

//?	To store colors in r,g,b.
typedef struct s_colors
{
	float	r;
	float	g;
	float	b;
}	t_colors;

typedef struct s_corners
{
	t_coords	tl;
	t_coords	tr;
	t_coords	bl;
	t_coords	br;
}	t_corners;

/*
?	To store every item we're given:
*	type:		type of object (see e_type_of_object).
*	loc:		position of the object in xyz.
*	color:		object's color in rgb.
*	orient:		normal vector of the object.
*	brightness:	the brightness of a light or ambient light.
*	diameter:	the diameter of the object.
*	height:		la height of the cylinder.
*	fov:		the horizontal angle of vision of the camera.
*/
typedef struct s_item
{
	int			type;
	t_coords	loc;		//  Doesn't apply to ALIGHT.
	t_colors	color;		//  Doesn't apply to CAMERA and LIGHT.
	t_coords	orient;		//  Doesn't apply to ALIGHT, LIGHT and SPHERE.
	float		brightness;	//* Applies only to ALIGHT and LIGHT.
	float		diameter;	//* Applies only to SPHERE and CYLINDER.
	float		height;		//* Applies only to CYLINDER;
	float		fov;		//* Applies only to CAMERA.
}	t_item;

//? Linked list where content points to a t_item structure.
typedef struct s_itemlist
{
	t_item				*content;
	struct s_itemlist	*next;
}	t_itemlist;

/*
*	Structure to store a plane equation in the format:
?	ax + by + cz + d = 0
*/
typedef struct s_plane_equation
{
	float	a;
	float	b;
	float	c;
	float	d;
}	t_plane_equation;

#endif
