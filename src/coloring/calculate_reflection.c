/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/24 21:14:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static t_colors	col_f_mult(t_colors color, float brightness)
// {
// 	t_colors	result;

// 	result.r = color.r * brightness;
// 	result.g = color.g * brightness;
// 	result.b = color.b * brightness;
// 	return (result);
// }

static float	single_light(t_figure_point point, t_item light, t_item *items)
{
	t_coords	incision_vector;
	float		vect_cos;

	items = NULL;
	incision_vector = v_v_sub(light.loc, point.loc);
	vect_cos = get_cos(incision_vector, point.dir);
	if (vect_cos < 0.0)
		vect_cos = 0.0;
	return (vect_cos);
}

void	calculate_reflection(t_figure_point *point, t_item *items, \
t_item item_alight, t_vectors ray)
{
	t_item		*lights;
	t_colors	tot_light_color;
	float		bness;
	t_colors	tot_phong_color;
	int			interruption;

	tot_light_color.r = item_alight.color.r * item_alight.brightness;
	tot_light_color.g = item_alight.color.g * item_alight.brightness;
	tot_light_color.b = item_alight.color.b * item_alight.brightness;
	tot_phong_color.r = 0.0;
	tot_phong_color.g = 0.0;
	tot_phong_color.b = 0.0;
	lights = items;
	while (lights)
	{
		if (lights->type == LIGHT)
		{
			interruption = find_light_interruption(*(lights), *point, items);
			bness = single_light(*point, *(lights), items) * \
					(float)interruption;
			tot_light_color = color_sum(tot_light_color, 1.0, lights->color, \
					bness * lights->brightness);
			if (interruption)
				tot_phong_color = color_sum(tot_phong_color, 1.0, lights->color, specular_reflection(*lights, *point, ray) * lights->brightness);
//			printf("bness = %f  |  tot_color = (%5.1f,%5.1f,%5.1f)\n", bness, tot_light_color.r, tot_light_color.g, tot_light_color.b);
		}
		lights = lights->next;
	}
	point->color = color_sum(alight2fig(point->color, tot_light_color, 1.0), 1.0, tot_phong_color, 1.0);
}
