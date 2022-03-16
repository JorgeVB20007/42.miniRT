#include "minirt.h"

static t_colors	**doing_calculations(char **argv)
{
	t_itemlist	*items;
	t_itemlist	*items2;
	t_coords	**v_matrix;
	t_colors	**c_matrix;

	items = NULL;
	items2 = NULL;
	get_items(&items, argv[1]);
	v_matrix = set_cam_vectors(set_corners(get_item_by_type(&items, CAMERA)));
	c_matrix = set_color_matrix(items, v_matrix);

	lst_rt_print(items);
	get_items_by_type(&items2, items, SPHERE);
	lst_rt_print(items2);
	lst_rt_free(&items);
	lst_rt_free(&items2);
	return (c_matrix);
}

int	main(int argc, char **argv)
{
	t_colors	**c_matrix;

	if (argc != 2)
		return (1);
	c_matrix = doing_calculations(argv);
}
