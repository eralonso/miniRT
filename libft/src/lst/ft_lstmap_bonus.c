/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:56:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/24 10:47:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static t_list	*ft_applyftonode(t_list *curnode, void *(*f)(void *), \
	void (*del)(void *))
{
	t_list	*newnode;
	void	*newcontent;

	if (! curnode || ! f)
		return (0);
	newcontent = (*f)(curnode->content);
	if (! newcontent)
		return (0);
	newnode = ft_lstnew(newcontent);
	if (! newnode)
	{
		(*del)(newcontent);
		return (0);
	}
	return (newnode);
}

static t_list	*ft_appendnewnode(t_list *newnode, t_list *newlistlast, \
	t_list **newlist)
{
	if (! newnode || ! newlist)
		return (0);
	if (! *newlist)
		*newlist = newnode;
	else if (newlistlast)
		newlistlast->next = newnode;
	else
	{
		newlistlast = ft_lstlast(*newlist);
		if (newlistlast)
			newlistlast->next = newnode;
	}
	return (newnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*cur;
	t_list	*curnew;
	t_list	*newnode;

	newlist = 0;
	curnew = 0;
	cur = lst;
	while (cur && (! newlist || curnew))
	{
		newnode = ft_applyftonode(cur, f, del);
		curnew = ft_appendnewnode(newnode, curnew, &newlist);
		if (!curnew && !newlist)
			return (0);
		cur = cur->next;
	}
	if (! curnew && newlist)
		ft_lstclear(&newlist, del);
	return (newlist);
}
