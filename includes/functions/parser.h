/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:16 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "dtos.h"

t_item			*line2alight(char **line);
t_item			*line2camera(char **line);
t_item			*line2light(char **line);
t_item			*line2sphere(char **line);
t_item			*line2plane(char **line);
t_item			*line2cylinder(char **line);

t_itemlist		**get_items(char *argv);
#endif
