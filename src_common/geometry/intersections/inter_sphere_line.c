/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/04 16:00:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

static int	ft_coef_calc(double coefs[3], t_line line, const t_sphere *sphere)
{
	t_vector		rel_origin;
	const double	radius = sphere->diameter / 2.0;

	ft_substraction(rel_origin, line.point, (double *)sphere->point);
	coefs[0] = 1.0;
	coefs[1] = ft_dot_product(line.orientation, rel_origin);
	coefs[2] = ft_dot_product(rel_origin, rel_origin) - radius * radius;
	return (1);
}

int	inter_sphere_line(t_intersect_data *ret, t_line line, void *figure)
{
	const t_sphere		*sphere = (t_sphere *)figure;
	double				coefs[3];
	double				roots[2];

	if (!ft_coef_calc(coefs, line, sphere))
		return (0);
	ft_quadrat_eq2(coefs, roots);
	if (!ft_take_min_pos_root(&ret->distance, roots))
		return (0);
	ret->tan_plane.material = sphere->material;
	ft_addition(ret->tan_plane.point, line.point, \
		ft_scale_vector(ret->tan_plane.point, \
			line.orientation, ret->distance));
	ft_substraction(ret->tan_plane.orientation, \
		ret->tan_plane.point, (double *)sphere->point);
	ft_normalize(ret->tan_plane.orientation, ret->tan_plane.orientation);
	ret->color = chess_sphere_pick_color(ret->tan_plane.orientation, \
										sphere->material);
	return (1);
}
