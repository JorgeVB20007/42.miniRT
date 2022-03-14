/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/14 20:04:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "dtos.h"

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void		lst_rt_add_front(t_itemlist **alst, t_itemlist *new_node);

/**
 * * Returns malloced node
*/
t_itemlist	*lst_rt_new(t_item *content);

//*	Gets degrees, returns radians.
float		deg2rad(float deg);

//*	Gets radians, returns degrees.
float		deg2rad(float deg);

//*	Gets vector, returns module.
float		getmodule(t_coords vector);

#endif
