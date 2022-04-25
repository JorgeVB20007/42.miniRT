/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_reflection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:38:30 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/25 19:16:05 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

t_coords	get_reflection_vector(t_coords vec_in, t_coords vec_norm)
{
    return (turn2unit(v_v_sub(vec_in, v_f_mult(vec_norm, 2 * \
	dot_product(vec_in, vec_norm)))));
}

/*
*	If object.dir was already a unit vector, that'd be great.
*/
float	specular_reflection(t_item light, t_figure_point object, t_vectors ray)
{
	t_coords	vec_in;
	t_coords	vec_out;
	t_coords	vec_obj_cam;
	float		result;

	vec_in = turn2unit(v_v_sub(object.loc, light.loc));
	vec_out = get_reflection_vector(vec_in, turn2unit(object.dir));
	vec_obj_cam = turn2unit(v_v_sub(ray.loc, object.loc));
	result = get_cos(vec_out, vec_obj_cam);
//	result = (result - 0.9) * 10;
	if (result < 0.0)
		return (0.0);
//	result = powf(result, 5.0);
	if (result < 0.0)
		return (0.0);
	else
		return (result);
}
