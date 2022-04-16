/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:16:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/16 19:36:54 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define ERROR_SCENE "Error: invadid scene\n"

//* Element type counters to handle errors
typedef struct s_mandatory_items
{
	int	ambient;
	int	camera;
	int	light;
}t_mandatory_items;

/**
 * * Get item from a line read of a scene file regarding element's type
 * @param line	line to process from scene file
 * @return 		*t_item/NULL as ok/error
 */
static	t_item	*get_item(char	*line)
{
	t_item	*item;
	char	**sep_line;

	item = NULL;
	sep_line = ft_split(line, ' ');
	if (!ft_strcmp(sep_line[0], "A"))
		item = line2alight(sep_line);
	else if (!ft_strcmp(sep_line[0], "C"))
		item = line2camera(sep_line);
	else if (!ft_strcmp(sep_line[0], "L"))
		item = line2light(sep_line);
	else if (!ft_strcmp(sep_line[0], "sp"))
		item = line2sphere(sep_line);
	else if (!ft_strcmp(sep_line[0], "pl"))
		item = line2plane(sep_line);
	else if (!ft_strcmp(sep_line[0], "cy"))
		item = line2cylinder(sep_line);
	megafree(&sep_line);
	return (item);
}

/**
 * * Get item from a line read of a scene file
 * @param list	list of items to populate
 * @param line	line to process from scene file
 * @param m		element type counters to handle errors
 * @return 		FALSE/TRUE as ok/error
 */
static int	try_get_item(t_item **list, char	*line, t_mandatory_items *m, int id)
{
	t_item	*item;

	item = get_item(line);
	if (item == NULL)
		return (TRUE);
	m->ambient += (item->type == ALIGHT);
	m->camera += (item->type == CAMERA);
	m->light += (item->type == LIGHT);
	item->id = id;
	if (m->ambient > 1 || m->camera > 1 || (m->light > 1 && !MULTIPLE_LIGHTS))
		return (TRUE);
	lst_rt_add_front(list, item);
	return (FALSE);
}

/**
 * * Get items from a given scene file
 * @param list			returned list of items
 * @param scene_file	scene file to process
*/
void	get_items(t_item **list, char *scene_file)
{
	int					fd;
	int					error;
	char				*line;
	t_mandatory_items	m;
	int					id;

	error = FALSE;
	m.ambient = 0;
	m.camera = 0;
	m.light = 0;
	fd = open(scene_file, O_RDONLY);
	id = 0;
	while (get_next_line(fd, &line) > 0 && !error)
	{
		if (ft_strlen(line) > 2)
			error = try_get_item(list, line, &m, id++);
		free(line);
	}
	if (error || m.ambient != 1 || m.camera != 1 || \
		(m.light != 1 && !MULTIPLE_LIGHTS))
	{
		lst_rt_free(list);
		ft_putstr_fd(ERROR_SCENE, STDERR_FILENO);
	}
	close(fd);
}
