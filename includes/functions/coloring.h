/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/25 20:35:58 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H
# include "dtos.h"

int				**set_color_matrix(t_itemlist *items, t_coords **v_matrix);
int				check4collisions(t_coords vector, t_itemlist *items);
t_figure_point	get_closest_fig_point(t_vectors ray, t_itemlist *items);
int				touches_sphere(t_vectors ray, t_item sphere);
int				touches_cylinder(t_vectors ray, t_item cylinder);
int				touches_plane(t_vectors ray, t_item plane);
t_colors		alight2fig(t_colors fig_color, t_colors alight_color, \
float alight_brightness);

#endif
