/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:48:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 15:03:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_parse_sphere(t_list *node, char **str_arr)
{
	t_sphere	*sphere;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (ft_log_error(ERR_SPHERE_MALLOC_FAILED));
	sphere->ft = FT_SPHERE;
	if (ft_matrixlen(str_arr) != SPHERE_COMPONENTS_NUMBER)
	{
		free(sphere);
		return (ft_free_n_log_error(sphere, ERR_SPHERE_COMPONENTS_NUMBER));
	}
	if (!ft_isvector(str_arr[1], sphere->point)
		|| !ft_ispositivedouble(str_arr[2], &sphere->diameter)
		|| !ft_isname(str_arr[3], &sphere->material_id))
	{
		ft_free_figure(sphere);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = sphere;
	return (1);
}

int	ft_parse_plane(t_list *node, char **str_arr)
{
	t_plane		*plane;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (ft_log_error(ERR_PLANE_MALLOC_FAILED));
	plane->ft = FT_PLANE;
	if (ft_matrixlen(str_arr) != PLANE_COMPONENTS_NUMBER)
		return (ft_free_n_log_error(plane, ERR_PLANE_COMPONENTS_NUMBER));
	if (!ft_isvector(str_arr[1], plane->point)
		|| !ft_isorientation(str_arr[2], plane->orientation)
		|| !ft_isname(str_arr[3], &plane->material_id))
	{
		ft_free_figure(plane);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = plane;
	return (1);
}

int	ft_parse_cylinder(t_list *node, char **str_arr)
{
	t_cylinder	*cylinder;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (ft_log_error(ERR_CYLINDER_MALLOC_FAILED));
	cylinder->ft = FT_CYLINDER;
	if (ft_matrixlen(str_arr) != CYLINDER_COMPONENTS_NUMBER)
		return (ft_free_n_log_error(cylinder, ERR_CYLINDER_COMPONENTS_NUMBER));
	if (!ft_isvector(str_arr[1], cylinder->point)
		|| !ft_isorientation(str_arr[2], cylinder->orientation)
		|| !ft_ispositivedouble(str_arr[3], &cylinder->diameter)
		|| !ft_ispositivedouble(str_arr[4], &cylinder->height)
		|| !ft_isname(str_arr[5], &cylinder->material_id))
	{
		free(cylinder);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = cylinder;
	return (1);
}

static void	ft_arrange_cone_heights(t_cone *cone)
{
	double	aux;

	if (cone->heights[0] > cone->heights[1])
	{
		aux = cone->heights[0];
		cone->heights[0] = cone->heights[1];
		cone->heights[1] = aux;
	}
}

int	ft_parse_cone(t_list *node, char **str_arr)
{
	t_cone		*cone;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	cone = ft_calloc(sizeof(t_cone), 1);
	if (!cone)
		return (ft_log_error(ERR_CONE_MALLOC_FAILED));
	cone->ft = FT_CONE;
	if (ft_matrixlen(str_arr) != CONE_COMPONENTS_NUMBER)
		return (ft_free_n_log_error(cone, ERR_CONE_COMPONENTS_NUMBER));
	if (!ft_isvector(str_arr[1], cone->point)
		|| !ft_isorientation(str_arr[2], cone->orientation)
		|| !ft_istheta(str_arr[3], &cone->theta)
		|| !ft_ispositivedouble(str_arr[4], &cone->heights[0])
		|| !ft_ispositivedouble(str_arr[5], &cone->heights[1])
		|| !ft_isname(str_arr[6], &cone->material_id))
	{
		ft_free_figure(cone);
		return (0);
	}
	ft_arrange_cone_heights(cone);
	free_x((void **)&node->content);
	node->content = cone;
	return (1);
}
