/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_n_log_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:45 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 14:58:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_free_n_log_error(void *to_free, char *msg)
{
	if (to_free)
		free(to_free);
	return (ft_log_error(msg));
}
