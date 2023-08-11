/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:21:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/09 16:05:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	*ft_matrix_x_vector(t_matrix m, t_vector v)
{
	double	*nv;
	int		i;

	nv = ft_vector_unitary(1);
	i = 0;
	while (i < 3)
	{
		nv[i] = ft_dot_product(m[i], v);
		i++;
	}
	return (nv);
}

static double	ft_row_x_column(t_matrix a, t_matrix b, int i, int j)
{
	int		k;
	double	ret;

	ret = 0.0;
	k = 0;
	while (k < 3)
	{
		ret += (a[i][k] * b[k][j]);
		k++;
	}
	return (ret);
}

double	**ft_matrix_x_matrix(t_matrix a, t_matrix b)
{
	double	**nm;
	int		i;
	int		j;

	nm = ft_matrix_identity();
	if (!nm)
		return (nm);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			nm[i][j] = ft_row_x_column(a, b, i, j);
			j++;
		}
		i++;
	}
	return (nm);
}
