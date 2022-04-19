/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_managing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:13:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/19 21:34:33 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * *	This function gets the a, b and c values for a second degree equation
 * *	and writes the two results in d.
 * 
 * @note
 * -b ± sqrt(b^2 - 4ac)
 * --------------------
 * 			2a
 * 
 * @param a ax^2
 * @param b bx
 * @param c c
 * @param d[2] An array of two floats to store the two possible solutions.
 * 
 * @retval 0 No solutions could be found.
 * @retval 1 One or two solutions were found.
*/
int	second_degree_equation(float a, float b, float c, float d[2])
{
	float	inside_sqrt;

	if (a == 0.0 || powf(b, 2.0) < 4.0 * a * c)
		return (0);
	inside_sqrt = powf(b, 2.0) - (4.0 * a * c);
	d[0] = (-b + sqrtf(inside_sqrt)) / (2.0 * a);
	d[1] = (-b - sqrtf(inside_sqrt)) / (2.0 * a);
	return (1);
}

/*
//	Explanation at minirt/cylinder_explanation1.jpg and 
//	minirt/cylinder_explanation2.jpg
*/
int	get_the_m(t_vectors ray, t_item cylinder, float *m, t_coords *norm_vector)
{
	t_coords	vec_a;
	t_coords	vec_b;
	float		results[2];	

	vec_a = v_v_sub(v_v_sub(ray.loc, cylinder.loc), v_f_mult(turn2unit(cylinder.orient), \
	dot_product(turn2unit(cylinder.orient), v_v_sub(ray.loc, cylinder.loc))));
	vec_b = v_v_sub(ray.dir, v_f_mult(turn2unit(cylinder.orient), dot_product(turn2unit(cylinder.orient), ray.dir)));
	if (!second_degree_equation(powf(getmodule(vec_b), 2.0), 2 * dot_product(vec_a, vec_b), powf(getmodule(vec_a), 2.0) - powf(cylinder.diameter / 2.0, 2.0), results))
		return (0);
	if (results[0] < 0.0 && results[1] < 0.0)
		return (0);
	if (results[0] > results[1] && results[1] >= 0.0)
		*m = results[1];
	else
		*m = results[0];
	*norm_vector = turn2unit(v_v_sum(vec_a, v_f_mult(vec_b, *m)));
	return (1);
}

static void	get_lid_centres(t_item cylinder, t_coords lid[2])
{
	lid[0] = v_f_mult(turn2unit(cylinder.orient), cylinder.height / 2);
	lid[1] = v_f_mult(turn2unit(cylinder.orient), - cylinder.height / 2);
}

int	lid_collision(t_vectors ray, t_item cylinder, t_vectors *result)
{
	t_vectors		plane_vectors[2];
	float			t[2];
	t_coords		temp_coords[2];
	int				best_coord;
	t_coords		lids[2];

	if (dot_product(ray.dir, cylinder.orient) == 0.0)
		return (0);
	get_lid_centres(cylinder, lids);
	plane_vectors[0].dir = turn2unit(cylinder.orient);
	plane_vectors[0].loc = lids[0];
	plane_vectors[1].dir = turn2unit(v_f_mult(cylinder.orient, -1.0));
	plane_vectors[1].loc = lids[1];
	t[0] = get_the_t(ray, plane_vector2equation(plane_vectors[0]));
	t[1] = get_the_t(ray, plane_vector2equation(plane_vectors[1]));
	temp_coords[0] = v_v_sum(v_f_mult(turn2unit(ray.dir), t[0]), ray.loc);
	temp_coords[1] = v_v_sum(v_f_mult(turn2unit(ray.dir), t[1]), ray.loc);
	best_coord = getmodule(v_v_sub(temp_coords[0], ray.loc)) > getmodule(v_v_sub(temp_coords[1], ray.loc));
	if (getmodule(v_v_sub(temp_coords[best_coord], lids[best_coord])) > cylinder.diameter / 2)
		return (0);
	result->loc = temp_coords[best_coord];
	result->dir = plane_vectors[best_coord].dir;
	return (1);
}

