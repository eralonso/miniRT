/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:44:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/27 17:06:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_H
# define MINIRT_DATA_H

# include "../../libft/libft.h"
# include "../graph_ctx/graph_decl.h"

# define AMBIENT_COMPONENTS_NUMBER 3
# define CAMERA_COMPONENTS_NUMBER 4
# define LIGHT_COMPONENTS_NUMBER 4
# define SPHERE_COMPONENTS_NUMBER 4
# define PLANE_COMPONENTS_NUMBER 4
# define CYLINDER_COMPONENTS_NUMBER 6

# define ERR_AMBIENT_COMPONENTS_NUMBER \
		"Invalid number of components for ambient light\n"
# define ERR_AMBIENT_MALLOC_FAILED \
		"Malloc failed when allocating ambient\n"
# define ERR_CAMERA_COMPONENTS_NUMBER \
		"Invalid number of components for light\n"
# define ERR_CAMERA_MALLOC_FAILED \
		"Malloc failed when allocating camera\n"
# define ERR_LIGHT_COMPONENTS_NUMBER \
		"Invalid number of components for light\n"
# define ERR_LIGHT_MALLOC_FAILED \
		"Malloc failed when allocating light\n"
# define ERR_SPHERE_COMPONENTS_NUMBER \
		"Invalid number of components for sphere\n"
# define ERR_SPHERE_MALLOC_FAILED \
		"Malloc failed when allocating sphere\n"
# define ERR_PLANE_COMPONENTS_NUMBER \
		"Invalid number of components for plane\n"
# define ERR_PLANE_MALLOC_FAILED \
		"Malloc failed when allocating plane\n"
# define ERR_CYLINDER_COMPONENTS_NUMBER \
		"Invalid number of components for cylinder\n"
# define ERR_CYLINDER_MALLOC_FAILED \
		"Malloc failed when allocating cylinder\n"
# define ERR_MISSED_ARGUMENTS_AT_PARSE \
		"Missed arguments at parse\n"

typedef double	t_vector[3];

typedef struct s_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_rgba;

typedef struct s_ambient
{
	double	ratio;
	t_rgba	color;
	size_t	count;
}	t_ambient;

typedef struct s_camera
{
	t_vector	point;
	t_vector	orientation;
	double		fov;
	size_t		count;
}	t_camera;

typedef struct s_light
{
	t_vector	point;
	double		brightness;
	t_rgba		color;
	size_t		count;
}	t_light;

typedef struct s_sphere
{
	t_vector	point;
	double		diameter;
	t_rgba		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	point;
	t_vector	orientation;
	t_rgba		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	point;
	t_vector	orientation;
	double		diameter;
	double		height;
	t_rgba		color;
}	t_cylinder;

typedef enum e_figure_type
{
	FT_SPHERE,
	FT_PLANE,
	FT_CYLINDER
}	t_figure_type;

typedef enum e_minirt_type
{
	MRT_INVALID,
	MRT_EMPTY,
	MRT_AMBIENT,
	MRT_CAMERA,
	MRT_LIGHT,
	MRT_SPHERE,
	MRT_PLANE,
	MRT_CYLINDER,
}	t_minirt_type;

typedef struct s_figure
{
	t_figure_type	ft;
	size_t			count;
	void			*data;
}	t_figure;

typedef struct s_minirt_data
{
	t_graphics		*gr_ctx;
	char			*filename;
	int				exit_cmd;
	t_list			*list;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_list			*figures;
}	t_minirt_data;

typedef int		(*t_object_parser)(t_list *, char **);

int	ft_parse_sphere(t_list *node, char **str_arr);
int	ft_parse_plane(t_list *node, char **str_arr);
int	ft_parse_cylinder(t_list *node, char **str_arr);
int	ft_parse_ambient(t_list *node, char **str_arr);
int	ft_parse_camera(t_list *node, char **str_arr);
int	ft_parse_light(t_list *node, char **str_arr);

#endif