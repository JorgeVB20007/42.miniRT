/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/28 17:45:14 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define LIT_TYPES "ALIGHT ☀️,CAMERA 🎥,LIGHT 💡,SPHERE ⚽️,PLANE ⬜️,CYLINDER 🥫"
#define LIT_TYPE "\n\n\033[1mtype:\033[0m %s\n"
#define LIT_BRIGHT "\033[1mbright:\033[0m %f\t"
#define LIT_DIAMETER "\033[1mdiameter:\033[0m %f\t"
#define LIT_FOV "\033[1mfov:\033[0m %f\t"
#define LIT_HEIGHT "\033[1mheight:\033[0m %f\t"
#define LIT_COLOR "\n\033[1mcolor:\n\t\033[1;31mR \033[0;31m%f\t\033[1;32mG\
 \033[0;32m%f\t\033[1;34mB \033[0;36m%f\033[0m"
#define LIT_POSITION "\n\033[1mposition:\033[0m\n\t\033[1mX\033[0m %f\t\033[1m\
Y\033[0m %f\t\033[1mZ\033[0m %f"
#define LIT_ORIENTATION "\n\033[1morientantion:\033[0m\n\t\033[1mX\033[0m \
%f\t\033[1mY\033[0m %f\t\033[1mZ\033[0m %f"


/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void	lst_rt_add_front(t_item **alst, t_item *new)
{
	if (!alst || !new)
		return ;
	new -> next = *alst;
	*alst = new;
}

/**
 * * Returns an item of list that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
t_item	get_item_by_type(t_item **item_list, int type)
{
	t_item		*item;
	t_item		returning;

	returning.type = -1;
	item = *item_list;
	while (item)
	{
		if (item->type == type)
		{
			returning = *item;
			return (returning);
		}
		item = item -> next;
	}
	return (returning);
}

static t_item	*copy_rt_content(t_item *content)
{
	t_item	*result;

	result = NULL;
	result = malloc(sizeof(t_item));
	result->brightness = content->brightness;
	result->color = content->color;
	result->diameter = content->diameter;
	result->fov = content->fov;
	result->height = content->height;
	result->loc = content->loc;
	result->orient = content->orient;
	result->type = content->type;
	return (result);
}

/**
 * * Filter list from type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
void	get_items_by_type(t_item **filtered_list, t_item *list, int type)
{
	t_item		*content;

	content = NULL;
	while (list != NULL)
	{
		if (list->type == type)
		{
			content = copy_rt_content(list);
			lst_rt_add_front(filtered_list, content);
		}
		list = list->next;
	}
}

void	get_object_items(t_item **filtered_list, t_item *list)
{
	t_item		*content;

	content = NULL;
	while (list != NULL)
	{
		if (list->type == SPHERE || list->type == PLANE \
		|| list->type == CYLINDER)
		{
			content = copy_rt_content(list);
			lst_rt_add_front(filtered_list, content);
		}
		list = list->next;
	}
}

/**
 * * Print list
 * @param list
*/
void	lst_rt_print(t_item *i)
{
	char	**type;

	type = ft_split(LIT_TYPES, ',');
	while (i != NULL)
	{
		printf(LIT_TYPE, type[i->type]);
		if (i->type == ALIGHT || i->type == LIGHT)
			printf(LIT_BRIGHT, i->brightness);
		if (i->type == CYLINDER || i->type == SPHERE)
			printf(LIT_DIAMETER, i->diameter);
		if (i->type == CAMERA)
			printf(LIT_FOV, i->fov);
		if (i->type == CYLINDER)
			printf(LIT_HEIGHT, i->height);
		if (i->type != CAMERA && i->type != LIGHT)	// Multidirectional lights can't have a color in the  mandatory part :(
			printf(LIT_COLOR, i->color.r, i->color.g, i->color.b);
		if (i->type != ALIGHT)
			printf(LIT_POSITION, i->loc.x, i->loc.y, i->loc.z);
		if (i->type != ALIGHT && i->type != SPHERE && i->type != LIGHT)
			printf(LIT_ORIENTATION, i->orient.x, i->orient.y, i->orient.z);
		printf("\n\n\033[0;33m ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \033[0m");	//Plz don't kill me
		i = i->next;
	}
	megafree(&type);
	printf("\n");
}

/**
 * * Free list
 * @param list	list
*/
void	lst_rt_free(t_item **list)
{
	t_item	*next;
	t_item	*item;

	next = *list;
	item = *list;
	while (next != NULL)
	{
		next = next->next;
		free(item);
		item = next;
	}
	*list = NULL;
	list = NULL;
}
