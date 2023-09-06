/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base_ref.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:15:16 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 16:27:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../common.h"

void	ft_get_base_ref(t_vector *base, double *orientation)
{
	t_vector	main_axis;

	ft_vector_fill_unitary(main_axis, 2);
	if (fabs(ft_dot_product(orientation, main_axis)) > 0.95)
		ft_vector_fill_unitary(main_axis, 1);
	ft_cross_product(base[0], orientation, main_axis);
	ft_normalize(base[0], base[0]);
	ft_cross_product (base[1], orientation, base[0]);
}
