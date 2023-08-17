/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/17 13:45:13 by eralonso         ###   ########.fr       */
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
	t_intersect_data	hit;
	t_figure_type		ft;
	double				res;

	figures = minirt->figures;
	ft_copy_vector(ls.point, minirt->light.point);
	ft_substraction(ls.orientation, best.tan_plane.point, minirt->light.point);
	ft_normalize(ls.orientation, ls.orientation);
	res = ft_dot_product(best.tan_plane.orientation, \
	ft_scale_vector(ls.orientation, ls.orientation, -1));
	if (res <= 0)
		return ((t_rgba){0, 0, 0, 0});
	figures = minirt->figures;
	hit.pos = 0;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (best.pos != hit.pos++ && intersect[ft](&hit, ls, figures->content))
			return ((t_rgba){0, 0, 0, 0});
		figures = figures->next;
	}
	return (ft_col_light(minirt->light.color, res * \
		minirt->light.brightness, best.tan_plane.color));
}

t_rgba	ft_rgba_addition(t_rgba color1, t_rgba color2)
{
	t_rgba	ret;
	int		res;

	res = (int)color1.r + (int)color2.r;
	if (res > 255)
		res = 255;
	ret.r = res;
	res = (int)color1.g + (int)color2.g;
	if (res > 255)
		res = 255;
	ret.g = res;
	res = (int)color1.b + (int)color2.b;
	if (res > 255)
		res = 255;
	ret.b = res;
	res = (int)color1.a + (int)color2.a;
	if (res > 255)
		res = 255;
	ret.a = res;
	return (ret);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_intersect_data	best;
	t_intersect_data	hit;
	t_list				*figures;
	t_figure_type		ft;
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
	if (best.distance != INFINITY)
		best.tan_plane.color = shader(minirt, best, intersect);
	best.tan_plane.color = ft_rgba_addition(best.tan_plane.color, \
		ft_col_light(minirt->ambient.color, \
		minirt->ambient.ratio, best.tan_plane.color));
	return (best.tan_plane.color);
}
