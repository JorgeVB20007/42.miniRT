#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

typedef struct s_colors
{
	float	r;
	float	g;
	float	b;
}	t_colors;

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

enum e_type_of_object
{
	ALIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};

#endif