/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:10 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/09 17:24:23 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incclude <math.h>
#include "../../common.h"


t_list *camera_rays(t_camera *cam, int size[2])
{
	t_list	*ray_list;
	double half_width = (size[0] - 1.0) / 2.0;
	double half_height = (size[1]- 1.0) / 2.0;
	double focal_dis = half_width / tan(cam->fov / 2);
	t_vector z_axis = {0, 0, 1};
	t_vector horizontal;
	t_vector vertical;
	int i;
	int j;
	t_vector aux;
	t_line *ray;

	ft_cross_product(horizontal, cam->orientation, z_axis);
	ft_normalize(horizontal, horizontal);
	//if necessary reverse order x prod to let the vector be well oriented
	//according to the screen reversed way
	ft_cross_product(vertical, cam->orientation, horizontal);
	ft_normalize(vertical, vertical);
	j = 0;
	while (j < size[1])
	{
		ft_scale_vector(ray, cam->orientation, (double)(size[0] - 1));
		ft_scale_vector(aux, vertical, j - half_height);
		ft_addition(aux, aux, aux);
		i = 0;
		while (i < size[1])
		{
			ray = malloc(t_line);
			ft_scale_vector(ray->point, cam->point, 1.0); //just copy
			ft_scale_vector(ray->orientation, aux, 1.0); //just copy
			ft_scale_vector(aux, horizontal, i - half_width);
			ft_addition(ray->orientation, ray->orientation, aux);
			ft_normalize(ray->orientation, ray->orientation);
			ft_lstadd_front(&ray_list,ft_lstnew(ray));
			i++;
		}
		j++;
	}
	return (ray_list);
}
