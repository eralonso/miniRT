/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:03 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/08 12:29:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

void	ft_copy_pos(int *dst, int *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

int	*ft_dup_pos(int *src)
{
	int	*dst;

	dst = malloc(2 * sizeof(int));
	if (dst)
		ft_copy_pos(dst, src);
	return (dst);
}

void	ft_set_pos(int *pos, int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

void	ft_add_pos(int *pos, int *displ)
{
	pos[0] += displ[0];
	pos[1] += displ[1];
}
