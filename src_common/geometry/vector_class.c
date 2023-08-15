/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:17:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/15 13:17:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "geometry.h"

double	*ft_vector_create(t_vector v)
{
	int		i;
	double	*nv;

	nv = malloc(3 * sizeof(double));
	if (!nv)
		return (nv);
	i = 0;
	while (i < 3)
	{
		nv[i] = v[i];
		i++;
	}
	return (nv);
}

double	*ft_vector_fill_unitary(t_vector v, int axis)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (i == axis)
			v[i] = 1.0;
		else
			v[i] = 0.0;
		i++;
	}
	return (v);
}

double	*ft_vector_unitary(int axis)
{
	double	*nv;

	nv = malloc(3 * sizeof(double));
	if (!nv)
		return (nv);
	return (ft_vector_fill_unitary(nv, axis));
}

double	*ft_vector_dispose(t_vector v)
{
	if (!v)
		return (NULL);
	free(v);
	return (NULL);
}
