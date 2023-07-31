/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:09:22 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:10:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	char	*pe;

	p = (char *)b;
	pe = p + len;
	while (p < pe)
	{
		*p = c;
		p++;
	}
	return (b);
}
