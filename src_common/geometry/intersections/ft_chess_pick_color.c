/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chess_pick_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 14:37:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

t_rgba	chess_plane_pick_color(t_vector point, t_vector origin, \
			t_vector orientation, t_material *mat)
{
	t_vector2d	uv;
	t_chess_ext	*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_planar_map(uv, point, origin, orientation);
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}

t_rgba	chess_sphere_pick_color(t_vector orientation, t_material *mat)
{
	t_vector2d		uv;
	t_chess_ext		*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_spherical_map(uv, orientation);
	uv[0] *= 20;
	uv[1] *= 10;
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}
