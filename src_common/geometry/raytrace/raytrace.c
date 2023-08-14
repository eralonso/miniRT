/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/14 15:46:21 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

t_rgba	get_color(t_figure_type ft, void *figure)
{
	if (ft == FT_SPHERE)
		return (((t_sphere *)figure)->color);
	else if (ft == FT_PLANE)
		return (((t_plane *)figure)->color);
	return (((t_cylinder *)figure)->color);
}

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_rgba				color;
	t_vector			hit;
	t_list				*figures;
	static t_intersect	intersect[3] = {inter_sphere_line, \
									inter_plane_line, inter_cyl_line};

	figures = minirt->figures;
	color.r = 100;
	color.g = 100;
	color.b = 100;
	color.a = 0;
	while (figures)
	{
		if (intersect[((t_sphere *)(figures->content))->ft](hit, ray, figures->content))
			color = get_color(((t_sphere *)(figures->content))->ft, figures->content);
		figures = figures->next;
	}
	return (color);
}
