/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrat_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:00:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/21 17:46:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_quadrat_eq(double coef[3], int sign)
{
	double	disc;
	double	dsign;

	dsign = 1.0 * sign;
	dsign /= fabs(dsign);
	disc = (coef[1] * coef[1] - coef[0] * coef[2]);
	if (disc < 0)
		return (INFINITY); 
	return ((-coef[1] - dsign * sqrt(disc)) / coef[0]);
}
