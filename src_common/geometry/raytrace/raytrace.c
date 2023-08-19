/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/19 16:56:10 by eralonso         ###   ########.fr       */
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

static t_rgba	ft_col_light(t_rgba color_source, double ratio, t_rgba surf_col)
{
	const unsigned char	*light_channels = \
		(const unsigned char *)&color_source;
	unsigned char		*surf_channels;
	int					i;
	double				comp;

	surf_channels = (unsigned char *)&surf_col;
	i = 0;
	while (i < 3)
	{
		comp = ratio * light_channels[i] / 255.0;
		surf_channels[i] = (unsigned char)floor(comp * surf_channels[i]);
		i++;
	}
	return (surf_col);
}

t_rgba	shader(t_minirt_data *minirt, t_intersect_data best, \
				t_intersect *intersect)
{
	t_line				ls;
	t_list				*figures;
	t_intersect_data	hit[2];
	t_figure_type		ft;
	double				res;
	double				dis;
	t_vector			trash;

	ft_copy_vector(ls.point, minirt->light.point);
	ft_substraction(ls.orientation, best.tan_plane.point, minirt->light.point);
	dis = ft_module(ls.orientation);
	ft_normalize(ls.orientation, ls.orientation);
	res = ft_dot_product(best.tan_plane.orientation, \
	ft_scale_vector(trash, ls.orientation, -1));
	if (res < 0)
		return ((t_rgba){0, 0, 0, 0});
	figures = minirt->figures;
	ft_init_best(&hit[1]);
	hit[0].pos = -1;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (++hit[0].pos != best.pos && intersect[ft](&hit[0], ls, figures->content))
			ft_take_best_intersection(&hit[1], &hit[0]);
		figures = figures->next;
	}
	if (hit[1].distance < dis)
		return ((t_rgba){0, 0, 0, 0});
	return (ft_col_light(minirt->light.color, res * \
		minirt->light.brightness, best.tan_plane.color));
}

unsigned char	check_addition_rgba(unsigned char color1, unsigned char color2)
{
	int	res;

	res = (int)color1 + (int)color2;
	if (res > 255)
		res = 255;
	return (res);
}

t_rgba	ft_rgba_addition(t_rgba color1, t_rgba color2)
{
	t_rgba	ret;

	ret.r = check_addition_rgba(color1.r, color2.r);
	ret.g = check_addition_rgba(color1.g, color2.g);
	ret.b = check_addition_rgba(color1.b, color2.b);
	ret.a = check_addition_rgba(color1.a, color2.a);
	return (ret);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_intersect_data	best;
	t_intersect_data	hit;
	t_list				*figures;
	t_figure_type		ft;
	t_rgba				color;
	static t_intersect	intersect[3] = {inter_sphere_line, \
									inter_plane_line, inter_cyl_line};

	figures = minirt->figures;
	ft_init_best(&best);
	hit.pos = 0;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (intersect[ft](&hit, ray, figures->content))
			ft_take_best_intersection(&best, &hit);
		figures = figures->next;
		hit.pos++;
	}
	color = best.tan_plane.color;
	if (best.distance != INFINITY)
		best.tan_plane.color = shader(minirt, best, intersect);
	best.tan_plane.color = ft_rgba_addition(best.tan_plane.color, \
		ft_col_light(minirt->ambient.color, \
		minirt->ambient.ratio, color));
	return (best.tan_plane.color);
}
