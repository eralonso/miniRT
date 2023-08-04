/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:43:43 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/04 13:03:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	*ft_normalize(t_vector res, t_vector a)
{
	double	length;

	length = ft_module(a);
	return (ft_scale_vector(res, a, 1 / length));
}
