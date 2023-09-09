/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/09 11:27:13 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static int	is_in_shadow(t_shader_data *data)
{
	data->sr = gen_shadow_ray(data->light, data->best, &data->dis);
	data->hit = get_best_intersect(data->minirt, data->sr, data->best->pos);
	if (data->hit.distance < data->dis)
		return (1);
	return (0);
}

t_rgba	object_light(t_shader_data data)
{
	t_rgba	ambient;
	t_rgba	object_color;
	t_rgba	color;
	t_rgba	diffuse;
	t_rgba	specular;

	ambient = ft_col_light(data.ambient.color, data.ambient.ratio, \
							data.best->color);
	ambient = ft_rgba_scale(ambient, \
				(1 - data.best->tan_plane.material->reflec_ratio));
	if (is_in_shadow(&data) || \
		data.best->tan_plane.material->reflec_ratio >= 1.0)
		return (ambient);
	object_color = ft_col_light(data.light->color, 1, data.best->color);
	diffuse = calc_diffuse_light(&data, object_color, \
								data.best->tan_plane.material->diffuse_ratio);
	specular = calc_specular_light(&data, \
								data.best->tan_plane.material->specular_ratio);
	color = ft_rgba_addition(diffuse, specular);
	return (ft_rgba_addition(color, ambient));
}

t_rgba	object_reflect(t_shader_data *data, int depth)
{
	t_rgba				reflected;
	double				reflection_index;

	reflection_index = data->best->tan_plane.material->reflec_ratio;
	if (depth == 1 || reflection_index == 0)
		return ((t_rgba){0, 0, 0, 0});
	reflected = raytrace(data->minirt, \
						gen_reflect_ray(data->ray, data->best), depth - 1);
	reflected = ft_rgba_scale(reflected, reflection_index);
	return (reflected);
}

t_rgba	get_sum_lights(t_intersect_data *best, \
			t_line ray, t_minirt_data *minirt, int depth)
{
	t_rgba			color;
	t_list			*lights;
	t_shader_data	data;

	color = (t_rgba){0, 0, 0, 0};
	lights = minirt->lights;
	data.best = best;
	data.ray = ray;
	data.ambient = minirt->ambient;
	data.minirt = minirt;
	while (lights)
	{
		data.light = (t_light *)lights->content;
		color = ft_rgba_addition(color, object_light(data));
		color = ft_rgba_addition(color, object_reflect(&data, depth));
		lights = lights->next;
	}
	return (color);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray, int depth)
{
	t_intersect_data	best;
	t_rgba				color;

	if (depth == 0)
		return (minirt->background_color);
	best = get_best_intersect(minirt, ray, -1);
	color = best.color;
	if (best.distance != INFINITY)
		color = get_sum_lights(&best, ray, minirt, depth);
	return (color);
}
