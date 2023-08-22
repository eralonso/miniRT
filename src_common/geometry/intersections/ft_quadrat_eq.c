/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrat_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:00:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/22 12:16:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_quadrat_eq(double coef[3], int sign)
{
	double	disc;
	double	dsign;
	double	roots[2];

	if (fabs(coef[0]) < 1.0e-10)
		return (-0.5 * coef[2] / coef[1]);
	dsign = 1.0 * sign;
	dsign /= fabs(dsign);
	disc = (coef[1] * coef[1] - coef[0] * coef[2]);
	if (disc < 0)
		return (INFINITY); 
	roots[0] = (-coef[1] - sqrt(disc)) / coef[0];
	roots[1] = (-coef[1] + sqrt(disc)) / coef[0];
	if (roots[0] < roots[1] && sign > 0)
		return (roots[0]);
	return (roots[1]);
}
