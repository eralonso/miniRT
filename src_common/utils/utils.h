/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:38:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/04 13:22:25 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../common.h"

# define ISRGB_MISS_STR "Miss string argument\n"
# define ISRGB_SIZE "Invalid number of rgb components\n"
# define ISUNSIGNEDCHAR_MISS_STR "Miss string argument\n"
# define ISUNSIGNEDCHAR_NAN "Is not a number\n"
# define ISUNSIGNEDCHAR_NIR "Is not in range\n"
# define ISVECTOR_MISS_STR "Miss string argument\n"
# define ISVECTOR_SIZE "Invalid number of vector components\n"
# define ISDOUBLE_MISS_STR "Miss string argument\n"
# define ISDOUBLE_NAN "Is not a double\n"
# define ISDOUBLE_NIR "Is not in range\n"
# define ISORIENTATION_MOD_TOO_LOW "Orientation module too low\n"
# define ISORIENTATION_COMPS_OOR "Orientation component out of range\n"

int		ft_matrixlen(char **matrix);
int		ft_isdouble(char *str, double *ret);
int		ft_isunsignedchar(char *str, unsigned char *ret);
int		ft_isrgb(char *str, t_rgba *ret);
double	ft_strtod(const char *str);
int		ft_isvector(char *str, t_vector vect);
int		ft_validate_double(char *str);
int		ft_isorientation(char *str, t_vector orient);


#endif