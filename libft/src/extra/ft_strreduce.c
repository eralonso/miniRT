/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:46:06 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

void	*ft_strreduce(char *s, void (*f)(unsigned int, char*, void*), \
		void *acum)
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, s + i, acum);
			i++;
		}
	}
	return (acum);
}
