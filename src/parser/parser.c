/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:16:37 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/14 00:02:40 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	deg2rad(float deg)
{
	return(deg * (M_PI / 180));
}

void	set_corners(t_itemlist *item)
{
	t_coords	v;
	t_coords	unit_v;
	float		module;
	t_coords	q;
	t_coords	unit_q;
	t_coords	a;
	t_coords	tl;
	t_coords	tr;
	t_coords	bl;
	t_coords	br;

	v = item->content->orient;
	module = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2));
	unit_v.x = v.x / module;
	unit_v.y = v.y / module;
	unit_v.z = v.z / module;
	q.x = -unit_v.z;
	q.y = 0.0;
	q.z = unit_v.x;
	module = sqrtf(powf(q.x, 2) + powf(q.y, 2) + powf(q.z, 2));
	if (module)
	{
		unit_q.x = q.x / module;
		unit_q.z = q.z / module;
	}
	else
	{
		unit_q.x = 1.0;
		unit_q.z = 0.0;
	}
	unit_q.y = 0.0;
	a.x = -unit_q.z * unit_v.y;
	a.y = +unit_v.x * unit_q.z - unit_q.x * unit_v.z;
	a.z = -unit_q.x * unit_v.y;
	printf("\nv unitari: (%2f, %2f, %2f)", unit_v.x, unit_v.y, unit_v.z);
	printf("\nq unitari: (%2f, %2f, %2f)", unit_q.x, unit_q.y, unit_q.z);
	printf("\na: (%2f, %2f, %2f)", a.x, a.y, a.z);

	tl.x = unit_v.x - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.x + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.x;
	tl.y = unit_v.y - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.y + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.y;
	tl.z = unit_v.z - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.z + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.z;

	tr.x = unit_v.x + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.x + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.x;
	tr.y = unit_v.y + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.y + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.y;
	tr.z = unit_v.z + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.z + tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.z;

	bl.x = unit_v.x - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.x - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.x;
	bl.y = unit_v.y - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.y - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.y;
	bl.z = unit_v.z - tanf(deg2rad(item->content->fov / 2.0)) * unit_q.z - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.z;

	br.x = unit_v.x + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.x - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.x;
	br.y = unit_v.y + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.y - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.y;
	br.z = unit_v.z + tanf(deg2rad(item->content->fov / 2.0)) * unit_q.z - tanf(deg2rad(item->content->fov / 2.0)) * (9.0 / 16.0) * a.z;

	printf("\nCamera position:    (%2f, %2f, %2f)\n", item->content->loc.x, item->content->loc.y, item->content->loc.z);
	printf("Camera orientation: (%2f, %2f, %2f)\n", item->content->orient.x, item->content->orient.y, item->content->orient.z);
	printf("\nTop left:  (%2f, %2f, %2f)", tl.x, tl.y, tl.z);
	printf("\nTop right:  (%2f, %2f, %2f)", tr.x, tr.y, tr.z);
	printf("\nBtm left:  (%2f, %2f, %2f)", bl.x, bl.y, bl.z);
	printf("\nBtm right:  (%2f, %2f, %2f)\n", br.x, br.y, br.z);


}

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
				set_corners(*items_list);
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
//	printf("\nNumber one: %d @ (%f, %f, %f)\n", (**items_list).content->type, (**items_list).content->loc.x, (**items_list).content->loc.y, (**items_list).content->loc.z);
	return (items_list);
}
