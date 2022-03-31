/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/31 21:18:23 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H
# include "dtos.h"

int				**set_color_matrix(t_itemlist *items, t_coords **v_matrix);
void			free_array_colors(int ***list);
int				check4collisions(t_coords vector, t_itemlist *items);
t_figure_point	get_closest_fig_point(t_vectors ray, t_itemlist *items);
int				touches_sphere(t_vectors ray, t_item sphere);
int				touches_cylinder(t_vectors ray, t_item cylinder);
int				touches_plane(t_vectors ray, t_item plane);
t_colors		alight2fig(t_colors fig_color, t_colors alight_color, \
float alight_brightness);
void			calculate_reflection(t_figure_point *point, t_itemlist *items,\
t_item item_alight);
t_colors		color_sum(t_colors color1, float bright1, t_colors color2, float \
bright2);
int			find_light_interruption(t_item light, t_coords target, t_itemlist *items);

#endif
