/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:52:49 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/08 17:51:38 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
char	*gnl_ft_calloc(int a);
int		eolcheck(char *str);
char	*gnl_ft_join(char *orig, char *add);

#endif
