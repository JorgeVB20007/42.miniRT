/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 18:26:17 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_item	*line2alight(char **line)
{
	t_item	*item;
	char	**split_commas;

	write(1, "A ", 2);
	item = malloc(sizeof(t_item));
	write(1, "B ", 2);
	item->type = ALIGHT;
	write(1, "C ", 2);
	item->brightness = ft_atof(line[1]);
	write(1, "D ", 2);
	split_commas =  ft_split(line[2], ',');
	write(1, "E ", 2);
	item->color.r = ft_atof(split_commas[0]);
	write(1, "F ", 2);
	item->color.g = ft_atof(split_commas[1]);
	write(1, "G ", 2);
	item->color.b = ft_atof(split_commas[2]);
	write(1, "H ", 2);
	megafree(&split_commas);
	write(1, "I ", 2);
	return (item);
}

t_item	*line2camera(char **line)
{
	t_item	*item;
	char	**split_commas;

	item = malloc(sizeof(t_item));
	item->type = CAMERA;
	split_commas =  ft_split(line[1], ',');
	item->loc.x = ft_atof(split_commas[0]);
	item->loc.y = ft_atof(split_commas[1]);
	item->loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item->orient.x = ft_atof(split_commas[0]);
	item->orient.y = ft_atof(split_commas[1]);
	item->orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item->fov = ft_atof(line[3]);
	return (item);
}

t_item	*line2light(char **line)
{
	t_item	*item;
	char	**split_commas;

	item = malloc(sizeof(t_item));
	item->type = LIGHT;
	split_commas =  ft_split(line[1], ',');
	item->loc.x = ft_atof(split_commas[0]);
	item->loc.y = ft_atof(split_commas[1]);
	item->loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item->brightness = ft_atof(line[2]);
	return (item);
}

t_item	*line2sphere(char **line)
{
	t_item	*item;
	char	**split_commas;

	item = malloc(sizeof(t_item));
	item->type = SPHERE;
	split_commas =  ft_split(line[1], ',');
	item->loc.x = ft_atof(split_commas[0]);
	item->loc.y = ft_atof(split_commas[1]);
	item->loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item->diameter = ft_atof(line[2]);
	split_commas =  ft_split(line[3], ',');
	item->color.r = ft_atof(split_commas[0]);
	item->color.g = ft_atof(split_commas[1]);
	item->color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}

t_item	*line2plane(char **line)
{
	t_item	*item;
	char	**split_commas;

	item = malloc(sizeof(t_item));
	item->type = PLANE;
	split_commas =  ft_split(line[1], ',');
	item->loc.x = ft_atof(split_commas[0]);
	item->loc.y = ft_atof(split_commas[1]);
	item->loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item->orient.x = ft_atof(split_commas[0]);
	item->orient.y = ft_atof(split_commas[1]);
	item->orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[3], ',');
	item->color.r = ft_atof(split_commas[0]);
	item->color.g = ft_atof(split_commas[1]);
	item->color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}

t_item	*line2cylinder(char **line)
{
	t_item	*item;
	char	**split_commas;

	item = malloc(sizeof(t_item));
	item->type = CYLINDER;
	split_commas =  ft_split(line[1], ',');
	item->loc.x = ft_atof(split_commas[0]);
	item->loc.y = ft_atof(split_commas[1]);
	item->loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item->orient.x = ft_atof(split_commas[0]);
	item->orient.y = ft_atof(split_commas[1]);
	item->orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	ft_atof(line[3]);
	ft_atof(line[4]);
	split_commas =  ft_split(line[5], ',');
	item->color.r = ft_atof(split_commas[0]);
	item->color.g = ft_atof(split_commas[1]);
	item->color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}
