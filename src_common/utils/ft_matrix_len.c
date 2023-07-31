/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:18:09 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/26 12:19:59 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_matrixlen(char **matrix)
{
	int	len;

	len = 0;
	if (!matrix)
		return (0);
	while (matrix[len])
		len++;
	return (len);
}
