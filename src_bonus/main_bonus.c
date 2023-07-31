/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:40 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/25 12:44:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int argc, char const *argv[])
{
	t_minirt_data	*minirt;

	minirt = minirt_constructor(ft_take_argument(argc, argv));
	if (minirt)
		mlx_loop(minirt->gr_ctx->inst);
	ft_putstr_fd ("exit main\n", 1);
	minirt_dispose(&minirt);
	return (0);
}
