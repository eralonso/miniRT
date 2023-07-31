/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:58:24 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/24 10:46:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

int	ft_lstevery(t_list *lst, int (*f)(void *, void *), void *arg)
{
	t_list	*cur;
	int		ok;

	cur = lst;
	ok = 1;
	if (f)
	{
		while (cur && ok)
		{
			ok = (*f)((void *)cur->content, arg);
			cur = cur->next;
		}
	}
	return (ok);
}
