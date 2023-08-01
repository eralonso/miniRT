/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:41:42 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 16:43:47 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	**ft_matrix_add(t_matrix res, t_matrix a, t_matrix b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_addition(res[i], a[i], b[i]);
		i++;
	}
	return (res);
}
