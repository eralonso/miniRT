/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ctx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:09:47 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/19 14:31:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static int	ft_valid_point(t_vector vec, t_img *img)
{
	return (!(vec[0] < 0 || vec[0] >= img->img_size[0] \
		|| vec[1] < 0 || vec[1] >= img->img_size[1]));
}

void	ft_pixel_put(t_img *img, int x, int y, t_rgba color)
{
	char		*pixel;
	int			idx;
	int			add;
	t_vector	vec;

	idx = 3 * (img->endian != 0);
	add = 1 - (2 * (img->endian != 0));
	vec[0] = x;
	vec[1] = y;
	if (!ft_valid_point(vec, img))
		return ;
	pixel = &img->addr[(y * img->size_line) + (x * img->bpp)];
	pixel[idx] = color.b;
	idx += add;
	pixel[idx] = color.g;
	idx += add;
	pixel[idx] = color.r;
	idx += add;
	pixel[idx] = color.a;
}

void	ft_print_line(t_vector a, t_vector b, t_rgba color, t_img *img)
{
	t_vector	c;
	t_vector	inc;
	double		hip;
	double		len;

	if (!ft_valid_point(a, img) && !ft_valid_point(b, img))
		return ;
	hip = ft_distance(a, b);
	c[0] = a[0];
	c[1] = a[1];
	len = hip;
	inc[0] = (b[0] - a[0]) / hip;
	inc[1] = (b[1] - a[1]) / hip;
	while (len > 0)
	{
		if (ft_valid_point(c, img))
			ft_pixel_put(img, c[0], c[1], color);
		c[0] += inc[0];
		c[1] += inc[1];
		len--;
	}
}
