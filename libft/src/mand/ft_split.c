/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:29:23 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:13:27 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

static size_t	ft_str_count(char const *s, char c)
{
	char	*p;
	size_t	count;
	int		in_str;

	p = (char *)s;
	count = 0;
	in_str = 0;
	while (*p)
	{
		if (!in_str && *p != c)
		{
			count++;
			in_str = 1;
		}
		else if (in_str && *p == c)
		{
			in_str = 0;
		}
		p++;
	}
	return (count);
}

static char	*ft_next_substr(const char *s, char c, size_t *index)
{
	size_t	start;
	size_t	size;

	while (s[*index] && s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
		(*index)++;
	size = *index - start;
	(*index)++;
	return (ft_substr(s, start, size));
}

static void	ft_free_array(void **s_arr, size_t n)
{
	char	**p;
	char	**pe;

	if (s_arr)
	{
		p = (char **)s_arr;
		pe = p + n;
		while (p < pe)
		{
			if (*p)
				free((void *)*p);
			*p = NULL;
			p++;
		}
		free(s_arr);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**sl;
	size_t	count;
	size_t	index;
	size_t	i;

	count = ft_str_count(s, c);
	index = 0;
	sl = (char **) ft_calloc(count + 1, sizeof(char *));
	if (sl)
	{
		sl[count] = NULL;
		i = 0;
		while (i < count)
		{
			sl[i] = ft_next_substr(s, c, &index);
			if (! sl[i])
			{
				ft_free_array((void **)sl, count);
				return (NULL);
			}
			i++;
		}
		return (sl);
	}
	return (NULL);
}
