/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:38:36 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/06 16:53:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

char	*ft_str_merge(char **s1, char **s2)
{
	size_t	len[2];
	size_t	tot_len;
	size_t	s1_len_cp;
	char	*buf;

	if (!s1 || !s2)
		return (NULL);
	tot_len = 0;
	s1_len_cp = 0;
	len[0] = ft_strlen_x(*s1);
	len[1] = ft_strlen_x(*s2);
	tot_len = len[0] + len[1];
	buf = (char *)malloc(tot_len + 1);
	if (buf)
	{
		if (len[0] > 0 && *s1)
			s1_len_cp = ft_strncpy_x(buf, *s1, len[0]);
		if (len[1] > 0 && *s2)
			ft_strncpy_x(buf + s1_len_cp, *s2, len[1]);
		free_x((void **)s1);
		free_x((void **)s2);
		return (buf);
	}
	return (0);
}
