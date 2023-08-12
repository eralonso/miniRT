/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/12 19:31:45 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static void	origin_configure(t_camera *cam, t_vector origin, int size[2])
{
	t_vector		trash;

	ft_addition(origin, cam->point, ft_scale_vector(trash, \
		cam->orientation, cam->focal_dis));
	ft_substraction(origin, origin, ft_scale_vector(trash, \
		cam->horizontal, (size[0] - 1.0) / 2.0));
	ft_substraction(origin, origin, ft_scale_vector(trash, \
		cam->vertical, (size[1] - 1.0) / 2.0));
}

static void	camera_configure(t_camera *cam, int width)
{
	t_vector	z_axis;

	z_axis[0] = 0;
	z_axis[1] = 0;
	z_axis[2] = 1;
	cam->focal_dis = ((width - 1.0) / 2.0) / tan(cam->fov / 2);
	ft_cross_product(cam->horizontal, cam->orientation, z_axis);
	ft_normalize(cam->horizontal, cam->horizontal);
	ft_cross_product(cam->vertical, cam->orientation, cam->horizontal);
	ft_normalize(cam->vertical, cam->vertical);
}

void	camera_rays_v2(t_minirt_data *minirt, t_camera *cam, \
						t_img *img, int size[2])
{
	t_vector		origin;
	t_vector		pixel;
	t_vector		trash;
	t_line			ray;
	int				iter[2];

	camera_configure(cam, size[W]);
	origin_configure(cam, origin, size);
	// printf("cam->point[0]: %f && cam->point[1]: %f && cam->point[2]: %f\n", cam->point[0], cam->point[1], cam->point[2]);
	// printf("cam->orientation[0]: %f && cam->orientation[1]: %f && cam->orientation[2]: %f\n", cam->orientation[0], cam->orientation[1], cam->orientation[2]);
	// printf("origin[0]: %f && origin[1]: %f && origin[2]: %f\n", origin[0], origin[1], origin[2]);
	ft_copy_vector(ray.point, cam->point);
	iter[H] = -1;
	while (++iter[H] < size[H])
	{
		iter[W] = -1;
		while (++iter[W] < size[W])
		{
			ft_copy_vector(pixel, origin);
			// printf("pixel[0]: %f && pixel[1]: %f && pixel[2]: %f", pixel[0], pixel[1], pixel[2]);
			ft_addition(pixel, pixel, ft_scale_vector(trash, \
				cam->horizontal, iter[W]));
			ft_addition(pixel, pixel, ft_scale_vector(trash, \
				cam->vertical, iter[H]));
			ft_substraction(ray.orientation, pixel, ray.point);
			ft_normalize(ray.orientation, ray.orientation);
			// printf("ray.orientation[0]: %f && ray.orientation[1]: %f && ray.orientation[2]: %f\n", ray.orientation[0], ray.orientation[1], ray.orientation[2]);
			// printf("iter[H]: %i && iter[W]: %i\n", iter[H], iter[W]);
			ft_pixel_put(img, iter[W], iter[H], raytrace(minirt, ray));
		}
	}
}
