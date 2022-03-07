#include "minirt.h"

t_item	*get_items(char *argv)
{
	int		fd;
	char	*line;
	char	**sep_line;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		sep_line = ft_split(line, ' ');
		if (ft_strcmp(sep_line, "A"))
			line2alight(sep_line);
		if (ft_strcmp(sep_line, "C"))
			line2camera(sep_line);
		if (ft_strcmp(sep_line, "L"))
			line2light(sep_line);
		if (ft_strcmp(sep_line, "sp"))
			line2sphere(sep_line);
		if (ft_strcmp(sep_line, "pl"))
			line2plane(sep_line);
		if (ft_strcmp(sep_line, "cy"))
			line2cylinder(sep_line);
	}
}
