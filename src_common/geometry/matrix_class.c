/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:17:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 19:31:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "geometry.h"

double	**ft_matrix_create(t_matrix m)
{
	int		i;
	double	**nm;
	int		failed;

	failed = 0;
	nm = malloc(3 * sizeof(double *));
	if (!nm)
		return (nm);
	i = 0;
	while (i < 3)
	{
		if (! failed)
		{
			nm[i] = ft_vector_create(m[i]);
			failed = (nm[i] == NULL);
		}
		else
			nm[i] = NULL;
		i++;
	}
	if (failed)
		return (ft_matrix_dispose(nm));
	return (nm);
}

double	**ft_matrix_identity(void)
{
	int		i;
	double	**nm;
	int		failed;

	failed = 0;
	nm = malloc(3 * sizeof(double *));
	if (!nm)
		return (nm);
	i = 0;
	while (i < 3)
	{
		if (! failed)
		{
			nm[i] = ft_vector_unitary(i);
			failed = (nm[i] == NULL);
		}
		else
			nm[i] = NULL;
		i++;
	}
	if (failed)
		return (ft_matrix_dispose(nm));
	return (nm);
}

double	**ft_matrix_rotation(int axis, double theta)
{
	int		j;
	int		k;
	double	**rot;
	double	sin_theta;
	double	cos_theta;

	if (axis < 0 || axis > 2)
		return (NULL);
	rot = ft_matrix_identity();
	if (!rot)
		return (NULL);
	j = (axis + 1) % 3;
	k = (axis + 2) % 3;
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	rot[j][j] = cos_theta;
	rot[k][k] = cos_theta;
	rot[j][k] = -sin_theta;
	rot[k][j] = sin_theta;
	return (rot);
}

double	**ft_matrix_transpose(t_matrix m)
{
	double	**res;
	double	swap;

	res = ft_matrix_create(m);
	if (!res)
		return (NULL);
	swap = res[0][1];
	res[0][1] = res[1][0];
	res[1][0] = swap;
	swap = res[0][2];
	res[0][2] = res[2][0];
	res[2][0] = swap;
	swap = res[1][2];
	res[1][2] = res[2][1];
	res[2][1] = swap;
	return (res);
}

double	**ft_matrix_dispose(t_matrix m)
{
	int		i;

	if (!m)
		return (m);
	i = 0;
	while (i < 3)
	{
		if (m[i])
			m[i] = ft_vector_dispose(m[i]);
		i++;
	}
	free(m);
	return (NULL);
}
