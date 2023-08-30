/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chess_pick_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/30 18:53:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static double	module(double num, double offset, double scale)
{
	const double	ratio = (num + offset) / scale / 2.0;

	return (ratio - floor(ratio));
}

static int	ft_tile(t_vector2d uv, t_chess_ext *chess_ext)
{
	return ((module(uv[0], chess_ext->offset[0], chess_ext->scale[0]) < 0.5) \
		^ (module(uv[1], chess_ext->offset[1], chess_ext->scale[1]) < 0.5));
}

static void	ft_rotate(t_vector2d uv, const t_vector2d xy, double angle)
{
	const double	cos_a = cos(angle);
	const double	sin_a = sin(angle);
	t_vector2d		aux;


	aux[0] = xy[0] * cos_a - xy[1] * sin_a;
	aux[1] = xy[0] * sin_a + xy[1] * cos_a;
	uv[0] = aux[0];
	uv[1] = aux[1];
}

t_rgba	chess_pick_color(t_vector point, t_vector origin, \
			t_vector orientation, t_material *mat)
{
	t_vector	trash;
	t_vector	main_axis;
	t_vector	base[2];
	t_vector2d	uv;
	t_chess_ext	*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	ft_substraction(trash, point, origin);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product(orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], orientation, base[0]);
	uv[0] = ft_dot_product(base[0], trash);
	uv[1] = ft_dot_product(base[1], trash);
	ft_rotate(uv, uv, chess_ext->alpha);
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}
