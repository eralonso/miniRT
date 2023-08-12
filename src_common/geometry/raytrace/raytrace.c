/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:47:34 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/12 17:07:09 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../common.h"

t_rgba	raytrace(t_minirt_data *minirt, t_line ray)
{
	t_rgba	color;

	(void)minirt;
	(void)ray;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	color.a = 0;
	return (color);
}
