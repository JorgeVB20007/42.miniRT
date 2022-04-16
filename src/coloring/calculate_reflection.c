/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/16 19:49:33 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
t_item item_alight)
{
	t_item		*lights;
	t_colors	tot_light_color;
	float		bness;

	tot_light_color.r = item_alight.color.r * item_alight.brightness;
	tot_light_color.g = item_alight.color.g * item_alight.brightness;
	tot_light_color.b = item_alight.color.b * item_alight.brightness;
	lights = items;
	while (lights)
	{
		if (lights->type == LIGHT)
		{
			bness = single_light(*point, *(lights), items) * \
					find_light_interruption(*(lights), *point, items);
			tot_light_color = color_sum(tot_light_color, 1.0, lights->color, \
					bness * lights->brightness);
		}
		lights = lights->next;
	}
	point->color = alight2fig(point->color, tot_light_color, 1.0);
}
