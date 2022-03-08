/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:49:52 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 18:18:02 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	get_decimals(char *str)
{
	double	result;
	int		ctr;

	ctr = 1;
	result = 0.0;
	while (ft_isdigit(str[ctr]))
	{
		result = result + (float)(str[ctr] - '0') / powf(10.0, (float)ctr);
		ctr++;
	}
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	int		ctr;
	int		neg;

	result = 0.0;
	ctr = 0;
	neg = 1;
	if (str[ctr] == '-' || str[ctr] == '+')
	{
		neg = -1;
		ctr++;
	}
	while (ft_isdigit(str[ctr]))
	{
		result = result * 10 + (str[ctr] - '0');
		ctr++;
	}
	if (str[ctr] == '.')
	{
		result = result + get_decimals(&(str[ctr]));
	}
	return (result);
}
