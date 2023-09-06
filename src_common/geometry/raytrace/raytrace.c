/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/06 14:56:19 by eralonso         ###   ########.fr       */
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
	t_ambient			ambient;
}	t_shader_data;

static t_rgba	ft_reflected_light(t_shader_data *data, int depth)
{
	t_rgba	ret;
	t_rgba	specular;
	t_rgba	diffuse;
	t_rgba	reflected_color;
	t_rgba	object_color;
	t_rgba	ambient;

	object_color = ft_col_light(data->light->color, \
		1, data->best->color);
	specular = ft_rgba_scale(data->light->color, \
				data->light->brightness * data->specular * 0.9);
	reflected_color = raytrace(data->minirt, \
						gen_reflect_ray(data->ray, data->best), depth - 1);
	reflected_color = ft_rgba_scale(reflected_color, \
		data->best->tan_plane.material->reflec_ratio);
	// reflected_color = ft_col_light(data->light->color, \
	// 			data->light->brightness \
	// 				* data->best->tan_plane.material->reflec_ratio, \
	// 			reflected_color);
	diffuse = ft_rgba_scale(object_color, \
				data->diffuse * data->light->brightness * 0.9);
	ambient = ft_col_light(data->best->color, (1 - data->best->tan_plane.material->reflec_ratio) * data->ambient.ratio, \
							data->ambient.color);
	// object_color = ft_col_light(data->light->color, \
	// 			data->diffuse * data->light->brightness * \
	// 			(1 - data->best->tan_plane.material->reflec_ratio), \
	// 			data->best->color);
	ret = ft_rgba_addition(reflected_color, diffuse);
	ret = ft_rgba_addition(specular, ret);
	ret = ft_rgba_addition(ambient, ret);
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
	ambient = ft_col_light(data->best->color, (1 - data->best->tan_plane.material->reflec_ratio) * data->ambient.ratio, \
							data->ambient.color);
	// diffuse = ft_col_light(data->light->color, \
	// 					data->diffuse * data->light->brightness, \
	// 					data->best->color);
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
	// data.diffuse *= (1 - data.specular);
	if (data.best->tan_plane.material->reflec_ratio > 0)
		return (ft_reflected_light(&data, depth));
	return (ft_non_reflective_light(&data));
}

t_rgba	calc_diffuse_light(t_shader_data *data, t_rgba object_color, \
									double diffuse_idx)
{
	t_rgba	diffuse;
	double	light_dot_normal;

	light_dot_normal = -ft_dot_product(data->best->tan_plane.orientation, \
									data->sr.orientation);
	if (light_dot_normal <= 0)
		return ((t_rgba){0, 0, 0, 0});
	diffuse = ft_rgba_scale(object_color, light_dot_normal * data->light->brightness * diffuse_idx);
	return (diffuse);
}

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

t_rgba	object_light(t_shader_data data)
{
	t_rgba	ambient;
	t_rgba	object_color;
	t_rgba	color;
	t_rgba	diffuse;
	t_rgba	specular;

	ambient = ft_col_light(data.ambient.color, data.ambient.ratio, \
							data.best->color);
	ambient = ft_rgba_scale(ambient, (1 - data.best->tan_plane.material->reflec_ratio));
	color = (t_rgba){0, 0, 0, 0};
	data.sr = gen_shadow_ray(data.light, data.best, &data.dis);
	data.hit = get_best_intersect(data.minirt, data.sr, data.best->pos);
	if (data.hit.distance < data.dis)
		return (ambient);
	object_color = ft_col_light(data.light->color, 1, data.best->color);
	diffuse = calc_diffuse_light(&data, object_color, 0.6);
	specular = calc_specular_light(&data, 0.6);
	// printf("specular.r: %i && specular.g: %i && specular.b: %i\n", specular.r, specular.g, specular.b);
	diffuse = ft_rgba_scale(diffuse, (1 - data.best->tan_plane.material->reflec_ratio));
	specular = ft_rgba_scale(specular, (1 - data.best->tan_plane.material->reflec_ratio));
	color = ft_rgba_addition(diffuse, specular);
	color = ft_rgba_addition(color, ambient);
	// color = ft_rgba_scale(color, (1 - data.best->tan_plane.material->reflec_ratio));
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
	// best_color = ft_rgba_addition(color, ft_col_light(\
	// minirt->ambient.color, minirt->ambient.ratio * \
	// 	(1 - best.tan_plane.material->reflec_ratio), best_color));
	return (color);
}
