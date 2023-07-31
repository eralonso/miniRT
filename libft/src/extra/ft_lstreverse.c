/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:17:49 by omoreno-          #+#    #+#             */
/*   Updated: 2022/12/01 17:45:06 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

t_list	*ft_lstreverse(t_list **lst)
{
	t_list	*next;
	t_list	*rev_list;

	if (! lst || ! *lst)
		return (NULL);
	rev_list = NULL;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->next = NULL;
		ft_lstadd_front(&rev_list, *lst);
		*lst = next;
	}
	return (rev_list);
}
