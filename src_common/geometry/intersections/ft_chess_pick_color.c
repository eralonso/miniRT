/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chess_pick_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/01 18:04:52 by omoreno-         ###   ########.fr       */
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

t_rgba	chess_cyl_pick_color(t_vector point, t_vector origin, \
			t_vector orientation, t_material *mat)
{
	t_vector2d	uv;
	t_chess_ext	*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_cylindrical_map(uv, point, origin, orientation);
	uv[0] *= 20;
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}

t_rgba	chess_cylin_pick_color(t_vector point, const t_cylinder *cyl)
{
	const t_material	*mat = cyl->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_cyl_map(uv, point, cyl);
	uv[0] *= 20;
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}

t_rgba	chess_cone_pick_color(t_vector point, const t_cone *cone)
{
	const t_material	*mat = cone->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	chess_ext = (t_chess_ext *)mat->ext_prop;
	ft_cone_map(uv, point, cone);
	uv[0] *= 20;
	if (ft_tile(uv, chess_ext))
		return (mat->color);
	return (chess_ext->color);
}
