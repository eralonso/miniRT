/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:50:55 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/23 16:58:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"
#define BIAS 6e-4

t_line	gen_shadow_ray(t_light *light, \
					t_intersect_data *best, double *dis)
{
	t_line		ray;
	t_vector	trash;

	ft_copy_vector(ray.point, light->point);
	ft_addition(ray.point, ray.point, ft_scale_vector(trash, \
		best->tan_plane.orientation, BIAS));
	ft_substraction(ray.orientation, best->tan_plane.point, \
		light->point);
	if (dis)
		*dis = ft_module(ray.orientation);
	ft_normalize(ray.orientation, ray.orientation);
	return (ray);
}

t_line	gen_reflect_ray(t_line ray, t_intersect_data *hit)
{
	t_line		reflect;
	t_vector	trash;

	ft_copy_vector(reflect.point, hit->tan_plane.point);
	ft_addition(reflect.point, reflect.point, ft_scale_vector(trash, \
		hit->tan_plane.orientation, BIAS));
	ft_substraction(reflect.orientation, ray.orientation, \
		ft_scale_vector(trash, hit->tan_plane.orientation, \
			ft_dot_product(ray.orientation, hit->tan_plane.orientation) * 2));
	return (reflect);
}
