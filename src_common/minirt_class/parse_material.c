/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:45:02 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/30 12:47:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_parse_homog_material(t_material *mat, char **str_arr, int argc)
{
	if (argc > MATERIAL_MIN_COMPONENTS_NUMBER)
	{
		ft_free_material(mat);
		return (ft_log_error(ERR_MATERIAL_COMPONENTS_NUMBER));
	}
	if (
		!ft_isname(str_arr[2], &mat->name)
		|| !ft_isrgb(str_arr[3], &mat->color)
		|| !ft_isratio(str_arr[4], &mat->reflec_ratio)
		|| !ft_ispositivedouble(str_arr[5], &mat->n_sharpness))
	{
		ft_free_material(mat);
		return (0);
	}
	return (1);
}

static int	ft_parse_chess_material(t_material *mat, char **str_arr, int argc)
{
	if (argc < MATERIAL_CHESS_COMPONENTS_NUMBER)
	{
		ft_free_material(mat);
		return (ft_log_error(ERR_CHESS_MATERIAL_COMPONENTS_NUMBER));
	}
	mat->ext_prop = ft_calloc(1, sizeof(t_chess_ext));
	if (!mat->ext_prop)
		ft_log_error(ERR_MATERIAL_MALLOC_FAILED);
	if (
		!mat->ext_prop || !ft_isname(str_arr[2], &mat->name)
		|| !ft_isrgb(str_arr[3], &mat->color)
		|| !ft_isratio(str_arr[4], &mat->reflec_ratio)
		|| !ft_ispositivedouble(str_arr[5], &mat->n_sharpness)
		|| !ft_isrgb(str_arr[6], &((t_chess_ext *)(mat->ext_prop))->color))
	{
		ft_free_material(mat);
		return (0);
	}
	return (1);
}


int	ft_parse_material(t_list *node, char **str_arr)
{
	int					argc;
	t_material			*mat;
	const t_mat_parser	mp[3] = {NULL, ft_parse_homog_material, \
									ft_parse_chess_material};

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	mat = ft_calloc(1, sizeof(t_material));
	if (!mat)
		return (ft_log_error(ERR_MATERIAL_MALLOC_FAILED));
	argc = ft_matrixlen(str_arr);
	if (argc < MATERIAL_MIN_COMPONENTS_NUMBER)
	{
		free(mat);
		return (ft_log_error(ERR_MATERIAL_COMPONENTS_NUMBER));
	}
	if (!ft_ismattype(str_arr[1], &mat->type) \
		|| !mp[mat->type](mat, str_arr, argc))
		return (0);
	free_x((void **)&node->content);
	node->content = mat;
	return (1);
}
