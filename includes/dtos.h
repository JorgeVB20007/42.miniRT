/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtos.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:16 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTOS_H
# define DTOS_H

//?	Para guardar coordenadas en x,y,z.
typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

//?	Para guardar vectores con su coordenada (loc) y su dirección (dir).
typedef struct s_vectors
{
	t_coords	loc;
	t_coords	dir;
}	t_vectors;

//?	Para guardar colores en r,g,b.
typedef struct s_colors
{
	float	r;
	float	g;
	float	b;
}	t_colors;

/*
?	Para guardar cada ítem que nos pasen:
*	type:		el tipo de objeto (ver e_type_of_object).
*	loc:		la posición del objeto en xyz.
*	color:		el color del objeto en rgb.
*	orient:		el vector normal del objeto.
*	brightness:	el brillo de una luz/luz ambiental.
*	diameter:	el diámetro del objeto.
*	height:		la altura del cilindro.
*	fov:		el ángulo de visión horizontal de la cámara.
*/
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

//?	Lista enlazada donde content apunta a una estructura t_item.
typedef struct s_itemlist
{
	t_item				*content;
	struct s_itemlist	*next;
}	t_itemlist;
#endif
