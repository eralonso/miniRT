/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/16 17:35:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

int	inter_plane_line(t_intersect_data *res, t_line line, void *figure)
{
	const t_plane	*plane = (t_plane *)figure;
	double			d;
	double			dot1;
	double			dot2;

	d = -ft_dot_product((double *)plane->point, (double *)plane->orientation);
	dot1 = ft_dot_product((double *)plane->orientation, line.orientation);
	dot2 = ft_dot_product((double *)plane->orientation, line.point);
	if (dot1 == 0)
		return (0);
	res->distance = -(dot2 + d) / dot1;
	if (res->distance < 0)
		return (0);
	ft_copy_vector(res->tan_plane.orientation, (double *)plane->orientation);
	res->tan_plane.color = plane->color;
	ft_addition(res->tan_plane.point, line.point, \
		ft_scale_vector(res->tan_plane.point, \
			line.orientation, res->distance));
	return (1);
}
