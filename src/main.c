/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/31 16:59:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;

	if (argc == 2)
		printf("%d %30.28G\n", ft_validate_double((char *)argv[1]), ft_strtod(argv[1]));
	else
		printf("use argment\n");
	return (0);
	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
		mlx_loop(minirt->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	minirt_dispose(&minirt);
	return (0);
}
