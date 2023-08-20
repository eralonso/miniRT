/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:30:33 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/20 18:50:01 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"
#include <math.h>

t_rgba	get_background_color(void)
{
	return ((t_rgba){127, 127, 127, 0});
}

unsigned char	check_addition_rgba(unsigned char color1, unsigned char color2)
{
	int	res;

	res = (int)color1 + (int)color2;
	if (res > 255)
		res = 255;
	return (res);
}

t_rgba	ft_rgba_addition(t_rgba color1, t_rgba color2)
{
	t_rgba	ret;

	ret.r = check_addition_rgba(color1.r, color2.r);
	ret.g = check_addition_rgba(color1.g, color2.g);
	ret.b = check_addition_rgba(color1.b, color2.b);
	ret.a = check_addition_rgba(color1.a, color2.a);
	return (ret);
}

t_rgba	ft_col_light(t_rgba color_source, double ratio, t_rgba surf_col)
{
	const unsigned char	*light_channels = \
		(const unsigned char *)&color_source;
	unsigned char		*surf_channels;
	int					i;
	double				comp;

	surf_channels = (unsigned char *)&surf_col;
	i = 0;
	while (i < 3)
	{
		comp = ratio * light_channels[i] / 255.0;
		surf_channels[i] = (unsigned char)floor(comp * surf_channels[i]);
		i++;
	}
	return (surf_col);
}
