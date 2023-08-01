/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/01 20:09:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../common.h"
#include <math.h>

static char	*ft_purge_chars(char *str, const char *set)
{
	int	i;

	while (*str)
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

static int	check_after_num(char *str, int state, int dot)
{
	int	next_state;

	next_state = 0;
	if (!*str)
		next_state = -state;
	else if (dot && *str == '.' && str[1] != '\0')
		next_state = 4;
	else if ((*str == 'e' || *str == 'E') && str[1] != '\0')
		next_state = 5;
	return (next_state);
}

static char	*do_state(char *str, int *state, char *set)
{
	char	*ret;
	int		next_state;

	ret = ft_purge_chars(str, set);
	next_state = 0;
	if (*state == 1 && *ret)
		next_state = 2;
	else if (*state == 2 && ret - str <= 1 && *ret)
		next_state = 3;
	else if (*state == 3)
		next_state = check_after_num(ret++, *state, 1);
	else if (*state == 4)
		next_state = check_after_num(ret++, *state, 0);
	else if (*state == 5)
		next_state = 6 * (ret - str <= 1 && *ret);
	else if (*state == 6)
		next_state = -(*state) * (ret == str && *ret);
	*state = next_state;
	return (ret);
}

int	ft_validate_double(char *str)
{
	int		state;

	state = 1;
	while (*str && state > 0)
	{
		if (state == 1)
			str = do_state(str, &state, " ");
		else if (state == 2)
			str = do_state(str, &state, "+-");
		else if (state == 3)
			str = do_state(str, &state, "0123456789");
		else if (state == 4)
			str = do_state(str, &state, "0123456789");
		else if (state == 5)
			str = do_state(str, &state, "+-");
		else if (state == 6)
			str = do_state(str, &state, "0123456789");
		else
			state = 0;
	}
	return (-state);
}

int	ft_isdouble(char *str, double *ret)
{
	int		i;

	*ret = ft_strtod(str);
	i = 0;
	if (*ret == INFINITY || *ret == NAN)
		return (0);
	if (!ft_validate_double(str))
		return (0);
	return (1);
}
