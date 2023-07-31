/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:12:32 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:12:50 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_index;
	size_t	d_index;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d_index = ft_strlen(dst);
	s_index = 0;
	while (src[s_index] && (d_index + 1) < dstsize)
	{
		dst[d_index] = src[s_index];
		s_index++;
		d_index++;
	}
	dst[d_index] = '\0';
	return (ft_strlen(dst) + ft_strlen(src + s_index));
}
