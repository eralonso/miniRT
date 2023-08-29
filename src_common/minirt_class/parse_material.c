/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:02 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/29 14:04:41 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_parse_material(t_list *node, char **str_arr)
{
	t_material	*mat;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	mat = ft_calloc(1, sizeof(t_material));
	if (!mat)
		return (ft_log_error(ERR_MATERIAL_MALLOC_FAILED));
	if (ft_matrixlen(str_arr) < MATERIAL_MIN_COMPONENTS_NUMBER)
	{
		free(mat);
		return (ft_log_error(ERR_MATERIAL_COMPONENTS_NUMBER));
	}
	if (
		!ft_ismattype(str_arr[1], &mat->type)
		|| !ft_isname(str_arr[2], &mat->name)
		|| !ft_isrgb(str_arr[3], &mat->color)
		|| !ft_isratio(str_arr[4], &mat->reflec_ratio)
		|| !ft_ispositivedouble(str_arr[5], &mat->n_sharpness))
	{
		ft_free_material(mat);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = mat;
	return (1);
}
