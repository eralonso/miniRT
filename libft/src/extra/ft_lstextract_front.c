/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextract_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:41:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/25 15:44:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

t_list	*ft_lstextract_front(t_list **lst)
{
	t_list	*node;

	node = NULL;
	if (lst && *lst)
	{
		node = *lst;
		*lst = node->next;
		node->next = NULL;
	}
	return (node);
}
