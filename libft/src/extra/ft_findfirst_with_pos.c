/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findfirst_with_pos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:06:22 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/23 17:05:48 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

static int	eq_pos(unsigned int i, void *content, void *arg)
{
	int	*pos;
	int	*content_pos;

	(void)i;
	pos = arg;
	content_pos = content;
	return (pos[0] == content_pos[0] && pos[1] == content_pos[1]);
}

t_list	*ft_findfirst_with_pos(t_list *lst, int *pos)
{
	return (ft_lstfindfirst(lst, &eq_pos, pos));
}
