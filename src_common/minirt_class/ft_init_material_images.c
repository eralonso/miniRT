/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_material_images.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:34:56 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 14:01:21 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_mount_image(unsigned int ui, void *vmat, void *data)
{
	t_minirt_data	*minirt;
	t_material		*mat;
	t_image_ext		*image_ext;

	(void)ui;
	mat = vmat;
	minirt = data;
	if (mat->type != MTT_IMAGE)
		return ;
	image_ext = mat->ext_prop;
	image_ext->img = image_constructor(minirt, image_ext->filename);
	if (!image_ext->img)
		minirt->mat_link_nok = 1;
}

int	ft_init_material_images(t_minirt_data *minirt)
{
	ft_lstreduce(minirt->materials_list, ft_mount_image, minirt);
	return (!minirt->mat_link_nok);
}
