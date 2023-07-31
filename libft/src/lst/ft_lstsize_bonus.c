/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:12:02 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/21 13:16:54 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cur;

	cur = lst;
	i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}
