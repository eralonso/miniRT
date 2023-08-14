/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/14 11:29:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_rgba				color;
	t_vector			hit;
	t_list				*figures;
	static t_intersect	intersect[3] = {inter_sphere_line, inter_plane_line, inter_cyl_line};

	figures = minirt->figures;
	color.r = 100;
	color.g = 100;
	color.b = 100;
	color.a = 0;
	while (figures)
	{
		if (((t_sphere *)(figures->content))->ft == FT_SPHERE && \
			intersect[((t_sphere *)(figures->content))->ft](hit, ray, figures->content))
			color = ((t_sphere *)(figures->content))->color;
		figures = figures->next;
	}
	return (color);
}
