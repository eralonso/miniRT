/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:26:47 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 12:13:44 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_material_is_id(unsigned int ui, void *content, void *id)
{
	const t_material	*mat = content;

	(void)ui;
	return (!ft_strncmp(mat->name, id, 32));
}

t_material	*ft_find_material(t_list *mats, char *id)
{
	t_list	*loc;

	loc = ft_lstfindfirst(mats, ft_material_is_id, id);
	if (!loc)
		return (NULL);
	return ((t_material *)loc->content);
}
