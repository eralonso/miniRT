/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:55:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 11:58:24 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "../common.h"

float	ft_inv_sqrt(float value);
double	*ft_scale_vector(t_vector res, t_vector a, double s);
double	*ft_substraction(t_vector res, t_vector a, t_vector b);
double	*ft_addition(t_vector res, t_vector a, t_vector b);
double	ft_distance_sq(t_vector a, t_vector b);
double	ft_distance(t_vector a, t_vector b);
double	ft_module(t_vector a);
double	*ft_normalize(t_vector res, t_vector a);

#endif