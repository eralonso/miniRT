/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mat_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:34:34 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 13:30:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_parse_image_extension(t_material *mat, char **str_arr)
{
	t_image_ext	*image_ext;

	image_ext = mat->ext_prop;
	if (
		!ft_isexistingfile(str_arr[8], &image_ext->filename)
		|| !ft_isvector2d(str_arr[9], image_ext->scale)
		|| !ft_isvector2d(str_arr[10], image_ext->offset)
		|| !ft_isangle(str_arr[11], &image_ext->alpha))
		return (0);
	return (1);
}

int	ft_parse_image_material(t_material *mat, char **str_arr, int argc)
{
	if (argc < MATERIAL_IMAGE_COMPONENTS_NUMBER)
	{
		ft_free_material(mat);
		return (ft_log_error(ERR_IMAGE_MATERIAL_COMPONENTS_NUMBER));
	}
	mat->ext_prop = ft_calloc(1, sizeof(t_image_ext));
	if (!mat->ext_prop)
		ft_log_error(ERR_MATERIAL_MALLOC_FAILED);
	if (
		!mat->ext_prop || !ft_isname(str_arr[2], &mat->name)
		|| !ft_isrgb(str_arr[3], &mat->color)
		|| !ft_isratio(str_arr[4], &mat->reflec_ratio)
		|| !ft_ispositivedouble(str_arr[5], &mat->n_sharpness)
		|| !ft_isratio(str_arr[6], &mat->diffuse_ratio)
		|| !ft_isratio(str_arr[7], &mat->specular_ratio)
		|| !ft_parse_image_extension(mat, str_arr))
	{
		ft_free_material(mat);
		return (0);
	}
	return (1);
}
