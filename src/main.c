/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 15:46:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;
	t_vector		a;
	t_vector		b;
	t_vector		res;

	if (argc == 2)
		printf("%d %30.28G\n", \
					ft_validate_double((char *)argv[1]), ft_strtod(argv[1]));
	else
		printf("use argment\n");
	a[0] = 1.0;
	a[1] = 1.0;
	a[2] = 0.0;
	b[0] = -1.0;
	b[1] = 1.0;
	b[2] = 0.0;
	ft_scale_vector(res, a, 1.0);
	ft_addition(res, res, a);
	ft_addition(res, res, a);
	ft_substraction(res, res, res);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	ft_scale_vector(res, a, 2.0);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	ft_normalize(res, a);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	printf("a = (%20.18G, %20.18G, %20.18G)\n", a[0], a[1], a[2]);
	printf("b = (%20.18G, %20.18G, %20.18G)\n", b[0], b[1], b[2]);
	printf("dot product a*b %20.18G\n", ft_dot_product(a, b));
	ft_cross_product(res, a, b);
	printf("a^b = (%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	ft_cross_product(res, res, a);
	printf("(a^b)^a = (%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	return (0);
	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
		mlx_loop(minirt->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	minirt_dispose(&minirt);
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
