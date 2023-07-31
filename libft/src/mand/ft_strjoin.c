/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:22 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:13:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;	
	size_t	s2_len;
	size_t	tot_len;
	char	*buf;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len;
	buf = (char *)malloc(tot_len + 1);
	if (buf)
	{
		ft_memcpy(buf, s1, s1_len);
		ft_memcpy(buf + s1_len, s2, s2_len + 1);
		return (buf);
	}
	return (0);
}
