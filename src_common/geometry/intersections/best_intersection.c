/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:27:11 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/20 19:15:23 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

static void	ft_init_best(t_intersect_data *best)
{
	best->distance = INFINITY;
	best->pos = 0;
	best->tan_plane.color = get_background_color();
}

static void	ft_take_best_intersection(t_intersect_data *best, \
										t_intersect_data *hit)
{
	if (hit->distance < 0 || hit->distance > best->distance)
		return ;
	best->pos = hit->pos;
	best->distance = hit->distance;
	best->tan_plane = hit->tan_plane;
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
		if (++hit.pos != exclude && intersect[ft](&hit, ray, \
			figures->content))
			ft_take_best_intersection(&best, &hit);
		figures = figures->next;
	}
	return (best);
}
