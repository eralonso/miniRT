/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:35:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/25 13:20:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_create_wnd(t_minirt_data *minirt)
{
	t_graphics	*gr_ctx;

	if (! minirt || ! minirt->gr_ctx)
		return (0);
	gr_ctx = minirt->gr_ctx;
	gr_ctx->wnd = mlx_new_window(gr_ctx->inst, \
		gr_ctx->wnd_size[0], gr_ctx->wnd_size[1], "minirt Wnd");
	if (! gr_ctx->wnd)
	{
		minirt->exit_cmd = 1;
		return (1);
	}
	mlx_hook(gr_ctx->wnd, ON_DESTROY, 0, &ft_close, minirt);
	mlx_key_hook(gr_ctx->wnd, &ft_key_input, minirt);
	return (1);
}

int	ft_create_graph_ctx(t_minirt_data *minirt)
{
	t_graphics	*gr_ctx;

	if (! minirt)
		return (0);
	gr_ctx = ft_calloc(1, sizeof(t_graphics));
	minirt->gr_ctx = gr_ctx;
	if (! gr_ctx)
	{
		ft_log_error("Malloc failed while constructing graphic context\n");
		return (0);
	}
	// gr_ctx->wnd_size[0] = minirt->t->size[0] * minirt->block_size[0];
	// gr_ctx->wnd_size[1] = minirt->t->size[1] * minirt->block_size[0];
	gr_ctx->wnd_size[0] = DISP_WIDTH;
	gr_ctx->wnd_size[1] = DISP_HEIGHT;
	gr_ctx->inst = mlx_init();
	if (! gr_ctx->inst)
		return (0);
	// gr_ctx->gos = gr_ob_list_constructor(gr_ctx);
	// if (! gr_ctx->gos)
	// 	return (0);
	mlx_loop_hook(minirt->gr_ctx->inst, &ft_handle_no_event, minirt);
	return (ft_create_wnd(minirt));
}

int	ft_dispose_graph_ctx(t_minirt_data *minirt)
{
	if (! minirt || ! minirt->gr_ctx)
		return (0);
	if (minirt->gr_ctx->inst)
	{
		mlx_loop_hook(minirt->gr_ctx->inst, NULL, NULL);
		if (minirt->gr_ctx->wnd)
		{
			mlx_key_hook(minirt->gr_ctx->wnd, NULL, minirt);
			mlx_hook(minirt->gr_ctx->wnd, ON_DESTROY, 0, NULL, NULL);
			mlx_destroy_window (minirt->gr_ctx->inst, minirt->gr_ctx->wnd);
			minirt->gr_ctx->wnd = NULL;
		}
		// gr_ob_list_dispose(&minirt->gr_ctx->gos);
	}
	free_x((void **)&minirt->gr_ctx);
	return (0);
}
