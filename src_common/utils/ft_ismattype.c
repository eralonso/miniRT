/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismattype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:30:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 16:56:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"

int	ft_ismattype(char *str, t_material_type *ret)
{
	const size_t			len = ft_strlen_x(str);
	const char				*type_str_id[2] = {"HOMOG", "CHESS"};
	const t_material_type	type_id[2] = {MTT_HOMOG, MTT_CHESS};
	int						i;

	if (len < 5)
		ft_log_error(ISMATTYPE_INVALID);
	i = 0;
	while (i < 2)
	{
		if (ft_strncmp(str, type_str_id[i], 5))
		{
			*ret = type_id[i];
			return (1);
		}
		i++;
	}
	return (0);
}
