/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/20 19:14:33 by eralonso         ###   ########.fr       */
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

t_rgba	shader(t_light *light, t_intersect_data best, \
				t_intersect *intersect, t_list *figures)
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
	return (ft_col_light(light->color, res * \
		light->brightness, best.tan_plane.color));
}

t_rgba	get_sum_lights(t_list *lights, t_intersect_data best, \
						t_intersect *intersect, t_list *figures)
{
	t_rgba	color;

	color = (t_rgba){0, 0, 0, 0};
	while (lights)
	{
		color = ft_rgba_addition(color, shader((t_light *)lights->content, \
						best, intersect, figures));
		lights = lights->next;
	}
	return (color);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_intersect_data	best;
	t_rgba				color;
	static t_intersect	intersect[3] = {inter_sphere_line, \
									inter_plane_line, inter_cyl_line};

	best = get_best_intersect(minirt->figures, ray, intersect, -1);
	color = best.tan_plane.color;
	if (best.distance != INFINITY)
		color = get_sum_lights(minirt->lights, best, intersect, minirt->figures);
		// color = shader(minirt, best, intersect, minirt->figures);
	best.tan_plane.color = ft_rgba_addition(color, ft_col_light(\
	minirt->ambient.color, minirt->ambient.ratio, best.tan_plane.color));
	return (best.tan_plane.color);
}
