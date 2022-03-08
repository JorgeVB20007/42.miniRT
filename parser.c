#include "minirt.h"

t_itemlist	**get_items(char *argv)
{
	int			fd;
	char		*line;
	char		**sep_line;
	t_itemlist	**items_list;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			sep_line = ft_split(line, ' ');
			if (!ft_strcmp(sep_line[0], "A"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2alight(sep_line)));
			else if (!ft_strcmp(sep_line[0], "C"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2camera(sep_line)));
			else if (!ft_strcmp(sep_line[0], "L"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2light(sep_line)));
			else if (!ft_strcmp(sep_line[0], "sp"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2sphere(sep_line)));
			else if (!ft_strcmp(sep_line[0], "pl"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2plane(sep_line)));
			else if (!ft_strcmp(sep_line[0], "cy"))
				ft_rt_lstadd_front(items_list, ft_rt_lstnew(line2cylinder(sep_line)));
			write(1, "J ", 2);
			free(line);
			write(1, "K ", 2);
		}
	}
	printf("\nNumber one: %d @ (%f, %f, %f)\n", (**items_list).content->type, (**items_list).content->loc.x, (**items_list).content->loc.y, (**items_list).content->loc.z);
	return (items_list);
}
