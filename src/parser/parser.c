/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:16:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/16 10:41:52 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define ERROR_SCENE "Error: invadid scene\n"

typedef struct s_mandatory_items
{
	int	ambient;
	int	camera;
	int	light;
}t_mandatory_items;

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

static int	try_get_item(t_item **list, char	*line, t_mandatory_items *m)
{
	t_item	*item;

	item = get_item(line);
	if (item == NULL)
		return (TRUE);
	m->ambient += (item->type == ALIGHT);
	m->camera += (item->type == CAMERA);
	m->light += (item->type == LIGHT);
	if (m->ambient > 1 || m->camera > 1 || (m->light > 1 && !MULTIPLE_LIGHTS))
		return (TRUE);
	printf("%s\tPARSED\t\n", line);
	lst_rt_add_front(list, item);
	return (FALSE);
}

void	get_items(t_item **list, char *argv)
{
	int					fd;
	int					error;
	char				*line;
	t_mandatory_items	m;

	error = FALSE;
	m.ambient = 0;
	m.camera = 0;
	m.light = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && !error)
	{
		if (ft_strlen(line) > 2)
			error = try_get_item(list, line, &m);
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
