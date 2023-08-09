/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:58:14 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/04 18:07:37 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

int	ft_isfov(char *str, double *fov)
{
	if (!ft_isdouble(str, fov))
		return (0);
	if (*fov < 0 || *fov > 180)
		return (ft_log_error(ISFOV_NIR));
	*fov = (*fov * M_PI) / 180;
	return (1);
}
