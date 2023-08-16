/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrat_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:00:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/16 13:00:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_quadrat_eq(double coef[3])
{
	double	disc;

	disc = (coef[1] * coef[1] - coef[0] * coef[2]);
	if (disc < 0)
		return (INFINITY); 
	return ((-coef[1] - sqrt(disc)) / coef[0]);
}