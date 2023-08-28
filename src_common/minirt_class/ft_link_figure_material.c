/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_figure_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:12:46 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 13:04:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_link_sphere_material(void *figure, t_list *mats)
{
	t_sphere			*sphere;

	if (!figure || !mats)
		return (0);
	sphere = figure;
	sphere->material = ft_find_material(mats, sphere->material_id);
	free(sphere->material_id);
	sphere->material_id = NULL;
	return (!!sphere->material);
}

static int	ft_link_plane_material(void *figure, t_list *mats)
{
	t_plane			*plane;

	if (!figure || !mats)
		return (0);
	plane = figure;
	plane->material = ft_find_material(mats, plane->material_id);
	free(plane->material_id);
	plane->material_id = NULL;
	return (!!plane->material);
}

static int	ft_link_cylinder_material(void *figure, t_list *mats)
{
	t_cylinder			*cyl;

	if (!figure || !mats)
		return (0);
	cyl = figure;
	cyl->material = ft_find_material(mats, cyl->material_id);
	free(cyl->material_id);
	cyl->material_id = NULL;
	return (!!cyl->material);
}

static int	ft_link_cone_material(void *figure, t_list *mats)
{
	t_cone			*cone;

	if (!figure || !mats)
		return (0);
	cone = figure;
	cone->material = ft_find_material(mats, cone->material_id);
	free(cone->material_id);
	cone->material_id = NULL;
	return (!!cone->material);
}

int	ft_link_figure_material(void *figure, t_list *mats)
{
	const t_figure_type	ft = *(t_figure_type *)figure;
	const t_mat_linker	lookuptable[4] = {ft_link_sphere_material, \
											ft_link_plane_material, \
											ft_link_cylinder_material, \
											ft_link_cone_material};

	return (lookuptable[ft](figure, mats));
}
