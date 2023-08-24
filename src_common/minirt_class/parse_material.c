/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:02 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 17:39:51 by omoreno-         ###   ########.fr       */
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
		|| !ft_isratio(str_arr[4], &mat->reflec_ratio))
	{
		ft_free_material(mat);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = mat;
	return (1);
}
