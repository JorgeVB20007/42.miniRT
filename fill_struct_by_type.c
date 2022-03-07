#include "minirt.h"

t_item	line2alight(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = ALIGHT;
	item.brightness = ft_atof(line[1]);
	split_commas =  ft_split(line[2], ',');
	item.color.r = ft_atof(split_commas[0]);
	item.color.g = ft_atof(split_commas[1]);
	item.color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}

t_item	line2camera(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = CAMERA;
	split_commas =  ft_split(line[1], ',');
	item.loc.x = ft_atof(split_commas[0]);
	item.loc.y = ft_atof(split_commas[1]);
	item.loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item.orient.x = ft_atof(split_commas[0]);
	item.orient.y = ft_atof(split_commas[1]);
	item.orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item.fov = ft_atof(line[3]);
	return (item);
}

t_item	line2light(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = LIGHT;
	split_commas =  ft_split(line[1], ',');
	item.loc.x = ft_atof(split_commas[0]);
	item.loc.y = ft_atof(split_commas[1]);
	item.loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item.brightness = ft_atof(line[2]);
	return (item);
}

t_item	line2sphere(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = SPHERE;
	split_commas =  ft_split(line[1], ',');
	item.loc.x = ft_atof(split_commas[0]);
	item.loc.y = ft_atof(split_commas[1]);
	item.loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	item.diameter = ft_atof(line[2]);
	split_commas =  ft_split(line[3], ',');
	item.color.r = ft_atof(split_commas[0]);
	item.color.g = ft_atof(split_commas[1]);
	item.color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}

t_item	line2plane(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = PLANE;
	split_commas =  ft_split(line[1], ',');
	item.loc.x = ft_atof(split_commas[0]);
	item.loc.y = ft_atof(split_commas[1]);
	item.loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item.orient.x = ft_atof(split_commas[0]);
	item.orient.y = ft_atof(split_commas[1]);
	item.orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[3], ',');
	item.color.r = ft_atof(split_commas[0]);
	item.color.g = ft_atof(split_commas[1]);
	item.color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}

t_item	line2cylinder(char **line)
{
	t_item	item;
	char	**split_commas;

	item.type = CYLINDER;
	split_commas =  ft_split(line[1], ',');
	item.loc.x = ft_atof(split_commas[0]);
	item.loc.y = ft_atof(split_commas[1]);
	item.loc.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	split_commas =  ft_split(line[2], ',');
	item.orient.x = ft_atof(split_commas[0]);
	item.orient.y = ft_atof(split_commas[1]);
	item.orient.z = ft_atof(split_commas[2]);
	megafree(&split_commas);
	ft_atof(line[3]);
	ft_atof(line[4]);
	split_commas =  ft_split(line[5], ',');
	item.color.r = ft_atof(split_commas[0]);
	item.color.g = ft_atof(split_commas[1]);
	item.color.b = ft_atof(split_commas[2]);
	megafree(&split_commas);
	return (item);
}
