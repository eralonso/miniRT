/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/22 15:52:49 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

t_rgba	shader(t_light *light, t_intersect_data best, \
				t_intersect *intersect, t_list *figures, \
					t_line ray, t_minirt_data *minirt, int depth)
{
	t_line				sr;
	t_intersect_data	hit;
	double				res;
	double				res2;
	double				dis;
	double				ratio;
	t_vector			trash;

	sr = gen_shadow_ray(light, best, &dis);
	res = -ft_dot_product(best.tan_plane.orientation, sr.orientation);
	if (res < 0)
		res = 0;
	res2 = ft_dot_product(ft_scale_vector(trash, ray.orientation, -1), \
		gen_reflect_ray(sr, best).orientation);
	if (res2 < 0)
		res2 = 0;
	res2 = pow(res, 300);
	res *= (1 - res2);
	ratio = light->brightness;
	best.kr = 0;
	if (best.ft == FT_PLANE)
		best.kr = 0.5;
	else
		best.kr = 0.5;
	hit = get_best_intersect(figures, sr, intersect, best.pos);
	if (hit.distance < dis)
		return ((t_rgba){0, 0, 0, 0});
	if (best.kr)
		return (ft_rgba_scale(ft_rgba_addition(ft_rgba_scale(\
				light->color, light->brightness * res2), ft_rgba_addition(\
				ft_col_light(light->color, res * light->brightness * best.kr, \
				raytrace(minirt, gen_reflect_ray(ray, best), depth - 1)), \
				ft_col_light(light->color, res * light->brightness * \
				(1 - best.kr), best.tan_plane.color))), 0.8));
	return (ft_rgba_scale(ft_rgba_addition(ft_rgba_scale(\
			light->color, light->brightness * res2), \
			ft_col_light(light->color, res * light->brightness, \
			best.tan_plane.color)), 0.8));
}

t_rgba	get_sum_lights(t_list *lights, t_intersect_data best, \
			t_intersect *intersect, t_list *figures, \
			t_line ray, t_minirt_data *minirt, int depth)
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
	static t_intersect	intersect[4] = {inter_sphere_line, \
									inter_plane_line, \
									inter_cyl_line, \
									inter_cone_line};

	if (depth == 0)
		return (get_background_color());
	best = get_best_intersect(minirt->figures, ray, intersect, -1);
	color = best.tan_plane.color;
	if (best.distance != INFINITY)
		color = get_sum_lights(minirt->lights, best, intersect, \
			minirt->figures, ray, minirt, depth);
	best.tan_plane.color = ft_rgba_addition(color, ft_col_light(\
	minirt->ambient.color, minirt->ambient.ratio * 0.4, best.tan_plane.color));
	return (best.tan_plane.color);
}
