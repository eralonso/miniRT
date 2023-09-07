/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:48:27 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 13:04:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

t_img	*image_constructor(t_minirt_data *minirt, char *filename)
{
	t_img		*img;
	t_graphics	*gr_ctx;

	gr_ctx = minirt->gr_ctx;
	img = ft_calloc(1, sizeof(t_img));
	if (! img)
		return (img);
	img->ref = mlx_xpm_file_to_image(gr_ctx->inst, \
		filename, &img->size[0], &img->size[1]);
	if (! img->ref)
	{
		ft_log_error(ERR_IMAGE_OPEN_FAIL);
		image_dispose(&img, minirt);
	}
	img->addr = mlx_get_data_addr(img->ref, \
					&img->bpp, &img->size_line, &img->endian);
	if (! img->addr)
	{
		ft_log_error(ERR_IMAGE_OPEN_FAIL);
		image_dispose(&img, minirt);
	}
	img->bpp /= 8;
	return (img);
}

int	image_dispose(t_img **img, t_minirt_data *minirt)
{
	t_img		*limg;
	t_graphics	*gr_ctx;

	gr_ctx = minirt->gr_ctx;
	if (! img)
		return (0);
	limg = *img;
	if (limg->ref)
	{
		mlx_destroy_image (gr_ctx->inst, limg->ref);
		limg->ref = NULL;
	}
	free_x((void **) img);
	return (1);
}

static int	ft_valid_point(int x, int y, t_img *img)
{
	return (!(x < 0 || x >= img->size[0] \
		|| y < 0 || y >= img->size[1]));
}

t_rgba	ft_get_pixel(t_img *img, int x, int y, t_rgba def)
{
	t_rgba		ret;
	char		*pixel;
	int			idx;
	int			add;

	idx = 3 * (img->endian != 0);
	add = 1 - (2 * (img->endian != 0));
	if (!ft_valid_point(x, y, img))
		return (def);
	pixel = &img->addr[(y * img->size_line) + (x * img->bpp)];
	ret.b = pixel[idx];
	idx += add;
	ret.g = pixel[idx];
	idx += add;
	ret.r = pixel[idx];
	idx += add;
	ret.a = pixel[idx];
	return (ret);
}
