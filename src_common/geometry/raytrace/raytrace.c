/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/19 18:52:51 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static void	ft_init_best(t_intersect_data *best)
{
	best->distance = INFINITY;
	best->pos = 0;
	best->tan_plane.color.r = 127;
	best->tan_plane.color.g = 127;
	best->tan_plane.color.b = 127;
	best->tan_plane.color.a = 0;
}

static void	ft_take_best_intersection(t_intersect_data *best, \
										t_intersect_data *hit)
{
	if (hit->distance < 0 || hit->distance > best->distance)
		return ;
	best->pos = hit->pos;
	best->distance = hit->distance;
	best->tan_plane.color = hit->tan_plane.color;
	best->tan_plane = hit->tan_plane;
}

t_line	gen_shadow_ray(t_minirt_data *minirt, \
					t_intersect_data best, double *dis)
{
	t_line	ray;

	ft_copy_vector(ray.point, minirt->light.point);
	ft_substraction(ray.orientation, best.tan_plane.point, \
		minirt->light.point);
	*dis = ft_module(ray.orientation);
	ft_normalize(ray.orientation, ray.orientation);
	return (ray);
}

t_rgba	shader(t_minirt_data *minirt, t_intersect_data best, \
				t_intersect *intersect, t_list *figures)
{
	t_line				sr;
	t_intersect_data	hit[2];
	t_figure_type		ft;
	double				res;
	double				dis;

	sr = gen_shadow_ray(minirt, best, &dis);
	res = -ft_dot_product(best.tan_plane.orientation, sr.orientation);
	if (res < 0)
		return ((t_rgba){0, 0, 0, 0});
	ft_init_best(&hit[1]);
	hit[0].pos = -1;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (++hit[0].pos != best.pos && intersect[ft](&hit[0], sr, \
			figures->content))
			ft_take_best_intersection(&hit[1], &hit[0]);
		figures = figures->next;
	}
	return (ft_col_light(minirt->light.color, (hit[1].distance >= dis) * res * \
		minirt->light.brightness, best.tan_plane.color));
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_intersect_data	hit[2];
	t_list				*figures;
	t_figure_type		ft;
	t_rgba				color;
	static t_intersect	intersect[3] = {inter_sphere_line, \
									inter_plane_line, inter_cyl_line};

	figures = minirt->figures;
	ft_init_best(&hit[1]);
	hit[0].pos = 0;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (intersect[ft](&hit[0], ray, figures->content))
			ft_take_best_intersection(&hit[1], &hit[0]);
		figures = figures->next;
		hit[0].pos++;
	}
	color = hit[1].tan_plane.color;
	if (hit[1].distance != INFINITY)
		hit[1].tan_plane.color = shader(minirt, hit[1], \
			intersect, minirt->figures);
	hit[1].tan_plane.color = ft_rgba_addition(hit[1].tan_plane.color, \
		ft_col_light(minirt->ambient.color, minirt->ambient.ratio, color));
	return (hit[1].tan_plane.color);
}
