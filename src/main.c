#include "minirt.h"

int	main(int argc, char **argv)
{
	t_itemlist	**items;
	t_coords	**v_matrix;

	if (argc != 2)
		return (1);
	items = get_items(argv[1]);
	v_matrix =  set_cam_vectors(set_corners(get_item_by_type(items, CAMERA)));
}
