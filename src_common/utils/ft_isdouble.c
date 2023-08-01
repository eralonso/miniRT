/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/01 13:45:06 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

static char	*ft_purge_chars(char *str, const char *set)
{
	int	i;

	while (*str) // Cambio -> Antes: while (str) | Después: while (*str).
	{
		i = 0;
		while (set[i] && *str != set[i])
			i++;
		if (!set[i])
			return (str);
		str++;
	}
	return (str);
}

int	ft_validate_double(char *str)
{
	int		state;
	char	*aux;

	state = 1;
	while (*str && state > 0)
	{
		if (state == 1)
		{
			str = ft_purge_chars(str, " ");
			if (!*str)
				return (0);
			state = 2;
		}
		else if (state == 2)
		{
			aux = str;
			str = ft_purge_chars(str, "+-");
			if (str - aux > 1 || !*str)
				return (0);
			state = 3;
		}
		else if (state == 3)
		{
			str = ft_purge_chars(str, "0123456789");
			if (!*str)
				return (1);
			else if (*str == '.')
				state = 4;
			else if ((*str == 'e' || *str == 'E') && str[1] != '\0')
				state = 5;
			else
				return (0);
			str++;
		}
		else if (state == 4)
		{
			str = ft_purge_chars(str, "0123456789");
			if (!*str)
				return (1);
			else if ((*str == 'e' || *str == 'E') && str[1] != '\0')
				state = 5;
			else
				return (0);
			str++;
		}
		else if (state == 5)
		{
			aux = str;
			str = ft_purge_chars(str, "+-");
			if (str - aux > 1 || !*str)
				return (0);
			state = 6;
		}
		else if (state == 6)
		{
			aux = str;
			str = ft_purge_chars(str, "0123456789");
			return (str > aux && !*str);
		}
		else
			return (0);
	}
	return (-state);
}

// int	ft_validate_double(char *str)
// {
// 	int		state;
// 	char	*aux;

// 	state = 0;
// 	while (*str) // Cambio -> Antes: while (str) | Después: while (*str).
// 	{
// 		if (state == 0)
// 		{
// 			str = ft_purge_chars(str, " ");
// 			if (!*str) // Cambio -> Comprobar que no hay solo espacios.
// 				return (0);
// 			state = 1;
// 		}
// 		else if (state == 1)
// 		{
// 			aux = str;
// 			str = ft_purge_chars(str, "+-");
// 			if (str - aux > 1 || !*str) // Cambio -> Comprobar que el número no sea simplemente un signo ("   +", "-", ...).
// 				return (0);
// 			state = 2;
// 		}
// 		else if (state == 2)
// 		{
// 			str = ft_purge_chars(str, "0123456789");
// 			// if (!*str)
// 			// 	return (1);
// 			// else if (*str == '.')
// 			// {
// 			// 	str++;
// 			// 	state = 3;
// 			// }
// 			// else if (*str == 'e' || *str == 'E')
// 			// {
// 			// 	str++;
// 			// 	state = 4;
// 			// }
// 			// else
// 			// 	return (0);
// 			// Cambio -> Ya que si el carácter no es ni '.', ni 'e' o 'E', salimos de la función, podemos hacer la iteración de la string después de los condicionales.
// 			if (!*str)
// 				return (1);
// 			else if (*str == '.')
// 				state = 3;
// 			else if (*str == 'e' || *str == 'E')
// 				state = 4;
// 			else
// 				return (0);
// 			str++;
// 		}
// 		else if (state == 3)
// 		{
// 			str = ft_purge_chars(str, "0123456789");
// 			// if (!*str)
// 			// 	return (1);
// 			// else if (*str == 'e' || *str == 'E')
// 			// {
// 			// 	str++;
// 			// 	state = 4;
// 			// }
// 			// else
// 			// 	return (0);
// 			// Cambio -> Lo mismo que el caso anterior, itermaos después de los condicionales.
// 			if (!*str)
// 				return (1);
// 			else if (*str == 'e' || *str == 'E')
// 				state = 4;
// 			else
// 				return (0);
// 			str++;
// 		}
// 		else if (state == 4)
// 		{
// 			aux = str;
// 			str = ft_purge_chars(str, "+-");
// 			if (str - aux > 1 || !*str) // Cambio -> Comprobar que después de la e/E no haya simplemente un símbolo ("-1e+", "3.1415926535e-").
// 				return (0);
// 			state = 5;
// 		}
// 		else if (state == 5)
// 		{
// 			aux = str;
// 			str = ft_purge_chars(str, "0123456789");
// 			return ((str > aux));
// 		}
// 		else
// 			return (0);
// 	}
// 	return (0);
// }

// static int	ft_check_dots(char *str)
// {
// 	int	i;
// 	int	dot_cnt;
// 	int	e_cnt;

// 	i = 0;
// 	dot_cnt = 0;
// 	e_cnt = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '.')
// 		{
// 			if (e_cnt > 0)
// 				return (0);
// 			dot_cnt++;
// 		}
// 		if (str[i] == 'e' || str[i] == 'E')
// 		{
// 			e_cnt++;
// 			ft_check_signs(str+i+1, &i);
// 		}
// 		if (dot_cnt > 1 || e_cnt > 1)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static int	ft_check_signs(char *str, int *i)
// {
// 	if (!str || (ft_strchr("+-", str[0]) && ft_strchr("+-", str[1])))
// 		return (0);
// 	if (ft_strchr("+-", str[0]))
// 		(*i)++;
// 	return (1);
// }

int	ft_isdouble(char *str, double *ret)
{
	int		i;
	// int		exp_phase;

	*ret = ft_strtod(str);
	i = 0;
	if (*ret == INFINITY || *ret == NAN)
		return (0);
	if (!ft_validate_double(str))
		return (0);
	// if (!ft_check_signs(str, &i) || !ft_check_dots(str))
	// 	return (0);
	// if (!str[i])
	// 	return (0);
	// while (str[i])
	// {
	// 	if (!(ft_isdigit(str[i]) || str[i] == '.' \
	// 		|| str[i] == 'e' || str[i] == 'E' \
	// 		|| str[i] == '+' || str[i] == '-'))
	// 		return (0);
	// 	i++;
	// }
	return (1);
}
