/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomputers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:37:37 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#include <math.h>

void	ft_sphere_precomputer(void *figure)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)figure;
	sphere->radius = sphere->diameter / 2.0;
}

void	ft_plane_precomputer(void *figure)
{
	(void)figure;
}

void	ft_cylinder_precomputer(void *figure)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)figure;
	cyl->radius = cyl->diameter / 2.0;
	cyl->radius_sq = cyl->radius * cyl->radius;
	cyl->half_height = cyl->height / 2.0;
	cyl->caps[0].ft = FT_PLANE;
	cyl->caps[0].material = cyl->material;
	ft_scale_vector(cyl->caps[0].orientation, (double *)cyl->orientation, -1.0);
	ft_addition(cyl->caps[0].point, (double *)cyl->point, \
		ft_scale_vector(cyl->caps[0].point, \
			(double *)cyl->orientation, -cyl->half_height));
	cyl->caps[1].ft = FT_PLANE;
	cyl->caps[1].material = cyl->material;
	ft_copy_vector(cyl->caps[1].orientation, (double *)cyl->orientation);
	ft_addition(cyl->caps[1].point, (double *)cyl->point, \
		ft_scale_vector(cyl->caps[1].point, \
			(double *)cyl->orientation, cyl->half_height));
	ft_get_base_ref(cyl->base, (double *)cyl->orientation);
}

void	ft_cone_precomputer(void *figure)
{
	t_cone	*cone;

	cone = (t_cone *)figure;
	cone->cos_theta_sq = cos(cone->theta);
	cone->cos_theta_sq *= cone->cos_theta_sq;
	cone->tan_theta = tan(cone->theta);
	cone->caps[0].ft = FT_PLANE;
	cone->caps[0].material = cone->material;
	ft_scale_vector(cone->caps[0].orientation, \
						(double *)cone->orientation, -1.0);
	ft_addition(cone->caps[0].point, (double *)cone->point, \
		ft_scale_vector(cone->caps[0].point, \
			(double *)cone->orientation, cone->heights[0]));
	cone->caps[1].ft = FT_PLANE;
	cone->caps[1].material = cone->material;
	ft_copy_vector(cone->caps[1].orientation, (double *)cone->orientation);
	ft_addition(cone->caps[1].point, (double *)cone->point, \
		ft_scale_vector(cone->caps[1].point, \
			(double *)cone->orientation, cone->heights[1]));
	ft_get_base_ref(cone->base, (double *)cone->orientation);
}

void	ft_precompute_figure(unsigned int ui, void *fig, void *arg)
{
	t_minirt_data	*minirt;
	t_figure_type	ft;

	(void)ui;
	ft = *(t_figure_type *)fig;
	minirt = (t_minirt_data *)arg;
	if (minirt->precomputer[ft])
		minirt->precomputer[ft](fig);
}
