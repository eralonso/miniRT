/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minirt_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:04:38 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/28 14:55:22 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	check_object(t_minirt_data *minirt, t_list *node, 
							t_minirt_type mrtt)
{
	if (!node || !minirt)
		return (ft_log_error(ERR_CHECK_OBJECT_MISS_DATA));
	if (mrtt == MRT_AMBIENT && minirt->ambient.count == 1)
		return (ft_log_error(ERR_AMBIENT_LIGHT_REPEATED));
	else if (mrtt == MRT_CAMERA && minirt->camera.count == 1)
		return (ft_log_error(ERR_CAMERA_REPEATED));
	return (1);
}

static int	ft_save_object(t_minirt_data *minirt, t_list *node, 
							t_minirt_type mrtt)
{
	if (check_object(minirt, node, mrtt) == 0)
	{
		ft_lstdelone(node, free);
		return (0);
	}
	if (mrtt == MRT_AMBIENT)
		ft_memcpy(&minirt->ambient, node->content, sizeof(t_ambient));
	else if (mrtt == MRT_CAMERA)
		ft_memcpy(&minirt->camera, node->content, sizeof(t_camera));
	else if (mrtt == MRT_LIGHT)
		ft_lstadd_front(&minirt->lights, node);
	else if (mrtt == MRT_MATERIAL)
		ft_lstadd_front(&minirt->materials_list, node);
	if (mrtt != MRT_LIGHT && mrtt != MRT_MATERIAL)
		ft_lstdelone(node, free);
	return (1);
}

t_minirt_data	*ft_init_minirt_data(t_minirt_data *minirt)
{
	t_list			*node;
	t_minirt_type	mrtt;

	if (! minirt)
		return (minirt);
	minirt->list = ft_read_map(minirt->filename);
	mrtt = MRT_AMBIENT;
	while (minirt->list && mrtt != MRT_INVALID)
	{
		node = ft_lstextract_front(&minirt->list);
		if (node && node->content)
		{
			mrtt = ft_cast_line_object(node);
			if (mrtt == MRT_SPHERE || mrtt == MRT_PLANE || \
				mrtt == MRT_CYLINDER || mrtt == MRT_CONE)
				ft_lstadd_front(&minirt->figures, node);
			else if (ft_save_object(minirt, node, mrtt) == 0)
				return (minirt_dispose(&minirt));
		}
	}
	if (mrtt == MRT_INVALID || ! ft_create_graph_ctx(minirt)
		|| !ft_create_background(minirt))
		return (minirt_dispose(&minirt));
	return (minirt);
}
