/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:53:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 15:09:25 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_create_background(t_minirt_data *minirt)
{
	t_material	*mat;
	t_list		*node;

	minirt->background_color = ft_rgba_scale(minirt->ambient.color, \
											minirt->ambient.ratio);
	mat = ft_calloc(1, sizeof(t_material));
	if (!mat)
		return (ft_log_error(ERR_MATERIAL_MALLOC_FAILED));
	mat->name = ft_strdup("BACKGROUND_COLOR");
	if (!mat->name)
	{
		free(mat);
		return (ft_log_error(ERR_MATERIAL_MALLOC_FAILED));
	}
	mat->type = MTT_HOMOG;
	mat->color = minirt->background_color;
	mat->reflec_ratio = 0.0;
	node = ft_lstnew(mat);
	if (!node)
	{
		ft_free_material(mat);
		return (ft_log_error(ERR_MATERIAL_MALLOC_FAILED));
	}
	ft_lstadd_front(&minirt->materials_list, node);
	return (1);
}
