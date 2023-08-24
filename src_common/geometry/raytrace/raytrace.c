/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/24 11:58:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

typedef struct s_shader_data
{
	t_line				sr;
	t_intersect_data	hit;
	double				diffuse;
	double				specular;
	double				dis;
	t_light				*light;
	t_intersect_data	*best;
	t_minirt_data		*minirt;
	t_line				ray;
}	t_shader_data;

static t_rgba	ft_reflected_light(t_shader_data *data, int depth)
{
	t_rgba	ret;
	t_rgba	specular;
	t_rgba	reflected_color;
	t_rgba	object_color;

	specular = ft_rgba_scale(data->light->color, \
				data->light->brightness * data->specular);
	reflected_color = raytrace(data->minirt, \
						gen_reflect_ray(data->ray, data->best), depth - 1);
	reflected_color = ft_col_light(data->light->color, \
				data->diffuse * data->light->brightness \
					* data->best->tan_plane.reflec_ratio, \
				reflected_color);
	object_color = ft_col_light(data->light->color, \
				data->diffuse * data->light->brightness * \
				(1 - data->best->tan_plane.reflec_ratio), \
				data->best->tan_plane.color);
	ret = ft_rgba_addition(reflected_color, object_color);
	ret = ft_rgba_addition(specular, ret);
	ret = ft_rgba_scale(ret, 0.8);
	return (ret);
}

static t_rgba	ft_non_reflective_light(t_shader_data *data)
{
	t_rgba	ret;
	t_rgba	specular;
	t_rgba	diffuse;

	specular = ft_rgba_scale(data->light->color, \
							data->light->brightness * data->specular);
	diffuse = ft_col_light(data->light->color, \
						data->diffuse * data->light->brightness, \
						data->best->tan_plane.color);
	ret = ft_rgba_scale(ft_rgba_addition(specular, diffuse), 0.8);
	return (ret);
}

static t_rgba	shader(t_shader_data data, int depth)
{
	t_vector			trash;

	data.sr = gen_shadow_ray(data.light, data.best, &data.dis);
	data.diffuse = -ft_dot_product(data.best->tan_plane.orientation, \
									data.sr.orientation);
	if (data.diffuse < 0)
		data.diffuse = 0;
	data.specular = ft_dot_product(\
		ft_scale_vector(trash, data.ray.orientation, -1), \
		gen_reflect_ray(data.sr, data.best).orientation);
	if (data.specular < 0)
		data.specular = 0;
	data.specular = pow(data.specular, 5);
	data.diffuse *= (1 - data.specular);
	data.hit = get_best_intersect(data.minirt->figures, data.sr, \
									data.minirt->intersect, data.best->pos);
	if (data.hit.distance < data.dis)
		return ((t_rgba){0, 0, 0, 0});
	if (data.best->tan_plane.reflec_ratio)
		return (ft_reflected_light(&data, depth));
	return (ft_non_reflective_light(&data));
}

static t_rgba	get_sum_lights(t_intersect_data *best, \
			t_line ray, t_minirt_data *minirt, int depth)
{
	t_rgba			color;
	t_list			*lights;
	t_shader_data	data;

	color = (t_rgba){0, 0, 0, 0};
	lights = minirt->lights;
	data.best = best; 
	data.ray = ray;
	data.minirt = minirt;
	while (lights)
	{
		data.light = (t_light *)lights->content;
		color = ft_rgba_addition(color, shader(data, depth));
		lights = lights->next;
	}
	return (color);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray, int depth)
{
	t_intersect_data	best;
	t_rgba				color;

	if (depth == 0)
		return (get_background_color());
	best = get_best_intersect(minirt->figures, ray, minirt->intersect, -1);
	color = best.tan_plane.color;
	if (best.distance != INFINITY)
		color = get_sum_lights(&best, ray, minirt, depth);
	best.tan_plane.color = ft_rgba_addition(color, ft_col_light(\
	minirt->ambient.color, minirt->ambient.ratio * 0.4, best.tan_plane.color));
	return (best.tan_plane.color);
}
