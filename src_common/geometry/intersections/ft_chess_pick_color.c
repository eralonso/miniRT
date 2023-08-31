/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chess_pick_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 12:12:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

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
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}
