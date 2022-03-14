/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmodule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:57:34 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/14 20:06:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	getmodule(t_coords vector)
{
	float	result;

	result = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	return (result);
}
