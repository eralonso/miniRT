/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isratio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/22 17:41:15 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isratio(char *str, double *value)
{
	if (!ft_isdouble(str, value))
		return (0);
	if (*value < 0 || *value > 1)
		return (ft_log_error(ISRATIO_NIR));
	return (1);
}
