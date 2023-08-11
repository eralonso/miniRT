/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/11 13:50:20 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

void	camera_rays_v2(t_camera *cam, int size[2])
{
	const double	half_width = (size[0] - 1.0) / 2.0;
	const double	half_height = (size[1] - 1.0) / 2.0;
	const double	focal_dis = half_width / tan(cam->fov / 2);
	t_vector		z_axis = {0, 0, 1};
	t_vector		first_pixel;
	t_vector		horizontal;
	t_vector		vertical;
	t_vector		view_h;
	t_vector		view_v;
	t_vector		ix;
	t_vector		iy;
	int				i;
	int				j;
	t_line			ray;

	ft_cross_product(horizontal, cam->orientation, z_axis);
	ft_normalize(horizontal, horizontal);
	ft_cross_product(vertical, cam->orientation, horizontal);
	ft_normalize(vertical, vertical);
	ft_scale_vector(ray->orientation, cam->orientation, focal_dis);
	ft_addition(first_pixel, cam->point, ft_scale_vector(ray->point, \
		cam->orientation, focal_dis));
	ft_copy_vector(ray->point, cam->point);
	j = 0;
	while (j < size[1])
	{
		i = 0;
		while (i < size[0])
		{
			ft_substraction(ray->orientation, , ray->point);
			ft_scale_vector(aux, horizontal, i - half_width);
			ft_normalize(ray->orientation, ray->orientation);
			i++;
		}
		j++;
	}
}
