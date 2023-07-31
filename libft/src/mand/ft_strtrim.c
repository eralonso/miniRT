/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:02:54 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:12:08 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	start;
	size_t	len;
	size_t	ss_len;

	start = 0;
	len = ft_strlen(s1);
	if (len > 0)
	{
		while (start < len && ft_strchr(set, s1[start]))
			start++;
		while (len > start && ft_strchr(set, s1[len - 1]))
			len--;
	}
	ss_len = len - start;
	buf = malloc(ss_len + 1);
	if (buf)
	{
		if (ss_len > 0)
			ft_memcpy(buf, s1 + start, ss_len);
		buf[ss_len] = 0;
	}
	return (buf);
}
