/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_materials.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:56:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 18:16:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_grab_materials(t_minirt_data *minirt)
{
	int		i;
	t_list	*lst;

	lst = minirt->materials_list;
	minirt->mat_count = ft_lstsize(lst);
	if (minirt->mat_count > 254)
		return (ft_log_error(ERR_MATERIAL_TABLE_OVERFLOW));
	minirt->mat_table = ft_calloc(minirt->mat_count + 1, sizeof(t_material *));
	if (!minirt->mat_table)
		return (ft_log_error(ERR_MATERIAL_TABLE_MALLOC_FAILED));
	minirt->mat_table[minirt->mat_count] = NULL;
	i = 0;
	while (i < minirt->mat_count)
	{
		minirt->mat_table[i] = (t_material *)lst->content;
		i++;
	}
	return (1);
}
