/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:17:06 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/01 18:45:09 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

double	ft_limit_cyl_height(double height, const t_cylinder *cyl)
{
	const double	min_height = -0.999 * cyl->height / 2.0;
	const double	max_height = 0.999 * cyl->height / 2.0;

	if (height < min_height)
		return (min_height);
	if (height > max_height)
		return (max_height);
	return (height);
}

double	ft_limit_cone_height(double height, const t_cone *cone)
{
	const double	min_height = 1.001 * cone->heights[0];
	const double	max_height = 0.999 * cone->heights[1];

	if (height < min_height)
		return (min_height);
	if (height > max_height)
		return (max_height);
	return (height);
}
