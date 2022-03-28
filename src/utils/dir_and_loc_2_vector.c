/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_and_loc_2_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:23:47 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/28 19:51:41 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vectors dir_and_loc_2_vector(t_coords loc, t_coords dir)
{
	t_vectors result;

	result.loc = loc;
	result.dir = turn2unit(dir);
	return (result);
}

t_vectors	dir_and_cam_2_vector(t_item cam, t_coords dir)
{
	t_vectors result;

	result.dir = turn2unit(dir);
	result.loc = cam.loc;
	return (result);
}
