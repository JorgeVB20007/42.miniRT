/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/18 19:38:20 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H
# include "dtos.h"

t_colors	**set_color_matrix(t_itemlist *items, t_coords **v_matrix);

int	check4collisions(t_coords vector, t_itemlist *items);

#endif
