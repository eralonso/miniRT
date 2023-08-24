/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:27:11 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/24 12:00:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

static void	ft_init_best(t_intersect_data *best)
{
	best->distance = INFINITY;
	best->pos = 0;
	best->tan_plane.color = get_background_color();
	best->tan_plane.reflec_ratio = 0;
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
	best->tan_plane.reflec_ratio = hit->tan_plane.reflec_ratio;
}

t_intersect_data	get_best_intersect(t_list *figures, t_line ray, \
							t_intersect *intersect, int exclude)
{
	t_intersect_data	best;
	t_intersect_data	hit;
	t_figure_type		ft;

	ft_init_best(&best);
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
