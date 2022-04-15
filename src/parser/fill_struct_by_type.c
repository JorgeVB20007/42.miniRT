/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/15 20:50:48 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SET_DEFAULT_LIGHT_COLOR "255,255,255"

t_item	*line2alight(char **line)
{
	t_item	*item;
	int		error;

	if (line[3] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = ALIGHT;
	error += try_set_atof(&item->brightness, line[1], 0.0, 1.0);
	error += try_set_color(&item->color, line[2]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*line2camera(char **line)
{
	t_item	*item;
	int		error;

	if (line[4] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = CAMERA;
	error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
			MAX_PARSED_SIZE);
	error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	error += try_set_atof(&item->fov, line[3], 0.0, 180.0);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*line2light(char **line)
{
	t_item	*item;
	int		error;

	if (line[4] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = LIGHT;
	error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
			MAX_PARSED_SIZE);
	error += try_set_atof(&item->brightness, line[2], 0.0, 1.0);
	error += try_set_color(&item->color, line[3]);
	if (DEFAULT_LIGHT_COLOR)
		item->color = set_color(SET_DEFAULT_LIGHT_COLOR);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*line2sphere(char **line)
{
	t_item	*item;
	int		error;

	if (line[4] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = SPHERE;
	error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
			MAX_PARSED_SIZE);
	error += try_set_atof(&item->diameter, line[2], 0.0, MAX_PARSED_SIZE);
	error += try_set_color(&item->color, line[3]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*line2plane(char **line)
{
	t_item	*item;
	int		error;

	if (line[4] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = PLANE;
	error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
			MAX_PARSED_SIZE);
	error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	error += try_set_color(&item->color, line[3]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*line2cylinder(char **line)
{
	t_item	*item;
	int		error;

	if (line[4] != NULL)
		return (NULL);
	error = NONE;
	item = malloc(sizeof(t_item));
	item->type = CYLINDER;
	error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
			MAX_PARSED_SIZE);
	error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	error += try_set_atof(&item->diameter, line[3], 0.0, MAX_PARSED_SIZE);
	error += try_set_atof(&item->diameter, line[4], 0.0, MAX_PARSED_SIZE);
	error += try_set_color(&item->color, line[5]);
	return (item);
}

