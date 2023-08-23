/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:53:46 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/23 17:52:41 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	check_object(t_minirt_data *minirt, t_list *node, 
							t_minirt_type mrtt)
{
	if (!node || !minirt)
		return (ft_log_error("Either miniRT data or node missed\n"));
	if (mrtt == MRT_AMBIENT && minirt->ambient.count == 1)
		return (ft_log_error("Ambient light must be only once\n"));
	else if (mrtt == MRT_CAMERA && minirt->camera.count == 1)
		return (ft_log_error("Camera must be only once\n"));
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
	if (mrtt != MRT_LIGHT)
		ft_lstdelone(node, free);
	return (1);
}

t_minirt_data	*minirt_constructor(char *filename)
{
	t_minirt_data	*minirt;

	minirt = ft_calloc(sizeof(t_minirt_data), 1);
	if (minirt)
	{
		minirt->exit_cmd = 0;
		minirt->filename = filename;
		minirt->gr_ctx = NULL;
		minirt->intersect[FT_SPHERE] = inter_sphere_line;
		minirt->intersect[FT_PLANE] = inter_plane_line;
		minirt->intersect[FT_CYLINDER] = inter_cyl_line;
		minirt->intersect[FT_CONE] = inter_cone_line;
		minirt = ft_init_minirt_data(minirt);
	}
	else
		ft_log_error("Malloc failed while constructing minirt\n");
	return (minirt);
}

t_minirt_data	*minirt_dispose(t_minirt_data **minirt)
{
	t_minirt_data	*g;

	if (! minirt || ! *minirt)
		return (*minirt);
	g = *minirt;
	ft_lstclear(&g->list, &free);
	ft_lstclear(&g->figures, &free);
	ft_lstclear(&g->lights, &free);
	ft_dispose_graph_ctx(g);
	free_x((void **)minirt);
	exit (0);
	return (g);
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
	if (mrtt == MRT_INVALID || ! ft_create_graph_ctx(minirt))
		return (minirt_dispose(&minirt));
	return (minirt);
}
