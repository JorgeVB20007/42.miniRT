/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 17:08:26 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
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
 * * Returns malloced node
*/
void	lst_rt_add_front(t_itemlist **alst, t_itemlist *new)
{
	if (!alst || !new)
		return ;
	new -> next = *alst;
	*alst = new;
}

/**
 * * Returns an item of t_itemlist that has the type given.
 * @param item	list of items
 * @param type	type of item to get
*/
t_item	get_item_by_type(t_itemlist **item, int type)
{
	t_itemlist	*iter;
	t_item		returning;

	returning.type = -1;
	iter = *item;
	while (iter)
	{
		if (iter->content->type == type)
		{
			returning = *iter->content;
			return (returning);
		}
		iter = iter -> next;
	}
	return (returning);
}
