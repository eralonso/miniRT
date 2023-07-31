/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeletenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:10:36 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/23 17:06:14 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

static int	ft_eqnode(unsigned int i, t_list *lst, void *lst2)
{
	(void)i;
	return (lst == lst2);
}

void	ft_lstdeletenode(t_list **lst, t_list *node)
{
	ft_lstdeletewhere(lst, &ft_eqnode, &free, node);
}
