/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alight2fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:53:11 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/27 17:51:35 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	This function gets the color of a surface and the color and brightness of 
*	the ambient light and returns the resulting color. 
!	It does NOT take into account directional lights yet.
*/
t_colors	alight2fig(t_colors fig_color, t_colors alight_color, \
float alight_brightness)
{
	t_colors	result;

	result.r = (fig_color.r) * ((alight_color.r * alight_brightness) / 255);
	result.g = (fig_color.g) * ((alight_color.g * alight_brightness) / 255);
	result.b = (fig_color.b) * ((alight_color.b * alight_brightness) / 255);
	if (result.r > 255.0)
		result.r = 255.0;
	if (result.g > 255.0)
		result.g = 255.0;
	if (result.b > 255.0)
		result.b = 255.0;
	return (result);
}

t_colors	color_sum(t_colors color1, float bright1, t_colors color2, float bright2)
{
	t_colors	result;

	result.r = color1.r * bright1 + color2.r * bright2;
	result.g = color1.g * bright1 + color2.g * bright2;
	result.b = color1.b * bright1 + color2.b * bright2;
	if (result.r >= 255.0)
		result.r = 255.0;
	if (result.g >= 255.0)
		result.g = 255.0;
	if (result.b >= 255.0)
		result.b = 255.0;
	return (result);
}
