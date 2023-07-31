/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:48:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 18:55:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdlib.h>

static double	ft_pow(double base, int exp)
{
	int		i;
	int		exp_sign;
	double	res;

	res = 1.0;
	if (exp == 0)
		return (res);
	exp_sign = 1;
	if (exp < 0)
		exp_sign = -1;
	i = exp * exp_sign;
	while (i > 0)
	{
		res *= base;
		i--;
	}
	if (exp_sign == -1)
		res = 1.0 / res;
	return (res);
}

static int	ft_check_sign(const char *str, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		return (1);
	}
	if (*str == '+')
		return (1);
	return (0);
}

static double	ft_get_exponent(const char *str)
{
	int	exponent;
	int	exponent_sign;

	exponent = 0;
	exponent_sign = 1;
	if (*str != 'e' && *str != 'E')
		return (1);
	str++;
	str += ft_check_sign(str, &exponent_sign);
	while (ft_isdigit(*str))
	{
		exponent = exponent * 10 + (*str - '0');
		str++;
	}
	return (ft_pow(10.0, exponent * exponent_sign));
}

double	ft_strtod(const char *str)
{
	double	result;
	int		sign;
	double	divisor;

	result = 0.0;
	sign = 1;
	divisor = 10.0;
	while (ft_isspace(*str))
		str++;
	str += ft_check_sign(str, &sign);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		while (*(++str) && ft_isdigit(*str))
		{
			result += (*str - '0') / divisor;
			divisor *= 10.0;
		}
	}
	return (sign * (result * ft_get_exponent(str)));
}
