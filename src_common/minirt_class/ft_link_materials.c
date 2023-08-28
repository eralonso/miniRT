/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_materials.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:38:05 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 13:17:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_link(unsigned int ui, void *figure, void *data)
{
	t_minirt_data	*minirt;

	(void)ui;
	minirt = data;
	if (!ft_link_figure_material(figure, minirt->materials_list))
		minirt->mat_link_nok = 1;
}

int	ft_link_materials(t_minirt_data *minirt)
{
	ft_lstreduce(minirt->figures, ft_link, minirt);
	if (minirt->mat_link_nok)
		ft_log_error("Linking materials failed\n");
	return (!minirt->mat_link_nok);
}
