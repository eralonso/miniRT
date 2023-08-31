/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 14:38:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

// t_rgba	chess_color(t_vector point, t_rgba material_color)
// {
// 	t_rgba	color;
// 	double	inv_scale;
// 	int		values[3];

// 	color = (t_rgba){0, 0, 0, 0};
// 	inv_scale = 1 / 0.32;
// 	values[0] = floor(inv_scale * point[0]);
// 	values[1] = floor(inv_scale * point[1]);
// 	values[2] = floor(inv_scale * point[2]);
// 	if ((values[0] + values[1] + values[2]) % 2 == 0)
// 		color = material_color;
// 	return (color);
// }

// t_rgba	chess_color(t_vector point, t_vector orientation, t_rgba material_color)
// {
// 	t_rgba		color;
// 	double		uv[2];
// 	// t_vector	trash;

// 	(void)orientation;
// 	color = (t_rgba){0, 0, 0, 0};
// 	// uv[0] = ft_scale_vector(trash, orientation, point[0])[0];
// 	// uv[1] = ft_scale_vector(trash, orientation, point[1])[1];
// 	uv[0] = floor(point[0]) / point[0];
// 	uv[1] = floor(point[1]) / point[1];
// 	if (((int)((uv[0] * 40) + (uv[1] * 40))) % 2 == 0)
// 		color = material_color;
// 	return (color);
// }

int	inter_plane_line(t_intersect_data *res, t_line line, void *figure)
{
	const t_plane	*plane = (t_plane *)figure;
	double			d;
	double			dot1;
	double			dot2;
	double			sign;

	d = -ft_dot_product((double *)plane->point, (double *)plane->orientation);
	dot1 = ft_dot_product((double *)plane->orientation, line.orientation);
	dot2 = ft_dot_product((double *)plane->orientation, line.point);
	if (dot1 == 0)
		return (0);
	res->distance = -(dot2 + d) / dot1;
	if (res->distance < 0)
		return (0);
	sign = -dot1 / fabs(dot1);
	ft_scale_vector(res->tan_plane.orientation, \
		(double *)plane->orientation, sign);
	res->tan_plane.material = plane->material;
	ft_addition(res->tan_plane.point, line.point, \
		ft_scale_vector(res->tan_plane.point, \
			line.orientation, res->distance));
	res->color = chess_plane_pick_color(res->tan_plane.point, \
					(double *)plane->point, \
					res->tan_plane.orientation, res->tan_plane.material);
	return (1);
}
