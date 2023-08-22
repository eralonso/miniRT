/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isratio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/22 16:18:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isratio(char *str, double *light)
{
	if (!ft_isdouble(str, light))
		return (0);
	if (*light < 0 || *light > 1)
		return (ft_log_error(ISRATIO_NIR));
	return (1);
}
