/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/17 11:41:07 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static void	ft_init_best(t_intersect_data *best)
{
	best->distance = INFINITY;
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
	best->distance = hit->distance;
	best->tan_plane.color = hit->tan_plane.color;
	best->tan_plane = hit->tan_plane;
}

static t_rgba	ft_col_light(t_minirt_data *minirt, t_line ray, t_rgba surf_col)
{
	const unsigned char	*light_channels = \
		(const unsigned char *)&minirt->ambient.color;
	unsigned char		*surf_channels;
	int					i;
	double				comp;

	(void)ray;
	surf_channels = (unsigned char *)&surf_col;
	i = 0;
	while (i < 3)
	{
		comp = minirt->ambient.ratio * light_channels[i] / 255.0;
		surf_channels[i] = (unsigned char)floor(comp * surf_channels[i]);
		i++;
	}
	return (surf_col);
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
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		if (intersect[ft](&hit, ray, figures->content))
			ft_take_best_intersection(&best, &hit);
		figures = figures->next;
	}
	return (ft_col_light(minirt, ray, best.tan_plane.color));
}
