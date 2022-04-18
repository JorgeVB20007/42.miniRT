/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_managing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:13:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/18 21:09:58 by jvacaris         ###   ########.fr       */
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
int	get_the_m(t_vectors ray, t_item cylinder, float *m)
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
	return (1);
}
