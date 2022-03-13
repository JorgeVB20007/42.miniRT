/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 20:59:16 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
//? Resolución VERTICAL de la imagen. La resolución horizontal es 16/9 veces más grande.
# define RESOLUTION 1080

//?	Todos los tipos de objetos que nos pueden pasar.
enum e_type_of_object
{
	ALIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};
#endif
