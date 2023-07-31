/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:55:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/29 14:02:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "../common.h"

float	ft_inv_sqrt(float value);
double	ft_distance_sq(t_vector a, t_vector b);
double	ft_distance(t_vector a, t_vector b);

#endif