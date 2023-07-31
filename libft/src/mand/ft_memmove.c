/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:14:55 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:10:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

static void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char	*pd;
	char	*ps;
	char	*pb;

	if (dst != src)
	{
		pd = (char *)dst;
		ps = (char *)src;
		pb = ps;
		pd += (n - 1);
		ps += (n - 1);
		while (ps >= pb)
		{
			*pd = *ps;
			pd--;
			ps--;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;
	char	*src_c;

	dst_c = (char *)dst;
	src_c = (char *)src;
	if (dst_c < src_c)
		ft_memcpy(dst, src, len);
	else if (dst_c > src_c)
		ft_memcpy_rev(dst, src, len);
	return (dst);
}
