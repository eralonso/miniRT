/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/27 18:53:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isdouble(char *str, double *ret)
{
	int		i;
	int		dot;
	double	value;

	value = ft_strtod(str);
	if (!str || (ft_strchr("+-", str[0]) && ft_strchr("+-", str[1])))
		return (0);
	i = -1;
	if (ft_strchr("+-", str[0]))
		i++;
	if (!str[i])
		return (0);
	dot = 0;
	while (str[++i])
	{
		if (!dot && str[i] == '.')
			dot++;
		else if (dot && str[i] == '.')
			return (0);
		else if (!ft_isdigit(str[i]))
			return (0);
	}
	if (ret)
		*ret = value;
	return (1);
}
