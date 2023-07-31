/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrreduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:09:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/24 10:45:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

void	ft_lstreduce(t_list *lst, \
		void (*f)(unsigned int, void *, void *), void *arg)
{
	t_list			*cur;
	unsigned int	i;

	cur = lst;
	i = 0;
	if (f && arg)
	{
		while (cur)
		{
			(*f)(i, (void *)cur->content, arg);
			cur = cur->next;
			i++;
		}
	}
}
