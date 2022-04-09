/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtos.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/28 18:22:56 by jvacaris         ###   ########.fr       */
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

//?	To store a piont, a vector and a color. Used to indicate the collision 
//?	point between a ray and a figure.
typedef struct s_figure_point
{
	t_coords	loc;
	t_coords	dir;
	t_colors	color;
}	t_figure_point;

typedef struct s_corners
{
	t_coords	tl;
	t_coords	tr;
	t_coords	bl;
	t_coords	br;
}	t_corners;

/**
//? Linked list where content points to a t_item structure.
* @brief To store every item we're given:
* @param type		type of object (see e_type_of_object).
* @param loc		position of the object in xyz.
* @param color		object's color in rgb.
* @param orient		normal vector of the object.
* @param brightness	the brightness of a light or ambient light.
* @param diameter	the diameter of the object.
* @param height		la height of the cylinder.
* @param fov		the horizontal angle of vision of the camera.
*/
typedef struct s_item
{
	int				type;
	t_coords		loc;		//  Doesn't apply to ALIGHT.
	t_colors		color;		//  Doesn't apply to CAMERA and LIGHT.
	t_coords		orient;		//  Doesn't apply to ALIGHT, LIGHT and SPHERE.
	float			brightness;	//* Applies only to ALIGHT and LIGHT.
	float			diameter;	//* Applies only to SPHERE and CYLINDER.
	float			height;		//* Applies only to CYLINDER;
	float			fov;		//* Applies only to CAMERA.
	struct s_item	*next;
}	t_item;

/**
*	Structure to store a plane equation in the format:
*	ax + by + cz + d = 0
*/
typedef struct s_plane_equation
{
	float	a;
	float	b;
	float	c;
	float	d;
}	t_plane_equation;

#endif
