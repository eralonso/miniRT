/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islight_ratio.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/04 18:09:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_islight_ratio(char *str, double *light)
{
	if (!ft_isdouble(str, light))
		return (0);
	if (*light < 0 || *light > 1)
		return (ft_log_error(ISLIGHT_RATIO_NIR));
	return (1);
}
