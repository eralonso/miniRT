/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/09 16:02:42 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

void print_line(void *line)
{
	printf("%s", line);
}

void	print_sphere(void *figure)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)figure;
	printf("-> figures -> ft: %i\n", sphere->ft);
	printf("-> figures -> point[0]: %f\n", sphere->point[0]);
	printf("-> figures -> point[1]: %f\n", sphere->point[1]);
	printf("-> figures -> point[2]: %f\n", sphere->point[2]);
	printf("-> figures -> color -> r: %i\n", sphere->color.r);
	printf("-> figures -> color -> g: %i\n", sphere->color.g);
	printf("-> figures -> color -> b: %i\n", sphere->color.b);
	printf("-> figures -> color -> a: %i\n", sphere->color.a);
	printf("-> figures -> diameter: %f\n", sphere->diameter);
}

void	print_plane(void *figure)
{
	t_plane	*plane;

	plane = (t_plane *)figure;
	printf("-> figures -> ft: %i\n", plane->ft);
	printf("-> figures -> point[0]: %f\n", plane->point[0]);
	printf("-> figures -> point[1]: %f\n", plane->point[1]);
	printf("-> figures -> point[2]: %f\n", plane->point[2]);
	printf("-> figures -> color -> r: %i\n", plane->color.r);
	printf("-> figures -> color -> g: %i\n", plane->color.g);
	printf("-> figures -> color -> b: %i\n", plane->color.b);
	printf("-> figures -> color -> a: %i\n", plane->color.a);
	printf("-> figures -> orientation[0]: %f\n", plane->orientation[0]);
	printf("-> figures -> orientation[1]: %f\n", plane->orientation[1]);
	printf("-> figures -> orientation[2]: %f\n", plane->orientation[2]);
}

void	print_cylinder(void *figure)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)figure;
	printf("-> figures -> ft: %i\n", cylinder->ft);
	printf("-> figures -> point[0]: %f\n", cylinder->point[0]);
	printf("-> figures -> point[1]: %f\n", cylinder->point[1]);
	printf("-> figures -> point[2]: %f\n", cylinder->point[2]);
	printf("-> figures -> color -> r: %i\n", cylinder->color.r);
	printf("-> figures -> color -> g: %i\n", cylinder->color.g);
	printf("-> figures -> color -> b: %i\n", cylinder->color.b);
	printf("-> figures -> color -> a: %i\n", cylinder->color.a);
	printf("-> figures -> orientation[0]: %f\n", cylinder->orientation[0]);
	printf("-> figures -> orientation[1]: %f\n", cylinder->orientation[1]);
	printf("-> figures -> orientation[2]: %f\n", cylinder->orientation[2]);
	printf("-> figures -> diameter: %f\n", cylinder->diameter);
	printf("-> figures -> height: %f\n", cylinder->height);
}

void	print_figures(t_list **figures)
{
	t_list			*tmp;
	static t_print	print[3] = {print_sphere, print_plane, print_cylinder};

	tmp = *figures;
	while (tmp)
	{
		print[((t_sphere *)(tmp->content))->ft](tmp->content);
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_minirt(t_minirt_data *minirt)
{
	printf("-> filename: %s\n\n", minirt->filename);
	printf("-> gr_ctx: %p\n", minirt->gr_ctx);
	printf("-> gr_ctx -> inst: %p\n", minirt->gr_ctx->inst);
	printf("-> gr_ctx -> wnd: %p\n", minirt->gr_ctx->wnd);
	printf("-> gr_ctx -> wnd[0]: %i\n", minirt->gr_ctx->wnd_size[0]);
	printf("-> gr_ctx -> wnd[1]: %i\n\n", minirt->gr_ctx->wnd_size[1]);
	printf("-> ambient -> ratio: %f\n", minirt->ambient.ratio);
	printf("-> ambient -> color -> r: %i\n", minirt->ambient.color.r);
	printf("-> ambient -> color -> g: %i\n", minirt->ambient.color.g);
	printf("-> ambient -> color -> b: %i\n", minirt->ambient.color.b);
	printf("-> ambient -> color -> a: %i\n", minirt->ambient.color.a);
	printf("-> ambient -> count: %zu\n\n", minirt->ambient.count);
	printf("-> camera -> fov: %f\n", minirt->camera.fov);
	printf("-> camera -> point[0]: %f\n", minirt->camera.point[0]);
	printf("-> camera -> point[1]: %f\n", minirt->camera.point[1]);
	printf("-> camera -> point[2]: %f\n", minirt->camera.point[2]);
	printf("-> camera -> orientation[0]: %f\n", minirt->camera.orientation[0]);
	printf("-> camera -> orientation[1]: %f\n", minirt->camera.orientation[1]);
	printf("-> camera -> orientation[2]: %f\n", minirt->camera.orientation[2]);
	printf("-> camera -> count: %zu\n\n", minirt->camera.count);
	printf("-> light -> brightness: %f\n", minirt->light.brightness);
	printf("-> light -> point[0]: %f\n", minirt->light.point[0]);
	printf("-> light -> point[1]: %f\n", minirt->light.point[1]);
	printf("-> light -> point[2]: %f\n", minirt->light.point[2]);
	printf("-> light -> color -> r: %i\n", minirt->light.color.r);
	printf("-> light -> color -> g: %i\n", minirt->light.color.g);
	printf("-> light -> color -> b: %i\n", minirt->light.color.b);
	printf("-> light -> color -> a: %i\n", minirt->light.color.a);
	printf("-> light -> count: %zu\n\n", minirt->light.count);
	print_figures(&minirt->figures);
}

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;
	// t_matrix		m;
	// double			**_m;
	// t_vector		a;
	// double			*_a;
	// double			*_b;
	// t_vector		res;

	// if (argc == 2)
	// 	printf("%d %30.28G\n", \
	// 				ft_validate_double((char *)argv[1]), ft_strtod(argv[1]));
	// else
	// 	printf("use argment\n");

	// a[0] = 1.0;
	// a[1] = 0.0;
	// a[2] = 0.0;
	// _a = ft_vector_create(a);
	// _b = ft_vector_create(_a);
	// _b[0] = 0.0;
	// _b[1] = 1.0;
	// _b[2] = 0.0;
	// m[0] = ft_vector_create(_a);
	// ft_scale_vector(m[0], m[0], 0.25);
	// m[1] = ft_vector_create(_b);
	// ft_scale_vector(m[1], m[1], 4.0);
	// m[2] = ft_vector_create(_b);
	// m[2] = ft_cross_product(m[2], m[0], m[1]);
	// ft_scale_vector(res, _a, 1.0);
	// ft_addition(res, res, _a);
	// ft_addition(res, res, _a);
	// ft_substraction(res, res, res);
	// printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	// ft_scale_vector(res, _a, 2.0);
	// printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	// ft_normalize(res, _a);
	// printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	// printf("a = (%20.18G, %20.18G, %20.18G)\n", _a[0], _a[1], _a[2]);
	// printf("b = (%20.18G, %20.18G, %20.18G)\n", _b[0], _b[1], _b[2]);
	// printf("dot product a*b %20.18G\n", ft_dot_product(_a, _b));
	// ft_cross_product(res, _a, _b);
	// printf("a^b = (%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	// ft_cross_product(res, res, a);
	// printf("(a^b)^a = (%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	// _m = ft_matrix_create(m);
	// printf("m[0] = (%20.18G, %20.18G, %20.18G)\n", _m[0][0], _m[0][1], _m[0][2]);
	// printf("m[1] = (%20.18G, %20.18G, %20.18G)\n", _m[1][0], _m[1][1], _m[1][2]);
	// printf("m[2] = (%20.18G, %20.18G, %20.18G)\n", _m[2][0], _m[2][1], _m[2][2]);
	// _a = ft_vector_dispose(_a);
	// _b = ft_vector_dispose(_b);
	// m[0] = ft_vector_dispose(m[0]);
	// m[1] = ft_vector_dispose(m[1]);
	// m[2] = ft_vector_dispose(m[2]);
	// _m = ft_matrix_dispose(_m);
	// return (0);
	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
	{
		t_rgba color;

		color.r = 0xFF;
		color.g = 0x0;
		color.b = 0x0;
		color.a = 0x0;
		t_vector src = {0, 0, 0};
		t_vector dst = {100, 100, 0};

		for (int i = 0; i < 50; i++)
		{
			ft_print_line(src, dst, color, &minirt->gr_ctx->img);
			dst[0] += 1.0;
		}
		mlx_put_image_to_window(minirt->gr_ctx->inst, minirt->gr_ctx->wnd, minirt->gr_ctx->img.image, 0, 0);
		print_minirt(minirt);
		mlx_loop(minirt->gr_ctx->inst);
	}
	ft_putstr_fd ("exit main\n", 1);
	minirt_dispose(&minirt);
	// char	*filename = ft_take_argument(argc, argv);
	// t_list	*list = ft_read_map(filename);
	// list = ft_lstreverse(&list);
	// ft_lstiter(list, print_line);
	// ft_lstclear(&list, free);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	double	num;

// 	num = 0;
// 	if (ac == 2)
// 		printf("%d %30.28G\n", \
// 					ft_isdouble(av[1], &num), num);
// 	else
// 		printf("use argment\n");
// 	return (0);
// }
