/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmodule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:57:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 22:23:13 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Returns vector's module
 * @param vector
*/
float	getmodule(t_coords vector)
{
	float	result;

	result = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	return (result);
}

t_colors get_color(t_colors rgb)
{
	t_colors	color;

	color.r = rgb.r;
	color.g = rgb.g;
	color.b = rgb.b;
	return (color);
}

t_colors set_color(char **rgb)
{
	t_colors	color;

	color.r = ft_atof(rgb[0]);
	color.g = ft_atof(rgb[1]);
	color.b = ft_atof(rgb[2]);
	return (color);
}

t_coords get_coords(t_coords coords)
{
	t_coords	coordinates;

	coordinates.x = coords.x;
	coordinates.y = coords.y;
	coordinates.z = coords.z;
	return (coordinates);
}

t_coords set_coords(char **coords)
{
	t_coords	coordinates;

	coordinates.x = ft_atof(coords[0]);
	coordinates.y = ft_atof(coords[1]);
	coordinates.z = ft_atof(coords[2]);
	return (coordinates);
}
