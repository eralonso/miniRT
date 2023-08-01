/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:17:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 18:18:01 by omoreno-         ###   ########.fr       */
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

double	*ft_vector_unitary(int axis)
{
	int		i;
	double	*nv;

	nv = malloc(3 * sizeof(double));
	if (!nv)
		return (nv);
	i = 0;
	while (i < 3)
	{
		if (i == axis)
			nv[i] = 1.0;
		else
			nv[i] = 0.0;
		i++;
	}
	return (nv);
}

double	*ft_vector_dispose(t_vector v)
{
	if (!v)
		return (NULL);
	free(v);
	return (NULL);
}
