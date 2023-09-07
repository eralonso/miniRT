/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mat_images.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:14:06 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/07 14:20:55 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static void	ft_dismount_image(unsigned int ui, void *vmat, void *data)
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
	if (image_ext->img)
		image_dispose(&image_ext->img, minirt);
}

int	ft_destroy_mat_images(t_minirt_data *minirt)
{
	ft_lstreduce(minirt->materials_list, ft_dismount_image, minirt);
	return (1);
}
