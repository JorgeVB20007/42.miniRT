/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 22:38:36 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_item	*line2alight(char **line)
{
	t_item	*item;
	char	**rgb;

	item = malloc(sizeof(t_item));
	item->type = ALIGHT;
	item->brightness = ft_atof(line[1]);
	rgb = ft_split(line[2], ',');
	item->color = set_color(rgb);
	megafree(&rgb);
	return (item);
}

t_item	*line2camera(char **line)
{
	t_item	*item;
	char	**coords;

	item = malloc(sizeof(t_item));
	item->type = CAMERA;
	coords = ft_split(line[1], ',');
	item->loc = set_coords(coords);
	megafree(&coords);
	coords = ft_split(line[2], ',');
	item->orient = set_coords(coords);
	megafree(&coords);
	item->fov = ft_atof(line[3]);
	return (item);
}

t_item	*line2light(char **line)
{
	t_item	*item;
	char	**coords;

	item = malloc(sizeof(t_item));
	item->type = LIGHT;
	coords = ft_split(line[1], ',');
	item->loc = set_coords(coords);
	megafree(&coords);
	item->brightness = ft_atof(line[2]);
	return (item);
}

t_item	*line2sphere(char **line)
{
	t_item	*item;
	char	**split;

	item = malloc(sizeof(t_item));
	item->type = SPHERE;
	split = ft_split(line[1], ',');
	item->loc = set_coords(split);
	megafree(&split);
	item->diameter = ft_atof(line[2]);
	split = ft_split(line[3], ',');
	item->color = set_color(split);
	megafree(&split);
	return (item);
}

t_item	*line2plane(char **line)
{
	t_item	*item;
	char	**split;

	item = malloc(sizeof(t_item));
	item->type = PLANE;
	split = ft_split(line[1], ',');
	item->loc = set_coords(split);
	megafree(&split);
	split = ft_split(line[2], ',');
	item->orient = set_coords(split);
	megafree(&split);
	split = ft_split(line[3], ',');
	item->color = set_color(split);
	megafree(&split);
	return (item);
}

t_item	*line2cylinder(char **line)
{
	t_item	*item;
	char	**split;

	item = malloc(sizeof(t_item));
	item->type = CYLINDER;
	split = ft_split(line[1], ',');
	item->loc = set_coords(split);
	megafree(&split);
	split = ft_split(line[2], ',');
	item->orient = set_coords(split);
	megafree(&split);
	ft_atof(line[3]);
	ft_atof(line[4]);
	split = ft_split(line[5], ',');
	item->color = set_color(split);
	megafree(&split);
	return (item);
}

