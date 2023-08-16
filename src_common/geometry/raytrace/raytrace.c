/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/16 17:34:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static void	ft_init_best(t_intersect_data *best)
{
	best->distance = INFINITY;
	best->tan_plane.color.r = 100;
	best->tan_plane.color.g = 100;
	best->tan_plane.color.b = 100;
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
	return (best.tan_plane.color);
}
