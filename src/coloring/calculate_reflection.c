/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 19:36:59 by jvacaris         ###   ########.fr       */
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

/**
 * * In this function, we're calculating what lights (ambient and 
 * * multidirectional) collide with the point being evaluated and we add them 
 * * all toghether considering the angle between the normal vector of the point
 * * and the light and the brightness of each light.
 * * Then, we apply the overall light to the color of the point.
 * * If RENDER_PHONG is set to true, it will also apply the Specular Reflection
 * * to the overall color, but this one gets applied directly above the figure.
 * 
 * @param point A struct containing the location of the collision point, its normal vector, the color of the object (not counting lights) and its ID.
 * @param items List of all the items.
 * @param item_alight The ambient light of the scene.
 * @param ray The current ray projected bby the camera (struct containing the loc and dir as a unitary vector).
 *
 * @retval Nothing is returned, but the value of color in point gets modified.
*/
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
			if (interruption)
			{
				bness = single_light(*point, *(lights), items);
				tot_light_color = color_sum(tot_light_color, 1.0, lights->color, \
					bness * lights->brightness);
				if (RENDER_PHONG)
					tot_phong_color = color_sum(tot_phong_color, 1.0, lights->color, specular_reflection(*lights, *point, ray) * lights->brightness * (0.45 / (0.5 + 0.1 * (getmodule(v_v_sub(point->loc, lights->loc)))) + 0.1));
			}
		}
		lights = lights->next;
	}
	point->color = color_sum(light2fig(point->color, tot_light_color, 1.0), 1.0, tot_phong_color, (float)RENDER_PHONG);
}
