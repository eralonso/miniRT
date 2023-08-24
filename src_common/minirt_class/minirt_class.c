/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:53:46 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 19:41:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_check_missing(t_minirt_data *minirt)
{
	if (minirt->ambient.count == 0)
	{
		ft_log_error(ERR_MISSING_AMBIENT_LIGHT);
		minirt = minirt_dispose(&minirt);
	}
	if (minirt->camera.count == 0)
	{
		ft_log_error(ERR_MISSING_CAMERA);
		minirt = minirt_dispose(&minirt);
	}
	if (!minirt->lights)
	{
		ft_log_error(ERR_MISSING_LIGHTS);
		minirt = minirt_dispose(&minirt);
	}

}

t_minirt_data	*minirt_constructor(char *filename)
{
	t_minirt_data	*minirt;

	minirt = ft_calloc(sizeof(t_minirt_data), 1);
	if (minirt)
	{
		minirt->filename = filename;
		minirt->intersect[FT_SPHERE] = inter_sphere_line;
		minirt->intersect[FT_PLANE] = inter_plane_line;
		minirt->intersect[FT_CYLINDER] = inter_cyl_line;
		minirt->intersect[FT_CONE] = inter_cone_line;
		minirt = ft_init_minirt_data(minirt);
		// if (!ft_grab_materials(minirt))
		// 	return (0);
		ft_check_missing(minirt);
	}
	else
		ft_log_error(ERR_MINIRT_MALLOC_FAILED);
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
	ft_lstclear(&g->materials_list, &ft_free_material);
	// if (g->mat_table)
	// 	free_x ((void **)&g->mat_table);
	ft_dispose_graph_ctx(g);
	free_x((void **)minirt);
	exit (0);
	return (g);
}

