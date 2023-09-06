/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/06 15:41:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

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
	color = (t_rgba){0, 0, 0, 0};
	data.sr = gen_shadow_ray(data.light, data.best, &data.dis);
	data.hit = get_best_intersect(data.minirt, data.sr, data.best->pos);
	if (data.hit.distance < data.dis)
		return (ambient);
	object_color = ft_col_light(data.light->color, 1, data.best->color);
	diffuse = calc_diffuse_light(&data, object_color, 0.6);
	specular = calc_specular_light(&data, 0.6);
	diffuse = ft_rgba_scale(diffuse, \
				(1 - data.best->tan_plane.material->reflec_ratio));
	specular = ft_rgba_scale(specular, \
				(1 - data.best->tan_plane.material->reflec_ratio));
	color = ft_rgba_addition(diffuse, specular);
	color = ft_rgba_addition(color, ambient);
	return (color);
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
	t_rgba				best_color;

	if (depth == 0)
		return (minirt->background_color);
	best = get_best_intersect(minirt, ray, -1);
	color = best.color;
	best_color = color;
	if (best.distance != INFINITY)
		color = get_sum_lights(&best, ray, minirt, depth);
	return (color);
}
