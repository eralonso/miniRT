/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:38:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/21 13:02:07 by omoreno-         ###   ########.fr       */
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
# define ISFOV_NIR "FOV is not in range: [0 - 180]\n"
# define ISTHETA_NIR "Theta is not in range: [0 - 90]\n"
# define ISLIGHT_RATIO_NIR "Light ratio is not in range: [0.0 - 1.0]\n"

int				ft_matrixlen(char **matrix);
int				ft_isdouble(char *str, double *ret);
int				ft_isunsignedchar(char *str, unsigned char *ret);
int				ft_isrgb(char *str, t_rgba *ret);
double			ft_strtod(const char *str);
int				ft_isvector(char *str, t_vector vect);
int				ft_validate_double(char *str);
int				ft_isorientation(char *str, t_vector orient);
int				ft_isfov(char *str, double *fov);
int				ft_islight_ratio(char *str, double *light);
unsigned char	check_addition_rgba(unsigned char color1, unsigned char color2);
t_rgba			ft_rgba_addition(t_rgba color1, t_rgba color2);
t_rgba			ft_col_light(t_rgba color_source, double ratio, \
							t_rgba surf_col);
t_rgba			get_background_color(void);

#endif