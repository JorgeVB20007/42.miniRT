/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:37:23 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/15 20:49:20 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define NON_ZERO_NUMBERS "123456789"

/**
 * * Validates string contents within range
* @param s_nbr  string to process
*/
static int	valid_range(const char *s_nbr, long min, long max)
{
	double	d;
	size_t	i;

	d = 0;
	i = 0;
	if (s_nbr[0] == '-' && ft_isdigit(s_nbr[1]))
	{
		d = (s_nbr[1] - '0') * -1;
		i += 2;
	}
	else if (s_nbr[0] == '+')
		i++;
	while (s_nbr[i] != '\0' && ft_isdigit(s_nbr[i]) && (d < max || d > min))
		d = d * 10 + s_nbr[i++] - '0';
	if (s_nbr[i] == '.')
		while (!ft_strchr(NON_ZERO_NUMBERS, s_nbr[i]))
			i++;
	d += (ft_isdigit(s_nbr[i]) && s_nbr[0] != '-');
	d -= (ft_isdigit(s_nbr[i]) && s_nbr[0] == '-');
	if (d > max || d < min)
		return (FALSE);
	return (TRUE);
}

/**
 * * Validates allowed characters(FLOAT)
 * * Acept just one char as sign
* @param s_nbr  string to process
*/
static int	check_nbr(char *const_s_nbr)
{
	char	*s_nbr;
	int		dot_used;

	dot_used = FALSE;
	s_nbr = (char *)const_s_nbr;
	if (!(ft_isdigit(s_nbr[0])) && \
	!(ft_isdigit(s_nbr[1]) && (s_nbr[0] == '-' || s_nbr[0] == '+')))
		return (0);
	if (*s_nbr == '-' || *s_nbr == '+')
		s_nbr++;
	while (*s_nbr != '\0' && !ft_isspace(*s_nbr))
	{
		if (!ft_isdigit(*s_nbr) && (*s_nbr != '.' && !dot_used))
			return (FALSE);
		if (*s_nbr == '.')
			dot_used = TRUE;
		s_nbr++;
	}
	return (TRUE);
}

int	try_set_atof(float *out, char *nbr, long min, long max)
{
	if (!check_nbr(nbr))
		return (1);
	if (!valid_range(nbr, min, max))
		return (1);
	*out = ft_atof(nbr);
	return (0);
}

int	try_set_color(t_colors *out, const char *rgb)
{
	char		**split;
	int			error;

	split = ft_split(rgb, ',');
	error = (split[3] != NULL);
	if (!error)
		error += try_set_atof(&out->r, split[0], 0.0, 255.0);
	if (!error)
		error += try_set_atof(&out->g, split[1], 0.0, 255.0);
	if (!error)
		error += try_set_atof(&out->b, split[2], 0.0, 255.0);
	megafree(&split);
	return (error != FALSE);
}

int	try_set_coords(t_coords *out, const char *coords, long min, long max)
{
	char		**split;
	int			error;

	split = ft_split(coords, ',');
	error = (split[3] != NULL);
	if (!error)
		error += try_set_atof(&out->x, split[0], min, max);
	if (!error)
		error += try_set_atof(&out->y, split[1], min, max);
	if (!error)
		error += try_set_atof(&out->z, split[2], min, max);
	megafree(&split);
	return (error != FALSE);
}
