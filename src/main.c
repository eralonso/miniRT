/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 12:16:31 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;
	t_vector		a;
	t_vector		res;

	if (argc == 2)
		printf("%d %30.28G\n", \
					ft_validate_double((char *)argv[1]), ft_strtod(argv[1]));
	else
		printf("use argment\n");
	a[0] = 1.0;
	a[1] = 1.0;
	a[2] = 0.0;
	ft_scale_vector(res, a, 1.0);
	ft_addition(res, res, a);
	ft_addition(res, res, a);
	ft_substraction(res, res, res);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	ft_scale_vector(res, a, 2.0);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	ft_normalize(res, a);
	printf("(%20.18G, %20.18G, %20.18G)\n", res[0], res[1], res[2]);
	return (0);
	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
		mlx_loop(minirt->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	minirt_dispose(&minirt);
	return (0);
}
