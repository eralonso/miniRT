/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:40:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 11:38:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_free_sphere(void *figure)
{
	t_sphere	*sphere;

	sphere = figure;
	if (sphere->material_id)
		free(sphere->material_id);
	free (sphere);
}

static void	ft_free_plane(void *figure)
{
	t_plane	*plane;

	plane = figure;
	if (plane->material_id)
		free(plane->material_id);
	free (plane);
}

static void	ft_free_cylinder(void *figure)
{
	t_cylinder	*cyl;

	cyl = figure;
	if (cyl->material_id)
		free(cyl->material_id);
	free (cyl);
}

static void	ft_free_cone(void *figure)
{
	t_cone	*cone;

	cone = figure;
	if (cone->material_id)
		free(cone->material_id);
	free (cone);
}

void	ft_free_figure(void *figure)
{
	const t_figure_type	ft = *(t_figure_type *)figure;
	const t_freeer		lookuptable[4] = {ft_free_sphere, ft_free_plane, \
										ft_free_cylinder, ft_free_cone};

	lookuptable[ft](figure);
}
