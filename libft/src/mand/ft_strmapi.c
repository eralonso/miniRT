/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:41:24 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:12:31 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*buf;

	if (! s || ! f)
		return (0);
	len = ft_strlen(s);
	buf = (char *)malloc(len + 1);
	if (!buf)
		return (0);
	i = 0;
	while (i < len)
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
