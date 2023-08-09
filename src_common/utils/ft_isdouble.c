/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/08/04 18:00:19 by eralonso         ###   ########.fr       */
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

static int	check_after_num(char *aux, char *str, int state, int dot)
{
	int	next_state;

	next_state = 0;
	if (!*aux)
		next_state = -state;
	else if (dot && *aux == '.' \
		&& (ft_isdigit(str[0]) || ft_isdigit(str[1]) || ft_isdigit(aux[1])))
		next_state = 4;
	else if ((*aux == 'e' || *aux == 'E') && aux[1] != '\0')
		next_state = 5;
	return (next_state);
}

static char	*do_state(char *aux, char *str, int *state, const char *set)
{
	char	*ret;
	int		next_state;

	ret = ft_purge_chars(aux, set);
	next_state = 0;
	if (*state == 1 && *ret)
		next_state = 2;
	else if (*state == 2 && ret - aux <= 1 && *ret)
		next_state = 3;
	else if (*state == 3)
		next_state = check_after_num(ret, str, *state, 1);
	else if (*state == 4)
		next_state = check_after_num(ret, str, *state, 0);
	else if (*state == 5)
		next_state = 6 * (ret - aux <= 1 && *ret);
	else if (*state == 6)
		next_state = -(*state) * (!*ret);
	if ((*state == 3 || *state == 4) && *ret)
		ret++;
	*state = next_state;
	return (ret);
}

int	ft_isdouble(char *str, double *ret)
{
	int					state;
	char				*aux;
	static const char	*sets[6] = {" ", "+-", "0123456789", \
								"0123456789", "+-", "0123456789"};

	*ret = ft_strtod(str);
	if (*ret == INFINITY || *ret == NAN)
		return (ft_log_error(ISDOUBLE_NIR));
	state = 1;
	aux = str;
	while (*str && state > 0)
		if (state > 0 && state < 7)
			aux = do_state(aux, str, &state, sets[state - 1]);
	if (!state)
		ft_log_error(ISDOUBLE_NAN);
	return (-state);
}
