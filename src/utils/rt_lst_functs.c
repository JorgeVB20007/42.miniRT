/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lst_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:16 by jvacaris         ###   ########.fr       */
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
