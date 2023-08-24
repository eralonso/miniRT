/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 19:01:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

// void	print_sphere(void *figure)
// {
// 	t_sphere	*sphere;

// 	sphere = (t_sphere *)figure;
// 	printf("-> figures -> ft: %i\n", sphere->ft);
// 	printf("-> figures -> point[0]: %f\n", sphere->point[0]);
// 	printf("-> figures -> point[1]: %f\n", sphere->point[1]);
// 	printf("-> figures -> point[2]: %f\n", sphere->point[2]);
// 	printf("-> figures -> color -> r: %i\n", sphere->color.r);
// 	printf("-> figures -> color -> g: %i\n", sphere->color.g);
// 	printf("-> figures -> color -> b: %i\n", sphere->color.b);
// 	printf("-> figures -> color -> a: %i\n", sphere->color.a);
// 	printf("-> figures -> diameter: %f\n", sphere->diameter);
// }

// void	print_plane(void *figure)
// {
// 	t_plane	*plane;

// 	plane = (t_plane *)figure;
// 	printf("-> figures -> ft: %i\n", plane->ft);
// 	printf("-> figures -> point[0]: %f\n", plane->point[0]);
// 	printf("-> figures -> point[1]: %f\n", plane->point[1]);
// 	printf("-> figures -> point[2]: %f\n", plane->point[2]);
// 	printf("-> figures -> color -> r: %i\n", plane->color.r);
// 	printf("-> figures -> color -> g: %i\n", plane->color.g);
// 	printf("-> figures -> color -> b: %i\n", plane->color.b);
// 	printf("-> figures -> color -> a: %i\n", plane->color.a);
// 	printf("-> figures -> orientation[0]: %f\n", plane->orientation[0]);
// 	printf("-> figures -> orientation[1]: %f\n", plane->orientation[1]);
// 	printf("-> figures -> orientation[2]: %f\n", plane->orientation[2]);
// }

// void	print_cylinder(void *figure)
// {
// 	t_cylinder	*cylinder;

// 	cylinder = (t_cylinder *)figure;
// 	printf("-> figures -> ft: %i\n", cylinder->ft);
// 	printf("-> figures -> point[0]: %f\n", cylinder->point[0]);
// 	printf("-> figures -> point[1]: %f\n", cylinder->point[1]);
// 	printf("-> figures -> point[2]: %f\n", cylinder->point[2]);
// 	printf("-> figures -> color -> r: %i\n", cylinder->color.r);
// 	printf("-> figures -> color -> g: %i\n", cylinder->color.g);
// 	printf("-> figures -> color -> b: %i\n", cylinder->color.b);
// 	printf("-> figures -> color -> a: %i\n", cylinder->color.a);
// 	printf("-> figures -> orientation[0]: %f\n", cylinder->orientation[0]);
// 	printf("-> figures -> orientation[1]: %f\n", cylinder->orientation[1]);
// 	printf("-> figures -> orientation[2]: %f\n", cylinder->orientation[2]);
// 	printf("-> figures -> diameter: %f\n", cylinder->diameter);
// 	printf("-> figures -> height: %f\n", cylinder->height);
// }

// void	print_figures(t_list **figures)
// {
// 	t_list			*tmp;
// 	static t_print	print[3] = {print_sphere, print_plane, print_cylinder};

// 	tmp = *figures;
// 	while (tmp)
// 	{
// 		print[((t_sphere *)(tmp->content))->ft](tmp->content);
// 		printf("\n");
// 		tmp = tmp->next;
// 	}
// }

// void	print_minirt(t_minirt_data *minirt)
// {
// 	printf("-> filename: %s\n\n", minirt->filename);
// 	printf("-> gr_ctx: %p\n", minirt->gr_ctx);
// 	printf("-> gr_ctx -> inst: %p\n", minirt->gr_ctx->inst);
// 	printf("-> gr_ctx -> wnd: %p\n", minirt->gr_ctx->wnd);
// 	printf("-> gr_ctx -> wnd[0]: %i\n", minirt->gr_ctx->wnd_size[0]);
// 	printf("-> gr_ctx -> wnd[1]: %i\n\n", minirt->gr_ctx->wnd_size[1]);
// 	printf("-> ambient -> ratio: %f\n", minirt->ambient.ratio);
// 	printf("-> ambient -> color -> r: %i\n", minirt->ambient.color.r);
// 	printf("-> ambient -> color -> g: %i\n", minirt->ambient.color.g);
// 	printf("-> ambient -> color -> b: %i\n", minirt->ambient.color.b);
// 	printf("-> ambient -> color -> a: %i\n", minirt->ambient.color.a);
// 	printf("-> ambient -> count: %zu\n\n", minirt->ambient.count);
// 	printf("-> camera -> fov: %f\n", minirt->camera.fov);
// 	printf("-> camera -> point[0]: %f\n", minirt->camera.point[0]);
// 	printf("-> camera -> point[1]: %f\n", minirt->camera.point[1]);
// 	printf("-> camera -> point[2]: %f\n", minirt->camera.point[2]);
// 	printf("-> camera -> orientation[0]: %f\n", minirt->camera.orientation[0]);
// 	printf("-> camera -> orientation[1]: %f\n", minirt->camera.orientation[1]);
// 	printf("-> camera -> orientation[2]: %f\n", minirt->camera.orientation[2]);
// 	printf("-> camera -> count: %zu\n\n", minirt->camera.count);
// 	printf("-> light -> brightness: %f\n", minirt->light.brightness);
// 	printf("-> light -> point[0]: %f\n", minirt->light.point[0]);
// 	printf("-> light -> point[1]: %f\n", minirt->light.point[1]);
// 	printf("-> light -> point[2]: %f\n", minirt->light.point[2]);
// 	printf("-> light -> color -> r: %i\n", minirt->light.color.r);
// 	printf("-> light -> color -> g: %i\n", minirt->light.color.g);
// 	printf("-> light -> color -> b: %i\n", minirt->light.color.b);
// 	printf("-> light -> color -> a: %i\n", minirt->light.color.a);
// 	printf("-> light -> count: %zu\n\n", minirt->light.count);
// 	print_figures(&minirt->figures);
// }

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
