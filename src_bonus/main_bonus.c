/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/04 10:45:07 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;
	static int		size[2] = {DISP_HEIGHT, DISP_WIDTH};

	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
	{
		camera_rays_v2(minirt, &minirt->camera, &minirt->gr_ctx->img, size);
		mlx_put_image_to_window(minirt->gr_ctx->inst, minirt->gr_ctx->wnd, \
			minirt->gr_ctx->img.image, 0, 0);
		mlx_loop(minirt->gr_ctx->inst);
	}
	return (0);
}
