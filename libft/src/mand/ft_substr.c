/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:04:10 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:12:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*ss;
	size_t	s_len;
	size_t	ss_len;

	s_len = ft_strlen(s);
	p = (char *)s + start;
	ss_len = s_len - start;
	if (ss_len > len)
		ss_len = len;
	if (start >= s_len)
	{
		p = (char *)s + s_len;
		ss_len = 0;
	}
	ss = malloc(ss_len + 1);
	if (ss)
	{
		ft_memcpy(ss, p, ss_len);
		ss[ss_len] = 0;
	}
	return (ss);
}
