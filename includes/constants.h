/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/18 21:53:17 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
//? VERTICAL resolution of the image. Horizontal resolution is 16/9 times greater.
// # define VERT_RESOLUTION 1080
//* This should be temporary, as "RESOLUTION * (16/9)" doesnt work sometimes.
// # define HORIZ_RESOLUTION 1920
//* We can change things here for reference when doing screenshots.
# define MLX_TITLE "MiniRT Test | Cylinders"
# define NONE 0
# define LIT_ERROR "Error"

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

enum e_bool
{
	FALSE,
	TRUE
};
#endif
