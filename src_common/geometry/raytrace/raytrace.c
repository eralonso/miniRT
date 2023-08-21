/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/21 12:50:49 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

t_line	gen_shadow_ray(t_light *light, \
					t_intersect_data best, double *dis)
{
	t_line	ray;

	ft_copy_vector(ray.point, light->point);
	ft_substraction(ray.orientation, best.tan_plane.point, \
		light->point);
	if (dis)
		*dis = ft_module(ray.orientation);
	ft_normalize(ray.orientation, ray.orientation);
	return (ray);
}

t_line	get_reflect_ray(t_line ray, t_intersect_data hit)
{
	t_line		reflect;
	t_vector	trash;

	ft_copy_vector(reflect.point, hit.tan_plane.point);
	ft_addition(reflect.point, reflect.point, ft_scale_vector(trash, hit.tan_plane.orientation, 0.0006));
	ft_substraction(reflect.orientation, ray.orientation, \
		ft_scale_vector(trash, hit.tan_plane.orientation, \
			ft_dot_product(ray.orientation, hit.tan_plane.orientation) * 2));
	return (reflect);
}

t_rgba	ft_rgba_scale(t_rgba color, double scale)
{
	t_rgba	ret;

	ret.r = color.r * scale;
	ret.g = color.g * scale;
	ret.b = color.b * scale;
	ret.a = color.a * scale;
	return (ret);
}

t_rgba	shader(t_light *light, t_intersect_data best, \
				t_intersect *intersect, t_list *figures, \
					t_line ray, t_minirt_data *minirt, int depth)
{
	t_line				sr;
	t_intersect_data	hit;
	double				res;
	double				dis;

	sr = gen_shadow_ray(light, best, &dis);
	res = -ft_dot_product(best.tan_plane.orientation, sr.orientation);
	if (res < 0)
		return ((t_rgba){0, 0, 0, 0});
	hit = get_best_intersect(figures, sr, intersect, best.pos);
	if (hit.distance < dis)
		return ((t_rgba){0, 0, 0, 0});
	(void)ray;
	(void)minirt;
	(void)depth;
	if (best.ft == FT_PLANE)
		best.tan_plane.color = ft_rgba_addition(best.tan_plane.color, \
			ft_rgba_scale(raytrace(minirt, get_reflect_ray(ray, best), depth - 1), 0.8));
	return (ft_col_light(light->color, res * \
		light->brightness, best.tan_plane.color));
}

t_rgba	get_sum_lights(t_list *lights, t_intersect_data best, \
						t_intersect *intersect, t_list *figures, t_line ray, t_minirt_data *minirt, int depth)
{
	t_rgba	color;

	color = (t_rgba){0, 0, 0, 0};
	while (lights)
	{
		color = ft_rgba_addition(color, shader((t_light *)lights->content, \
						best, intersect, figures, ray, minirt, depth));
		lights = lights->next;
	}
	return (color);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray, int depth)
{
	t_intersect_data	best;
	t_rgba				color;
	static t_intersect	intersect[3] = {inter_sphere_line, \
									inter_plane_line, inter_cyl_line};

	if (depth == 0)
		return (get_background_color());
	best = get_best_intersect(minirt->figures, ray, intersect, -1);
	color = best.tan_plane.color;
	if (best.distance != INFINITY)
		color = get_sum_lights(minirt->lights, best, intersect, minirt->figures, ray, minirt, depth);
		// color = shader(minirt, best, intersect, minirt->figures);
	best.tan_plane.color = ft_rgba_addition(color, ft_col_light(\
	minirt->ambient.color, minirt->ambient.ratio, best.tan_plane.color));
	return (best.tan_plane.color);
}
