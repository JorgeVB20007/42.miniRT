/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:22:08 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/26 22:14:51 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	single_light(t_figure_point point, t_vectors ray, t_item light)
{
	t_coords	incision_vector;

	incision_vector = v_v_sub(point.loc, light.loc);
	/*
	*	Take formula from here.
	?	https://drive.google.com/file/d/1OepZ4vfFvYe6Avsskx1x2m-Xr8MT2xly/view?usp=sharing
	*/
}

void	calculate_reflection(t_figure_point *point, t_vectors ray, t_itemlist *items)
{
	t_itemlist	*lights;
	t_colors	tot_light_color;

	tot_light_color.r = 0.0;
	tot_light_color.g = 0.0;
	tot_light_color.b = 0.0;
	get_items_by_type(&lights, items, LIGHT);




//TODO	We'll need to free the lights list.
}
