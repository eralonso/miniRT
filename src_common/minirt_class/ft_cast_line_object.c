/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_line_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:48:01 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/31 10:52:32 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

static t_minirt_type	ft_get_object_type(char *id)
{
	size_t				len;
	size_t				i;
	const char			*mrt_str_id_arr[8] = {\
							"pl", "sp", "cy", "cn", \
							"mt", "A", "C", "L"};
	const t_minirt_type	mrt_id_arr[8] = {\
		MRT_PLANE, MRT_SPHERE, MRT_CYLINDER, MRT_CONE, \
		MRT_MATERIAL, MRT_AMBIENT, MRT_CAMERA, MRT_LIGHT};

	len = ft_strlen_x(id);
	if (len < 1 || len > 2)
		return (MRT_INVALID);
	i = 0;
	while (i < 8)
	{
		if (!ft_strncmp(id, mrt_str_id_arr[i], len))
			return (mrt_id_arr[i]);
		i++;
	}
	return (MRT_INVALID);
}

static t_minirt_type	ft_parse_object(t_list *node, \
										char **str_arr, \
										t_minirt_type mrtt)
{
	t_object_parser	parser[10];
	int				parse_res;

	parser[MRT_INVALID] = NULL;
	parser[MRT_EMPTY] = NULL;
	parser[MRT_AMBIENT] = ft_parse_ambient;
	parser[MRT_CAMERA] = ft_parse_camera;
	parser[MRT_LIGHT] = ft_parse_light;
	parser[MRT_MATERIAL] = ft_parse_material;
	parser[MRT_SPHERE] = ft_parse_sphere;
	parser[MRT_PLANE] = ft_parse_plane;
	parser[MRT_CYLINDER] = ft_parse_cylinder;
	parser[MRT_CONE] = ft_parse_cone;
	if (parser[mrtt])
	{
		parse_res = parser[mrtt](node, str_arr);
		if (parse_res)
			return (mrtt);
	}
	return (MRT_INVALID);
}

t_minirt_type	ft_cast_line_object(t_list *node)
{
	char			**str_arr;
	t_minirt_type	mrtt;

	if (((char *)node->content)[0] == 0)
		return (MRT_EMPTY);
	str_arr = ft_split(node->content, ' ');
	if (!str_arr)
		return (ft_log_error("Malloc failed while casting line\n"));
	if (!str_arr[0])
	{
		free(str_arr);
		return (MRT_EMPTY);
	}
	mrtt = ft_get_object_type(str_arr[0]);
	if (mrtt == MRT_INVALID)
	{
		ft_delete_str_arr(str_arr);
		return (ft_log_error("Invalid type of object\n"));
	}
	mrtt = ft_parse_object(node, str_arr, mrtt);
	ft_delete_str_arr(str_arr);
	return (mrtt);
}
