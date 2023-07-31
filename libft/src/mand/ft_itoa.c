/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:34:20 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 13:09:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mand.h"

static char	ft_get_last_digit(unsigned int *n, unsigned int base)
{
	char	ls;

	ls = *n % base;
	*n = *n / base;
	return (ls);
}

static size_t	ft_utobuf(unsigned int nb, char *buf)
{
	unsigned int	restant_digits;
	size_t			ret;
	char			digit;

	ret = 0;
	restant_digits = nb;
	digit = '0' + ft_get_last_digit(&restant_digits, 10);
	if (restant_digits > 0)
		ret = ft_utobuf(restant_digits, buf);
	buf[ret] = digit;
	return (ret + 1);
}

char	*ft_itoa(int n)
{
	char		neg;
	long int	aux;
	size_t		len;
	char		buf[12];
	char		*p;

	p = buf;
	neg = (n < 0);
	aux = (long int) n;
	if (neg)
	{
		aux = -aux;
		buf[0] = '-';
		p++;
	}
	len = ft_utobuf ((unsigned int)aux, p);
	p[len] = 0;
	return (ft_strdup(buf));
}
