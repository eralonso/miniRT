/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:38:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/02 17:28:30 by eralonso         ###   ########.fr       */
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

int		ft_matrixlen(char **matrix);
int		ft_isdouble(char *str, double *ret);
int		ft_isunsignedchar(char *str, unsigned char *ret);
int		ft_isrgb(char *str, t_rgba *ret);
double	ft_strtod(const char *str);
int		ft_isvector(char *str, t_vector ret);
int		ft_validate_double(char *str);

#endif