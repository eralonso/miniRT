/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:38:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 10:25:07 by omoreno-         ###   ########.fr       */
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
# define ISVECTOR2D_SIZE "Invalid number of vector2d components\n"
# define ISSTRING_DUPERR "Failed to duplicate string"
# define ISMATTYPE_INVALID "Material type is invalid"
# define ISDOUBLE_MISS_STR "Miss string argument\n"
# define ISDOUBLE_NAN "Is not a double\n"
# define ISDOUBLE_NIR "Is not in range\n"
# define ISORIENTATION_MOD_TOO_LOW "Orientation module too low\n"
# define ISORIENTATION_COMPS_OOR "Orientation component out of range\n"
# define ISFOV_NIR "FOV is not in range: [0 - 180]\n"
# define ISTHETA_NIR "Theta is not in range: [0 - 90]\n"
# define ISANGLE_NIR "Angle is not in range: [-180 - 180]\n"
# define ISPOSITIVEDOUBLE_NIR "Value is not positive\n"
# define ISRATIO_NIR "Ratio is not in range: [0.0 - 1.0]\n"
# define ISNOTEXISTINGFILE "Is not an existing file\n"
# define ISNEF_STR_DUPERR "Failed to duplicate string when checking filename\n"

int				ft_matrixlen(char **matrix);
int				ft_free_n_log_error(void *to_free, char *msg);
int				ft_isdouble(char *str, double *ret);
int				ft_isunsignedchar(char *str, unsigned char *ret);
int				ft_isrgb(char *str, t_rgba *ret);
double			ft_strtod(const char *str);
int				ft_isvector(char *str, t_vector vect);
int				ft_isvector2d(char *str, t_vector2d vect);
int				ft_validate_double(char *str);
int				ft_isorientation(char *str, t_vector orient);
int				ft_isfov(char *str, double *fov);
int				ft_istheta(char *str, double *theta);
int				ft_isangle(char *str, double *alpha);
int				ft_ispositivedouble(char *str, double *value);
int				ft_isratio(char *str, double *light);
int				ft_ismattype(char *str, t_material_type *ret);
int				ft_isname(char *str, char **ret);
int				ft_isexistingfile(char *str, char **filename);
unsigned char	check_addition_rgba(unsigned char color1, unsigned char color2);
t_rgba			ft_rgba_addition(t_rgba color1, t_rgba color2);
t_rgba			ft_rgba_scale(t_rgba color, double scale);
t_rgba			ft_col_light(t_rgba color_source, double ratio, \
							t_rgba surf_col);

#endif