/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chess_pick_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:21:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 13:20:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

t_rgba	chess_plane_pick_color(t_vector point, t_vector origin, \
			t_vector orientation, const t_plane *plane)
{
	const t_material	*mat = plane->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;
	t_image_ext			*image_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	ft_planar_map(uv, point, origin, orientation);
	if (mat->type == MTT_CHESS)
	{
		chess_ext = (t_chess_ext *)mat->ext_prop;
		if (ft_tile(uv, chess_ext))
			return (mat->color);
		return (chess_ext->color);
	}
	image_ext = (t_image_ext *)mat->ext_prop;
	return (ft_tile_image(uv, image_ext));
}

t_rgba	chess_sphere_pick_color(t_vector orientation, const t_sphere *sphere)
{
	const t_material	*mat = sphere->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;
	t_image_ext			*image_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	ft_spherical_map(uv, orientation);
	uv[0] *= 20;
	uv[1] *= 10;
	if (mat->type == MTT_CHESS)
	{
		chess_ext = (t_chess_ext *)mat->ext_prop;
		if (ft_tile(uv, chess_ext))
			return (mat->color);
		return (chess_ext->color);
	}
	image_ext = (t_image_ext *)mat->ext_prop;
	return (ft_tile_image(uv, image_ext));
}

t_rgba	chess_cylin_pick_color(t_vector point, const t_cylinder *cyl)
{
	const t_material	*mat = cyl->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;
	t_image_ext			*image_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	ft_cyl_map(uv, point, cyl);
	uv[0] *= 20;
	if (mat->type == MTT_CHESS)
	{
		chess_ext = (t_chess_ext *)mat->ext_prop;
		if (ft_tile(uv, chess_ext))
			return (mat->color);
		return (chess_ext->color);
	}
	image_ext = (t_image_ext *)mat->ext_prop;
	return (ft_tile_image(uv, image_ext));
}

t_rgba	chess_cone_pick_color(t_vector point, const t_cone *cone)
{
	const t_material	*mat = cone->material;
	t_vector2d			uv;
	t_chess_ext			*chess_ext;
	t_image_ext			*image_ext;

	if (mat->type == MTT_HOMOG)
		return (mat->color);
	ft_cone_map(uv, point, cone);
	uv[0] *= 20;
	if (mat->type == MTT_CHESS)
	{
		chess_ext = (t_chess_ext *)mat->ext_prop;
		if (ft_tile(uv, chess_ext))
			return (mat->color);
		return (chess_ext->color);
	}
	image_ext = (t_image_ext *)mat->ext_prop;
	return (ft_tile_image(uv, image_ext));
}
