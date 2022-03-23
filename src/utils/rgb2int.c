/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:48 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/23 20:01:52 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Gets a color in its rgb form (struct t_colors) and returns the int value 
*	of such color.
*/
int	rgb2int(t_colors rgb)
{
	int	result;

	result = rgb.b + rgb.g * 256 + rgb.r * 256 * 256;
	return (result);
}
