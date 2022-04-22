/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:33:12 by emadriga          #+#    #+#             */
/*   Updated: 2022/04/22 21:04:31 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

# define RESOLUTION 2

# if RESOLUTION==0					//	WVGA		16/9
#  define HORIZ_RESOLUTION 850
#  define VERT_RESOLUTION 480
# elif RESOLUTION==1				//	HD			16/9
#  define HORIZ_RESOLUTION 1280
#  define VERT_RESOLUTION 720
# elif RESOLUTION==2				//	FULL_HD		16/9
#  define HORIZ_RESOLUTION 1920
#  define VERT_RESOLUTION 1080
# elif RESOLUTION==3				//	2K			17/9
#  define HORIZ_RESOLUTION 2048
#  define VERT_RESOLUTION 1080
# elif RESOLUTION==4				//	QHD			16/9
#  define HORIZ_RESOLUTION 2560
#  define VERT_RESOLUTION 1440
# elif RESOLUTION==5				//	4K UHDV		16/9
#  define HORIZ_RESOLUTION 3840
#  define VERT_RESOLUTION 2160
# elif RESOLUTION==6				//	4K CINEMA	17/9
#  define HORIZ_RESOLUTION 4096
#  define VERT_RESOLUTION 2160
# endif

#endif
