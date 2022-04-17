/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/17 23:08:28 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SET_DEFAULT_LIGHT_COLOR "255,255,255"

static t_item	*line2alight(char **line, t_item	*item)
{
	int	error;

	error = (line[3] != NULL);
	item->type = ALIGHT;
	if (!error)
		error += try_set_atof(&item->brightness, line[1], 0.0, 1.0);
	if (!error)
		error += try_set_color(&item->color, line[2]);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2camera(char **line, t_item	*item)
{
	int	error;

	error = (line[4] != NULL);
	item->type = CAMERA;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_coords(&item->orient, line[2], -1.0, 1.0);
	if (!error)
		error += try_set_atof(&item->fov, line[3], 0.0, 180.0);
	if (error)
		ft_free((void **) &item);
	return (item);
}

static t_item	*line2light(char **line, t_item	*item)
{
	int	error;

	error = (line[4] != NULL);
	item->type = LIGHT;
	if (!error)
		error += try_set_coords(&item->loc, line[1], MIN_PARSED_SIZE, \
				MAX_PARSED_SIZE);
	if (!error)
		error += try_set_atof(&item->brightness, line[2], 0.0, 1.0);
	if (!error)
		error += try_set_color(&item->color, line[3]);
	if (DEFAULT_LIGHT_COLOR)
		item->color = set_color(SET_DEFAULT_LIGHT_COLOR);
	if (error)
		ft_free((void **) &item);
	return (item);
}

t_item	*init_new_item(t_item	*item)
{
	item->brightness = 0.0;
	item->color.r = 0.0;
	item->color.g = 0.0;
	item->color.b = 0.0;
	item->diameter = 0.0;
	item->fov = 0.0;
	item->height = 0.0;
	item->id = -1;
	item->loc.x = 0.0;
	item->loc.y = 0.0;
	item->loc.z = 0.0;
	item->orient.x = 0.0;
	item->orient.y = 0.0;
	item->orient.z = 0.0;
	item->next = NULL;
	item->type = -1;
	return (item);
}

t_item	*fill_struct_by_type(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (!item)
		return (NULL);
	item = init_new_item(item);
	if (!ft_strcmp(line[0], "A"))
		item = line2alight(line, item);
	else if (!ft_strcmp(line[0], "C"))
		item = line2camera(line, item);
	else if (!ft_strcmp(line[0], "L"))
		item = line2light(line, item);
	else
		ft_free((void **) &item);
	return (item);
}
