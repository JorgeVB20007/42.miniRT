#include "minirt.h"

int	main(int argc, char **argv)
{
	t_itemlist	**items;

	if (argc != 2)
		return (1);
	items = get_items(argv[1]);
}
