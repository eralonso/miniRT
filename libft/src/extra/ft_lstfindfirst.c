/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:46:19 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/24 10:45:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

t_list	*ft_lstfindfirst(t_list *lst, \
		int (*f)(unsigned int, void *, void *), void *arg)
{
	t_list			*cur;
	unsigned int	i;

	cur = lst;
	i = 0;
	if (! f || ! arg)
		return (NULL);
	while (cur)
	{
		if ((*f)(i, (void *)cur->content, arg))
			return (cur);
		cur = cur->next;
		i++;
	}
	return (cur);
}
