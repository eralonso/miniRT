/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:35:56 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 13:45:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

static int	ft_take_sign(char **p)
{
	int	sign;

	sign = 1;
	if (**p == '+')
		(*p)++;
	else if (**p == '-')
	{
		(*p)++;
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		s;
	char	*p;

	p = (char *)str;
	ret = 0;
	while (*p && ft_isspace(*p))
		p++;
	s = ft_take_sign(&p);
	while (*p && ft_isdigit(*p))
	{
		ret *= 10;
		ret += *p - '0';
		p++;
	}
	ret *= s;
	return (ret);
}
