#include "minirt.h"

static void	doing_calculations(char **argv)
{
	t_item		*items;
	t_item		*items2;
	t_coords	**v_matrix;
	int			**c_matrix;
	t_item		cam;


	items = NULL;
	items2 = NULL;
	get_items(&items, argv[1]);
	if (items != NULL)
	{
		cam = get_item_by_type(&items, CAMERA);
		v_matrix = set_cam_vectors(set_corners(cam));
		c_matrix = set_color_matrix(items, v_matrix, cam);
		render_image_on_mlx(c_matrix);
		free_array_coords(&v_matrix);
		free_array_colors(&c_matrix);
		// lst_rt_print(items);
		// get_items_by_type(&items2, items, SPHERE);
		// lst_rt_print(items2);
		lst_rt_free(&items);
		lst_rt_free(&items2);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	doing_calculations(argv);
}
