/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/27 21:06:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
static int	check_objs_in_middle(t_itemlist *items, t_figure_point point, \
t_item light, t_coords incision_vector)
{
	t_figure_point	closest_point;
	t_vectors		light_vector;

	light_vector.dir = incision_vector;
	light_vector.loc = light.loc;
	closest_point = get_closest_fig_point(light_vector.loc, items);
	if (getmodule(v_v_sub(closest_point, light.loc)) < getmodule(sub(point.loc, light.loc)))
		return (0);
	return (1);
}
*/
static float	single_light(t_figure_point point, t_item light, t_itemlist *items)
{
	t_coords	incision_vector;
	float		vect_cos;

	items = NULL;
	incision_vector = v_v_sub(point.loc, light.loc);
	vect_cos = - get_cos(incision_vector, point.dir);
	if (vect_cos < 0.0)
		vect_cos = 0;
	return (vect_cos);
}


void	calculate_reflection(t_figure_point *point, t_vectors ray, \
t_itemlist *items, t_item item_alight)
{
	t_itemlist	*lights;
	t_colors	tot_light_color;
	float		bness;

	tot_light_color.r = item_alight.color.r * item_alight.brightness;
	tot_light_color.g = item_alight.color.g * item_alight.brightness;
	tot_light_color.b = item_alight.color.b * item_alight.brightness;
	ray.loc.x++;
	ray.loc.x--;
//	printf("%.2f %.2f %.2f   vs   ", tot_light_color.r, tot_light_color.g, tot_light_color.b);
	lights = items;
	while (lights)
	{
		if (lights->content->type == LIGHT)
		{
			bness = single_light(*point, /*ray, */*(lights->content), items);
//			printf("%.2f %.2f %.2f  +  %.2f %.2f %.2f  *  %.2f  =  ", tot_light_color.r, tot_light_color.g, tot_light_color.b, lights->content->color.r, lights->content->color.g, lights->content->color.b, bness * lights->content->brightness);
			tot_light_color = color_sum(tot_light_color, 1.0, lights->content->color, bness * lights->content->brightness);
//			printf("%.2f %.2f %.2f\n", tot_light_color.r, tot_light_color.g, tot_light_color.b);
		}
		lights = lights->next;
	}
	point->color = alight2fig(point->color, tot_light_color, 1.0);
//	printf("%.2f %.2f %.2f\n", tot_light_color.r, tot_light_color.g, tot_light_color.b);
//TODO	We'll need to free the lights list.
}
