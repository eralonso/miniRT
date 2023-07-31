/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inv_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:59:46 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/29 14:46:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#define THREEHALFS	1.5F

typedef union u_double_encoding
{
	double		number;
	int64_t		encoding;
}	t_double_encoding;

typedef struct s_inv_sqrt_data
{
	t_double_encoding	t;
	t_double_encoding	y1;
	double				y0;
	int					leading;
	int64_t				biased;
	int64_t				trailing;
	int64_t				e;
	double				adjust;
}	t_inv_sqrt_data;

float	ft_inv_sqrt(float value)
{
	long	i;
	float	x2;
	float	y;

	x2 = value * 0.5F;
	y = value;
	i = *(long *) &y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y *= (THREEHALFS - (x2 * y * y));
	y *= (THREEHALFS - (x2 * y * y));
	return (y);
}

static int	get_leading_bit(int64_t value)
{
	int	v1;
	int	v0;

	v1 = (int)((value >> 32) & 0x00000000FFFFFFFF);
	if (v1 != 0)
		return (get_leading_bit(v1) + 32);
	v0 = (int)(value & 0x00000000FFFFFFFF);
	return (get_leading_bit (v0));
}

// The function call ’t = frexp(x,&e)’ is too expensive to use . It
// has to deal with general floating-point input. The code here takes
// advantage of knowledge about the input.
static void	ft_encode(t_inv_sqrt_data *d, double x)
{
	d->t.number = x;
	d->biased = d->t.encoding & 0x7FF0000000000000LL;
	d->trailing = d->t.encoding & 0x000FFFFFFFFFFFFFLL;
	if (d->biased != 0)
		d->e = (d->biased >> 52) - 1022;
	else
	{
		d->leading = get_leading_bit(d->trailing);
		d->e = d->leading - 1073;
		d->trailing = (d->trailing << (52 - d->leading)) & 0xFFEFFFFFFFFFFFFF;
	}
	d->trailing |= 0x3FE0000000000000LL ;
	d->t.encoding = d->trailing;
}

// The function call ’result = ldexp(y1,e)’ is too expensive to use.
// It has to deal with general floating-point input. The code here
// takes advantage of knowledge about the output: the number y1 is
// guaranteed to be a finite normal floating-point number.
double	inv_sqrt(double x)
{
	t_inv_sqrt_data		d;

	t_encode(&d, x);
	if (d.e & 1)
	{
		d.adjust = 0.7071067811865475;
		++d.e;
	}
	else
		d.adjust = 0.5;
	d.e = - (d.e / 2);
	d.y0 = 1.7875798999734804 - 0.80992000992385993 * d.t.number;
	d.y1.number = d.adjust * d.y0 * (3.0 - d.t.number * d.y0 * d.y0);
	d.y1.encoding += (d.e << 52);
	return (d.y1.number);
}
