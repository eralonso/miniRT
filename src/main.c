/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/02 15:44:30 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

void print_line(void *line)
{
	printf("%s", line);
}

int	main(int argc, char const *argv[])
{
	//t_minirt_data	*minirt;
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
	// minirt = minirt_constructor(ft_take_argument(argc, argv));
	// if (minirt)
	// 	mlx_loop(minirt->gr_ctx->inst);
	// ft_putstr_fd ("exit main\n", 1);
	// minirt_dispose(&minirt);
	char	*filename = ft_take_argument(argc, argv);
	t_list	*list = ft_read_map(filename);
	list = ft_lstreverse(&list);
	ft_lstiter(list, print_line);
	ft_lstclear(&list, free);
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
