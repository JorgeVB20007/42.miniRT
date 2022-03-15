#include "minirt.h"

int	main(int argc, char **argv)
{
	t_itemlist	*items;
	t_itemlist	*items2;

	items = NULL;
	items2 = NULL;
	if (argc != 2)
		return (1);
	get_items(&items, argv[1]);
	lst_rt_print(items);
	get_items_by_type(&items2, items, SPHERE);
	lst_rt_print(items2);
	lst_rt_free(&items);
	lst_rt_free(&items2);
}
