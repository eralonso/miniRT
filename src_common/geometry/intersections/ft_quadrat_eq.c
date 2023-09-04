/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrat_eq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:00:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/04 16:11:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

// static double	*ft_sort_roots(double *roots)
// {
// 	double	aux;

// 	if (roots[0] <= roots[1])
// 		return (roots);
// 	aux = roots[0];
// 	roots[0] = roots[1];
// 	roots[1] = aux;
// 	return (roots);
// }

double	*ft_quadrat_eq2(double coef[3], double roots[2])
{
	double	disc;
	double	sqrt_disc;

	roots[0] = INFINITY;
	roots[1] = INFINITY;
	if (fabs(coef[0]) < 1.0e-10)
	{
		roots[0] = -0.5 * coef[2] / coef[1];
		roots[1] = roots[0];
		return (roots);
	}
	disc = (coef[1] * coef[1] - coef[0] * coef[2]);
	if (disc < 0)
		return (roots);
	sqrt_disc = sqrt(disc);
	roots[0] = (-coef[1] - sqrt_disc) / coef[0];
	roots[1] = (-coef[1] + sqrt_disc) / coef[0];
	return (roots);
}

int	ft_take_min_pos_root(double *pos_root, double *roots)
{
	*pos_root = roots[0];
	if (*pos_root == INFINITY)
		return (0);
	if (*pos_root < 0.0)
		*pos_root = roots[1];
	if (*pos_root < 0.0)
		return (0);
	return (1);
}

int	ft_take_max_pos_root(double *pos_root, double *roots)
{
	*pos_root = roots[1];
	if (*pos_root == INFINITY)
		return (0);
	if (*pos_root < 0.0)
		*pos_root = roots[0];
	if (*pos_root < 0.0)
		return (0);
	return (1);
}

double	ft_quadrat_eq(double coef[3], int sign)
{
	double	disc;
	double	sqrt_disc;
	double	roots[2];

	if (fabs(coef[0]) < 1.0e-10)
		return (-0.5 * coef[2] / coef[1]);
	disc = (coef[1] * coef[1] - coef[0] * coef[2]);
	if (disc < 0)
		return (INFINITY);
	sqrt_disc = sqrt(disc);
	roots[0] = (-coef[1] - sqrt_disc) / coef[0];
	roots[1] = (-coef[1] + sqrt_disc) / coef[0];
	if (roots[0] < roots[1] && sign > 0)
		return (roots[0]);
	return (roots[1]);
}
