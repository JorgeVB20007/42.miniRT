/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/28 22:21:45 by emadriga         ###   ########.fr       */
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


#endif
