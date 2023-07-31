/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:49:28 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/30 10:10:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_x(const char *s)
{
	size_t	i;

	if (! s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strncpy_x(char *dst, const char *src, size_t n)
{
	char	*pd;
	char	*ps;
	char	*pe;

	if (dst != src && dst && src)
	{
		pd = (char *)dst;
		ps = (char *)src;
		pe = ps + n;
		while (*ps && ps < pe)
		{
			*pd = *ps;
			pd++;
			ps++;
		}
		*pd = 0;
		return (ps - (char *)src);
	}
	return (0);
}

char	*ft_strjoin_x(char const *s1, char const *s2, \
	size_t *s1_len, size_t s2_len)
{
	size_t	tot_len;
	size_t	s1_len_cp;
	char	*buf;

	tot_len = 0;
	s1_len_cp = 0;
	if (s1_len && *s1_len)
		tot_len += *s1_len;
	if (s2_len)
		tot_len += s2_len;
	buf = (char *)malloc(tot_len + 1);
	if (buf)
	{
		if (*s1_len > 0 && s1)
			s1_len_cp = ft_strncpy_x(buf, s1, *s1_len);
		if (s2_len > 0 && s2)
			ft_strncpy_x(buf + s1_len_cp, s2, s2_len);
		*s1_len = s1_len_cp + s2_len;
		return (buf);
	}
	return (0);
}

char	*ft_substr_empty2null(char const *s, unsigned int start,
	size_t len, int empty2null)
{
	char	*p;
	char	*ss;
	size_t	s_len;
	size_t	ss_len;

	s_len = ft_strlen_x(s);
	p = (char *)s + start;
	ss_len = s_len - start;
	if (ss_len > len)
		ss_len = len;
	if (start >= s_len)
	{
		p = (char *)s + s_len;
		ss_len = 0;
	}
	ss = NULL;
	if (ss_len > 0 || ! empty2null)
		ss = malloc(ss_len + 1);
	if (ss)
		ft_strncpy_x(ss, p, ss_len);
	return (ss);
}

char	*ft_strnl(const char *s)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != '\n')
		p++;
	if (*p != '\n')
		return (NULL);
	return (p);
}
