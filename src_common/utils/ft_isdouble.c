/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/31 13:43:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

static int	ft_check_dots(char *str)
{
	int	i;
	int	dot_cnt;
	int	e_cnt;

	i = 0;
	dot_cnt = 0;
	e_cnt = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (e_cnt > 0)
				return (0);
			dot_cnt++;
		}
		if (str[i] == 'e' || str[i] == 'E')
		{
			e_cnt++;
			ft_check_signs(str+i+1, &i);
		}
		if (dot_cnt > 1 || e_cnt > 1)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_signs(char *str, int *i)
{
	if (!str || (ft_strchr("+-", str[0]) && ft_strchr("+-", str[1])))
		return (0);
	if (ft_strchr("+-", str[0]))
		(*i)++;
	return (1);
}

int	ft_isdouble(char *str, double *ret)
{
	int		i;
	double	value;
	int		exp_phase;

	value = ft_strtod(str);
	i = 0;
	if (!ft_check_signs(str, &i) || !ft_check_dots(str))
		return (0);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.' \
			|| str[i] == 'e' || str[i] == 'E' \
			|| str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	if (ret)
		*ret = value;
	return (1);
}
