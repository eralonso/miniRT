/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:37:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 15:39:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

t_rgba	calc_specular_light(t_shader_data *data, \
									double specular_idx)
{
	t_rgba	specular;
	double	exponent;
	double	ray_dot_reflect;

	exponent = 5;
	ray_dot_reflect = -ft_dot_product(data->minirt->eye_ray.orientation, \
		gen_reflect_ray(data->sr, data->best).orientation);
	if (ray_dot_reflect <= 0)
		return ((t_rgba){0, 0, 0, 0});
	if (data->best->tan_plane.material->n_sharpness > exponent)
		exponent = data->best->tan_plane.material->n_sharpness;
	ray_dot_reflect = pow(ray_dot_reflect, exponent);
	specular = ft_rgba_scale(data->light->color, ray_dot_reflect * \
						data->light->brightness * specular_idx);
	return (specular);
}
