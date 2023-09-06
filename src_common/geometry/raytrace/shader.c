/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:29:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 15:50:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static t_rgba	ft_add_ambient(t_rgba acum, t_shader_data *data)
{
	t_rgba	ambient;

	ambient = ft_col_light(data->best->color, \
							(1 - data->best->tan_plane.material->reflec_ratio) \
								* data->ambient.ratio, \
							data->ambient.color);
	return (ft_rgba_addition(ambient, acum));
}

static t_rgba	ft_reflected_light(t_shader_data *data, int depth)
{
	t_rgba	ret;
	t_rgba	specular;
	t_rgba	diffuse;
	t_rgba	reflected_color;
	t_rgba	object_color;

	object_color = ft_col_light(data->light->color, \
		1, data->best->color);
	specular = ft_rgba_scale(data->light->color, \
				data->light->brightness * data->specular * 0.9);
	reflected_color = raytrace(data->minirt, \
						gen_reflect_ray(data->ray, data->best), depth - 1);
	reflected_color = ft_rgba_scale(reflected_color, \
		data->best->tan_plane.material->reflec_ratio);
	diffuse = ft_rgba_scale(object_color, \
				data->diffuse * data->light->brightness * 0.9);
	ret = ft_rgba_addition(reflected_color, diffuse);
	ret = ft_rgba_addition(specular, ret);
	ret = ft_add_ambient(ret, data);
	return (ret);
}

static t_rgba	ft_non_reflective_light(t_shader_data *data)
{
	t_rgba	ret;
	t_rgba	specular;
	t_rgba	diffuse;
	t_rgba	object_color;
	t_rgba	ambient;

	object_color = ft_col_light(data->light->color, \
		1, data->best->color);
	specular = ft_rgba_scale(data->light->color, \
							data->light->brightness * data->specular * 0.9);
	diffuse = ft_rgba_scale(object_color, \
				data->diffuse * data->light->brightness * 0.9);
	ambient = ft_col_light(data->best->color, \
					(1 - data->best->tan_plane.material->reflec_ratio) \
						* data->ambient.ratio, \
					data->ambient.color);
	ret = ft_rgba_addition(specular, diffuse);
	ret = ft_rgba_addition(ret, ambient);
	return (ret);
}

t_rgba	shader(t_shader_data data, int depth)
{
	data.sr = gen_shadow_ray(data.light, data.best, &data.dis);
	data.hit = get_best_intersect(data.minirt, data.sr, data.best->pos);
	if (data.hit.distance < data.dis)
		return ((t_rgba){0, 0, 0, 0});
	data.diffuse = -ft_dot_product(data.best->tan_plane.orientation, \
									data.sr.orientation);
	if (data.diffuse < 0)
		data.diffuse = 0;
	data.specular = -ft_dot_product(data.ray.orientation, \
		gen_reflect_ray(data.sr, data.best).orientation);
	if (data.specular < 0)
		data.specular = 0;
	if (data.best->tan_plane.material->n_sharpness >= 5)
		data.specular = pow(data.specular, \
						data.best->tan_plane.material->n_sharpness);
	else
		data.specular = pow(data.specular, 5);
	if (data.best->tan_plane.material->reflec_ratio > 0)
		return (ft_reflected_light(&data, depth));
	return (ft_non_reflective_light(&data));
}
