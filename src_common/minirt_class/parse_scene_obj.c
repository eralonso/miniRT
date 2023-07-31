/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:50:28 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 18:52:34 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common.h"

int	ft_parse_ambient(t_list *node, char **str_arr)
{
	t_ambient	*ambient;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (ft_log_error(ERR_AMBIENT_MALLOC_FAILED));
	ambient->count = 1;
	if (ft_matrixlen(str_arr) != AMBIENT_COMPONENTS_NUMBER)
	{
		free(ambient);
		return (ft_log_error(ERR_AMBIENT_COMPONENTS_NUMBER));
	}
	if (!ft_isdouble(str_arr[1], &ambient->ratio)
		|| !ft_isrgb(str_arr[2], &ambient->color))
	{
		free(ambient);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = ambient;
	return (1);
}

int	ft_parse_camera(t_list *node, char **str_arr)
{
	t_camera	*camera;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (ft_log_error(ERR_CAMERA_MALLOC_FAILED));
	camera->count = 1;
	if (ft_matrixlen(str_arr) != CAMERA_COMPONENTS_NUMBER)
	{
		free(camera);
		return (ft_log_error(ERR_CAMERA_COMPONENTS_NUMBER));
	}
	if (!ft_isvector(str_arr[1], camera->point)
		|| !ft_isvector(str_arr[2], camera->orientation)
		|| !ft_isdouble(str_arr[3], &camera->fov))
	{
		free(camera);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = camera;
	return (1);
}

int	ft_parse_light(t_list *node, char **str_arr)
{
	t_light	*light;

	if (!str_arr || !node)
		return (ft_log_error(ERR_MISSED_ARGUMENTS_AT_PARSE));
	light = malloc(sizeof(t_light));
	if (!light)
		return (ft_log_error(ERR_LIGHT_MALLOC_FAILED));
	light->count = 1;
	if (ft_matrixlen(str_arr) != LIGHT_COMPONENTS_NUMBER)
	{
		free(light);
		return (ft_log_error(ERR_LIGHT_COMPONENTS_NUMBER));
	}
	if (!ft_isvector(str_arr[1], light->point)
		|| !ft_isdouble(str_arr[2], &light->brightness)
		|| !ft_isrgb(str_arr[2], &light->color))
	{
		free(light);
		return (0);
	}
	free_x((void **)&node->content);
	node->content = light;
	return (1);
}
