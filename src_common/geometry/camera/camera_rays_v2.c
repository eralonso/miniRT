/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/11 19:36:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

void	camera_rays_v2(t_minirt_data *minirt, t_camera *cam, int size[2])
{
	const double	half_width = (size[0] - 1.0) / 2.0;
	const double	half_height = (size[1] - 1.0) / 2.0;
	const double	focal_dis = half_width / tan(cam->fov / 2);
	t_vector		z_axis = {0, 0, 1};
	t_vector		origin;
	t_vector		pixel;
	t_vector		horizontal;
	t_vector		vertical;
	t_vector		trash;
	t_line			ray;
	int				i;
	int				j;

	ft_cross_product(horizontal, cam->orientation, z_axis);
	ft_normalize(horizontal, horizontal);
	ft_cross_product(vertical, cam->orientation, horizontal);
	ft_normalize(vertical, vertical);
	ft_scale_vector(ray->orientation, cam->orientation, focal_dis);
	ft_addition(origin, cam->point, ft_scale_vector(trash, \
		cam->orientation, focal_dis));
	ft_substraction(origin, origin, ft_scale_vector(trash, horizontal, half_width));
	ft_substraction(origin, origin, ft_scale_vector(trash, vertical, half_height));
	ft_copy_vector(ray->point, cam->point);
	j = -1;
	while (++j < size[H])
	{
		i = -1;
		while (++i < size[W])
		{
			ft_copy_vector(pixel, origin);
			ft_addition(pixel, pixel, ft_scale_vector(trash, horizontal, i));
			ft_addition(pixel, pixel, ft_scale_vector(trash, vertical, j));
			ft_substraction(ray->orientation, pixel, ray->point);
			ft_normalize(ray->orientation, ray->orientation);
			ft_pixel_put(&minirt->gr_ctx->img, i, j, raytrace(minirt, ray));
		}
	}
}
