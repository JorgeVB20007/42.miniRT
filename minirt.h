/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:57:46 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 21:03:36 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

typedef struct s_colors
{
	float	r;
	float	g;
	float	b;
}	t_colors;

typedef struct s_item
{
	int			type;
	t_coords	loc;		//  Doesn't apply to ALIGHT.
	t_colors	color;		//  Doesn't apply to CAMERA and LIGHT.
	t_coords	orient;		//  Doesn't apply to ALIGHT, LIGHT and SPHERE.
	float		brightness;	//* Applies only to ALIGHT and LIGHT.
	float		diameter;	//* Applies only to SPHERE and CYLINDER.
	float		height;		//* Applies only to CYLINDER;
	float		fov;		//* Applies only to CAMERA.
}	t_item;

typedef struct s_itemlist
{
	t_item				*content;
	struct s_itemlist	*next;
}	t_itemlist;

enum e_type_of_object
{
	ALIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};

t_item		*line2alight(char **line);
t_item		*line2camera(char **line);
t_item		*line2light(char **line);
t_item		*line2sphere(char **line);
t_item		*line2plane(char **line);
t_item		*line2cylinder(char **line);

double		ft_atof(char *str);

t_itemlist		**get_items(char *argv);

int			ft_strcmp(const char *s1, const char *s2);

void		megafree(char ***list);

void		ft_rt_lstadd_front(t_itemlist **alst, t_itemlist *new);
t_itemlist	*ft_rt_lstnew(t_item *content);

#endif