/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/20 23:07:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
//? VERTICAL resolution of the image. Horizontal resolution is 16/9 times greater.
# define RESOLUTION 1080
//* This should be temporary, as "RESOLUTION * (16/9)" doesnt work sometimes.
# define HORIZ_RESOLUTION 1920

//?	All the types of object specified in the subject.
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
