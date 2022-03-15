/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 23:09:42 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define LIT_TYPES "ALIGHT,CAMERA,LIGHT,SPHERE,PLANE,CYLINDER"
#define LIT_TYPE "\n\ntype: %s\n"
#define LIT_BRIGHT "bright: %f\t"
#define LIT_DIAMETER "diameter: %f\t"
#define LIT_FOV "fov: %f\t"
#define LIT_HEIGHT "height: %f\t"
#define LIT_COLOR "\ncolor:\n\tR %f\tG %f\tB %f"
#define LIT_POSITION "\nposition:\n\tX %f\tY %f\tZ %f"
#define LIT_ORIENTATION "\norientantion:\n\tX %f\tY %f\tZ %f"

/**
 * * Returns malloced node
*/
t_itemlist	*lst_rt_new(t_item *content)
{
	t_itemlist	*result;

	result = malloc(sizeof(t_item));
	if (result == 0)
		return (NULL);
	result -> content = content;
	result -> next = NULL;
	return (result);
}

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void	lst_rt_add_front(t_itemlist **alst, t_itemlist *new)
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
t_item	get_item_by_type(t_itemlist **item_list, int type)
{
	t_itemlist	*item;
	t_item		returning;

	returning.type = -1;
	item = *item_list;
	while (item)
	{
		if (item->content->type == type)
		{
			returning = *item->content;
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
	result->color = get_color(content->color);
	result->diameter = content->diameter;
	result->fov = content->fov;
	result->height = content->height;
	result->loc = get_coords(content->loc);
	result->orient = get_coords(content->orient);
	result->type = content->type;
	return (result);
}

/**
 * * Filter list from type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
void	get_items_by_type(t_itemlist **filtered_list, t_itemlist *list, int type)
{
	t_item		*content;

	content = NULL;
	while (list != NULL)
	{
		if (list->content->type == type)
		{
			content = copy_rt_content(list->content);
			lst_rt_add_front(filtered_list, lst_rt_new(content));
		}
		list = list->next;
	}
}


/**
 * * Print list
 * @param list
*/
void	lst_rt_print(t_itemlist *list)
{
	t_item	*c;
	char	**type;

	type = ft_split(LIT_TYPES, ',');
	while (list != NULL)
	{
		c = list->content;
		printf(LIT_TYPE, type[c->type]);
		if (c->type == ALIGHT || c->type == LIGHT)
			printf(LIT_BRIGHT, c->brightness);
		if (c->type == CYLINDER || c->type == SPHERE)
			printf(LIT_DIAMETER, c->diameter);
		if (c->type == CAMERA)
			printf(LIT_FOV, c->fov);
		if (c->type == CYLINDER)
			printf(LIT_HEIGHT, c->height);
		if (c->type != CAMERA)
			printf(LIT_COLOR, c->color.r, c->color.g, c->color.b);
		if (c->type != ALIGHT)
			printf(LIT_POSITION, c->loc.x, c->loc.y, c->loc.z);
		if (c->type != ALIGHT && c->type != CAMERA && c->type != CAMERA)
			printf(LIT_ORIENTATION, c->orient.x, c->orient.y, c->orient.z);
		list = list->next;
	}
	megafree(&type);
}

/**
 * * Free list
 * @param list	list
*/
void	lst_rt_free(t_itemlist **list)
{
	t_itemlist	*next;
	t_itemlist	*item;

	next = *list;
	item = *list;
	while (next != NULL)
	{
		next = next->next;
		if (item->content != NULL)
			free(item->content);
		free(item);
		item = next;
	}
	*list = NULL;
	list = NULL;
}
