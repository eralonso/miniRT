/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:27:22 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/11 11:29:07 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../common.h"

double	*ft_copy_vector(t_vector dst, t_vector src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	return (dst);
}
