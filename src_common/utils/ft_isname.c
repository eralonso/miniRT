/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:30:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 17:33:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_isname(char *str, char **ret)
{
	*ret = ft_strdup(str);
	if (!ret)
		ft_log_error(ISSTRING_DUPERR);
	return (1);
}
