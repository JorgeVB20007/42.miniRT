/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder_managing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:11:05 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/20 23:31:37 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	do_the_f(t_coords vec_u, t_coords vec_w, t_coords vec_ori)
{
	return (dot_product(vec_u, vec_w) - dot_product(vec_ori, vec_u) * \
	dot_product(vec_ori, vec_w));
}

int	cylinder_lid(t_vectors ray, t_item cylinder, t_coords *coords, int *rev_ori)
{
	float	m;
	float	possible_ms[2];
	t_coords	pc;

	pc = v_v_sub(ray.loc, cylinder.loc);
	possible_ms[0] = (cylinder.height / 2.0 - dot_product(cylinder.orient, pc)) / dot_product(cylinder.orient, ray.dir);
	possible_ms[1] = (- cylinder.height / 2.0 - dot_product(cylinder.orient, pc)) / dot_product(cylinder.orient, ray.dir);
	if (possible_ms[0] >= 0.0 && possible_ms[0] < possible_ms[1])
	{
		m = possible_ms[0];
		if (rev_ori)
			*rev_ori = 1;
	}
	else if (possible_ms[1] >= 0.0)
	{
		m = possible_ms[1];
		if (rev_ori)
			*rev_ori = -1;
	}
	else
		return (0);
	if (do_the_f(v_v_sum(pc, v_f_mult(ray.dir, m)), v_v_sum(pc, v_f_mult(ray.dir, m)), cylinder.orient) >= powf(cylinder.diameter / 2.0, 2.0))
		return (0);
	*coords = v_v_sum(v_f_mult(ray.dir, m), ray.loc);
	return (1);
}

int	cylinder_wall(t_vectors ray, t_item cylinder, t_coords *coords)
{
	float		m;
	float		possible_ms[2];
	t_coords	pc;

	pc = v_v_sub(ray.loc, cylinder.loc);
	if (!second_degree_equation(do_the_f(ray.dir, ray.dir, turn2unit(cylinder.orient)), 2.0 * do_the_f(pc, ray.dir, turn2unit(cylinder.orient)), \
	do_the_f(pc, pc, turn2unit(cylinder.orient)) - powf(cylinder.diameter / 2.0, 2.0), possible_ms))
		return (0);
	if (possible_ms[0] >= 0.0 && possible_ms[0] < possible_ms[1])
		m = possible_ms[0];
	else if (possible_ms[1] >= 0.0)
		m = possible_ms[1];
	else
		return (0);
	if (fabs(dot_product(cylinder.orient, v_v_sum(pc, v_f_mult(ray.dir, m)))) > cylinder.height / 2.0)
		return (0);
	if (coords)
		*coords = v_v_sum(ray.loc, v_f_mult(ray.dir, m));
	return (1);
}

t_figure_point	new_get_cylinder_point(t_vectors ray, t_item cylinder)
{
	t_figure_point	result;
	int				rev_ori;

	ray.dir = turn2unit(ray.dir);
	cylinder.orient = turn2unit(cylinder.orient);
	if (cylinder_wall(ray, cylinder, &(result.loc)))
		result.dir = v_v_sum(cylinder.loc, v_f_mult(cylinder.orient, dot_product(v_v_sub(result.loc, cylinder.loc), cylinder.orient)));
	else if (cylinder_lid(ray, cylinder, &(result.loc), &rev_ori))
		result.dir = v_f_mult(cylinder.orient, rev_ori);
	result.color = cylinder.color;
	result.id = cylinder.id;
	return (result);
}
