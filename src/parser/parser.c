/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:16:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 16:49:45 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_itemlist	**get_items(char *argv)
{
	int			fd;
	char		*line;
	char		**sep_line;
	t_itemlist	**items_list;

	fd = open(argv, O_RDONLY);
	items_list = malloc(sizeof(t_itemlist *));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			sep_line = ft_split(line, ' ');
			if (!ft_strcmp(sep_line[0], "A"))
				lst_rt_add_front(items_list, lst_rt_new(line2alight(sep_line)));
			else if (!ft_strcmp(sep_line[0], "C"))
			{
				lst_rt_add_front(items_list, lst_rt_new(line2camera(sep_line)));
			}
			else if (!ft_strcmp(sep_line[0], "L"))
				lst_rt_add_front(items_list, lst_rt_new(line2light(sep_line)));
			else if (!ft_strcmp(sep_line[0], "sp"))
				lst_rt_add_front(items_list, lst_rt_new(line2sphere(sep_line)));
			else if (!ft_strcmp(sep_line[0], "pl"))
				lst_rt_add_front(items_list, lst_rt_new(line2plane(sep_line)));
			else if (!ft_strcmp(sep_line[0], "cy"))
				lst_rt_add_front(items_list, lst_rt_new(line2cylinder(sep_line)));
			free(line);
		}
	}
	return (items_list);
}
