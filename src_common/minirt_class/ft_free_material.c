/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:11:29 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/24 17:31:10 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_data.h"
#include "stdio.h"

void	ft_free_material(void *p)
{
	t_material	*mat;

	mat = p;
	if (mat->name)
		free(mat->name);
	free(p);
}
