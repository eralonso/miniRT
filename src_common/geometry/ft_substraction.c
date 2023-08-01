/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:59 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 11:57:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double	*ft_substraction(t_vector res, t_vector a, t_vector b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		res[i] = a[i] - b[i];
		i++;
	}
	return (res);
}
