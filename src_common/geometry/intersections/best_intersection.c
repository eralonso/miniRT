/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:27:11 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/29 10:52:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

static void	ft_init_best(t_intersect_data *best, t_minirt_data *minirt)
{
	best->distance = INFINITY;
	best->pos = 0;
	best->tan_plane.ft = FT_PLANE;
	best->tan_plane.material = minirt->materials_list->content;
}

static void	ft_take_best_intersection(t_intersect_data *best, \
										t_intersect_data *hit)
{
	if (hit->distance < 0 || hit->distance > best->distance)
		return ;
	best->pos = hit->pos;
	best->ft = hit->ft;
	best->distance = hit->distance;
	best->tan_plane = hit->tan_plane;
}

t_intersect_data	get_best_intersect(t_minirt_data *minirt, \
										t_line ray, int exclude)
{
	const t_list		*figures = minirt->figures;
	const t_intersect	*intersect = minirt->intersect;
	t_intersect_data	best;
	t_intersect_data	hit;
	t_figure_type		ft;

	ft_init_best(&best, minirt);
	hit.pos = -1;
	while (figures)
	{
		ft = *((t_figure_type *)(figures->content)); 
		hit.ft = ft;
		if (++hit.pos != exclude && intersect[ft](&hit, ray, \
			figures->content))
			ft_take_best_intersection(&best, &hit);
		figures = figures->next;
	}
	return (best);
}
