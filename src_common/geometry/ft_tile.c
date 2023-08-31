/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:41:36 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 12:23:15 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../common.h"

double	ft_residual(double num, double offset, double scale)
{
	const double	ratio = (num + offset) / scale / 2.0;

	return (ratio - floor(ratio));
}

void	ft_rotate(t_vector2d uv, const t_vector2d xy, double angle)
{
	const double	cos_a = cos(angle);
	const double	sin_a = sin(angle);
	t_vector2d		aux;


	aux[0] = xy[0] * cos_a - xy[1] * sin_a;
	aux[1] = xy[0] * sin_a + xy[1] * cos_a;
	uv[0] = aux[0];
	uv[1] = aux[1];
}

int	ft_tile(t_vector2d uv, t_chess_ext *chess_ext)
{
	double			residual[2];
	t_vector2d		rot_uv;
	const double	*offset = (const double *)chess_ext->offset;
	const double	*scale = (const double *)chess_ext->scale;

	ft_rotate(rot_uv, uv, chess_ext->alpha);
	residual[0] = ft_residual(rot_uv[0], offset[0], scale[0]);
	residual[1] = ft_residual(rot_uv[1], offset[1], scale[1]);
	return ((residual[0] < 0.5) ^ (residual[1] < 0.5));
}


