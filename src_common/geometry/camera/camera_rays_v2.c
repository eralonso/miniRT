/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 15:11:14 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

static void	origin_configure(t_camera *cam, t_vector origin, int size[2])
{
	t_vector		trash;

	(void)size;
	ft_addition(origin, cam->point, ft_scale_vector(trash, \
		cam->orientation, cam->focal_dis));
	ft_substraction(origin, origin, ft_scale_vector(trash, \
		cam->horizontal, (size[W] - 1.0) / 2.0));
	ft_substraction(origin, origin, ft_scale_vector(trash, \
		cam->vertical, (size[H] - 1.0) / 2.0));
}

static void	camera_configure(t_camera *cam, int width)
{
	t_vector	main_axis;

	if (fabs(ft_dot_product(ft_vector_fill_unitary(main_axis, 2), \
			cam->orientation)) < 0.95)
		ft_cross_product(cam->horizontal, cam->orientation, main_axis);
	else
		ft_cross_product(cam->horizontal, cam->orientation,
			ft_vector_fill_unitary(main_axis, 1));
	ft_normalize(cam->horizontal, cam->horizontal);
	cam->focal_dis = ((width - 1.0) / 2.0) / tan(cam->fov / 2);
	ft_cross_product(cam->vertical, cam->orientation, cam->horizontal);
	ft_normalize(cam->vertical, cam->vertical);
}

static void	ft_make_ray(t_camera *cam, t_vector origin, \
							t_line *ray, int iter[2])
{
	t_vector		pixel;
	t_vector		trash;

	ft_copy_vector(pixel, origin);
	ft_addition(pixel, pixel, ft_scale_vector(trash, \
		cam->horizontal, iter[W]));
	ft_addition(pixel, pixel, ft_scale_vector(trash, \
		cam->vertical, iter[H]));
	ft_substraction(ray->orientation, pixel, ray->point);
	ft_normalize(ray->orientation, ray->orientation);
}

void	camera_rays_v2(t_minirt_data *minirt, t_camera *cam, \
						t_img *img, int size[2])
{
	t_vector		origin;
	t_line			ray;
	int				iter[2];

	camera_configure(cam, size[W]);
	origin_configure(cam, origin, size);
	ft_copy_vector(ray.point, cam->point);
	iter[H] = -1;
	while (++iter[H] < size[H])
	{
		iter[W] = -1;
		while (++iter[W] < size[W])
		{
			ft_make_ray(cam, origin, &ray, iter);
			minirt->eye_ray = ray;
			ft_pixel_put(img, iter[W], iter[H], \
				raytrace(minirt, ray, minirt->camera.reflec_depth));
		}
	}
}
