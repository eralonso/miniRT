/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:36:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 15:37:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

t_rgba	calc_diffuse_light(t_shader_data *data, t_rgba object_color, \
									double diffuse_idx)
{
	t_rgba	diffuse;
	double	light_dot_normal;

	light_dot_normal = -ft_dot_product(data->best->tan_plane.orientation, \
									data->sr.orientation);
	if (light_dot_normal <= 0)
		return ((t_rgba){0, 0, 0, 0});
	diffuse = ft_rgba_scale(object_color, \
					light_dot_normal * data->light->brightness * diffuse_idx);
	return (diffuse);
}
