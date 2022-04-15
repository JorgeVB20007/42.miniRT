/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/15 20:18:57 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "dtos.h"

t_item		*line2alight(char **line);
t_item		*line2camera(char **line);
t_item		*line2light(char **line);
t_item		*line2sphere(char **line);
t_item		*line2plane(char **line);
t_item		*line2cylinder(char **line);

void		get_items(t_item **list, char *argv);
t_corners	set_corners(t_item item);
t_coords	**set_cam_vectors(t_corners corn);
void		free_array_coords(t_coords ***list);
int			try_set_atof(float *out, char *nbr, long min, long max);
int			try_set_color(t_colors *out, const char *rgb);
int			try_set_coords(t_coords *out, const char *coords, long min, \
				long max);

#endif
