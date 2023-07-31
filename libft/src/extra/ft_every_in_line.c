/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_every_in_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:04:54 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 17:51:52 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

int	ft_every_in_line(char *s, int (*f)(char, char), char arg)
{
	size_t	i;
	int		ok;

	ok = (s && f);
	i = 0;
	while (ok && s[i] && s[i] != '\n')
		ok = f(s[i++], arg);
	return (ok);
}
