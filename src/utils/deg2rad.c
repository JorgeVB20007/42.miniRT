/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg2rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:31:45 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/15 20:02:42 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * * Turns degrees into radians.
*/
float	deg2rad(float deg)
{
	return(deg * (M_PI / 180.0));
}

/**
 * * Turns radians into degrees.
*/
float	rad2deg(float rad)
{
	return(rad * (180.0 / M_PI));
}
