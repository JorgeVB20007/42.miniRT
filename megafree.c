#include "minirt.h"

/*
* This function recieves a list of strings (pointer to pointers) and frees
* everything, including the main pointer. The last string must be NULL.
*/
void	megafree(char ***list)
{
	int	a;

	a = 0;
	if (*list)
	{
		while ((*list)[a])
			free((*list)[a++]);
		free((*list)[a]);
		free(*list);
	}
}
