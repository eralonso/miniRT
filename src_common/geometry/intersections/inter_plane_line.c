/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/29 17:33:05 by eralonso         ###   ########.fr       */
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

static double       module(double num)
{
     return (num - floor(num));
}

t_rgba       chess_method_02(t_vector point, t_vector orientation, t_rgba color)
{
     t_vector        trash;
     double          uv[2];

	 if (ft_dot_product((t_vector){1, 1, 0}, orientation))
	 {
		uv[0] = ft_scale_vector(trash, orientation, point[0])[0];
		uv[1] = ft_scale_vector(trash, orientation, point[1])[1];
	 }
	 else if (ft_dot_product((t_vector){0, 1, 1}, orientation))
	 {
		uv[0] = ft_scale_vector(trash, orientation, point[1])[1];
		uv[1] = ft_scale_vector(trash, orientation, point[2])[2];
	 }
	 else if (ft_dot_product((t_vector){1, 0, 1}, orientation))
	 {
		uv[0] = ft_scale_vector(trash, orientation, point[0])[0];
		uv[1] = ft_scale_vector(trash, orientation, point[2])[2];
	 }
     if ((module(uv[0]) < 0.5) ^ (module(uv[1]) < 0.5))
             return (color);
     return ((t_rgba){0, 0, 0, 0});
}

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
	res->color = chess_method_02(res->tan_plane.point, res->tan_plane.orientation, res->tan_plane.material->color);
	return (1);
}
