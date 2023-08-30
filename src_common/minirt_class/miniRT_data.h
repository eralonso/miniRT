/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:44:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/30 12:27:19 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_H
# define MINIRT_DATA_H

# include "../../libft/libft.h"
# include "../graph_ctx/graph_decl.h"

# define AMBIENT_COMPONENTS_NUMBER 3
# define CAMERA_COMPONENTS_NUMBER 5
# define LIGHT_COMPONENTS_NUMBER 4
# define MATERIAL_MIN_COMPONENTS_NUMBER 6
# define MATERIAL_CHESS_COMPONENTS_NUMBER 7
# define SPHERE_COMPONENTS_NUMBER 4
# define PLANE_COMPONENTS_NUMBER 4
# define CYLINDER_COMPONENTS_NUMBER 6
# define CONE_COMPONENTS_NUMBER 7

# define ERR_MISSING_AMBIENT_LIGHT \
		"Missing ambient light\n"
# define ERR_MISSING_CAMERA \
		"Missing camera\n"
# define ERR_MISSING_LIGHTS \
		"Missing lights\n"
# define ERR_MINIRT_MALLOC_FAILED \
		"Malloc failed while constructing minirt\n"
# define ERR_CHECK_OBJECT_MISS_DATA \
		"Either miniRT data or node missed\n"
# define ERR_AMBIENT_LIGHT_REPEATED \
		"Ambient light must be only once\n"
# define ERR_CAMERA_REPEATED \
		"Camera must be only once\n"
# define ERR_AMBIENT_COMPONENTS_NUMBER \
		"Invalid number of components for ambient light\n"
# define ERR_AMBIENT_MALLOC_FAILED \
		"Malloc failed when allocating ambient\n"
# define ERR_CAMERA_COMPONENTS_NUMBER \
		"Invalid number of components for camera\n"
# define ERR_CAMERA_MALLOC_FAILED \
		"Malloc failed when allocating camera\n"
# define ERR_LIGHT_COMPONENTS_NUMBER \
		"Invalid number of components for light\n"
# define ERR_LIGHT_MALLOC_FAILED \
		"Malloc failed when allocating light\n"
# define ERR_MATERIAL_COMPONENTS_NUMBER \
		"Invalid number of components for material\n"
# define ERR_CHESS_MATERIAL_COMPONENTS_NUMBER \
		"Invalid number of components for chess material\n"
# define ERR_MATERIAL_MALLOC_FAILED \
		"Malloc failed when allocating material\n"
# define ERR_MATERIAL_TABLE_MALLOC_FAILED \
		"Malloc failed when allocating table for materials\n"
# define ERR_MATERIAL_TABLE_OVERFLOW \
		"Too many materials instantiated for the table\n"
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
# define ERR_CONE_COMPONENTS_NUMBER \
		"Invalid number of components for cone\n"
# define ERR_CONE_MALLOC_FAILED \
		"Malloc failed when allocating cone\n"
# define ERR_MISSED_ARGUMENTS_AT_PARSE \
		"Missed arguments at parse\n"

typedef double	t_vector[3];

typedef double	*t_matrix[3];

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
	double		focal_dis;
	t_vector	horizontal;
	t_vector	vertical;
	size_t		count;
	u_int8_t	reflec_depth;
}	t_camera;

typedef struct s_light
{
	t_vector	point;
	double		brightness;
	t_rgba		color;
	size_t		count;
}	t_light;

typedef enum e_figure_type
{
	FT_SPHERE,
	FT_PLANE,
	FT_CYLINDER,
	FT_CONE
}	t_figure_type;

typedef struct line_s
{
	t_vector	point;
	t_vector	orientation;
}	t_line;

typedef enum e_material_type
{
	MTT_INVALID,
	MTT_HOMOG,
	MTT_CHESS,
}	t_material_type;

typedef struct s_chess_ext
{
	t_rgba			color;
}	t_chess_ext;

typedef struct s_material
{
	t_material_type	type;
	char			*name;
	t_rgba			color;
	double			reflec_ratio;
	double			n_sharpness;
	void			*ext_prop;
}	t_material;

typedef struct s_sphere
{
	t_figure_type	ft;
	t_vector		point;
	double			diameter;
	char			*material_id;
	t_material		*material;
}	t_sphere;

typedef struct s_plane
{
	t_figure_type	ft;
	t_vector		point;
	t_vector		orientation;
	char			*material_id;
	t_material		*material;
}	t_plane;

typedef struct s_cylinder
{
	t_figure_type	ft;
	t_vector		point;
	t_vector		orientation;
	double			diameter;
	double			height;
	char			*material_id;
	t_material		*material;
}	t_cylinder;

typedef struct s_cone
{
	t_figure_type	ft;
	t_vector		point;
	t_vector		orientation;
	double			theta;
	double			heights[2];
	char			*material_id;
	t_material		*material;
}	t_cone;

typedef enum e_minirt_type
{
	MRT_INVALID,
	MRT_EMPTY,
	MRT_AMBIENT,
	MRT_CAMERA,
	MRT_LIGHT,
	MRT_MATERIAL,
	MRT_SPHERE,
	MRT_PLANE,
	MRT_CYLINDER,
	MRT_CONE
}	t_minirt_type;

typedef struct s_intersect_data
{
	double			distance;
	int				pos;
	t_plane			tan_plane;
	t_figure_type	ft;
	t_rgba			color;
}	t_intersect_data;

typedef int		(*t_intersect)(t_intersect_data * , t_line , void *);

typedef void	(*t_freeer)(void *);

typedef int		(*t_mat_linker)(void *figure, t_list *mats);

typedef int		(*t_mat_parser)(t_material *, char **, int);	


typedef struct s_minirt_data
{
	t_graphics		*gr_ctx;
	char			*filename;
	int				exit_cmd;
	t_list			*list;
	t_ambient		ambient;
	t_camera		camera;
	t_list			*lights;
	t_list			*figures;
	t_list			*materials_list;
	int				mat_link_nok;
	t_intersect		intersect[4];
	t_rgba			background_color;
}	t_minirt_data;

typedef int		(*t_object_parser)(t_list *, char **);
typedef void	(*t_print)(void *);

void		ft_free_material(void *p);
void		ft_free_figure(void *figure);
int			ft_parse_sphere(t_list *node, char **str_arr);
int			ft_parse_plane(t_list *node, char **str_arr);
int			ft_parse_cylinder(t_list *node, char **str_arr);
int			ft_parse_cone(t_list *node, char **str_arr);
int			ft_parse_ambient(t_list *node, char **str_arr);
int			ft_parse_camera(t_list *node, char **str_arr);
int			ft_parse_light(t_list *node, char **str_arr);
int			ft_parse_material(t_list *node, char **str_arr);
t_material	*ft_find_material(t_list *mats, char *id);
int			ft_link_figure_material(void *figure, t_list *mats);
int			ft_link_materials(t_minirt_data *minirt);
int			ft_create_background(t_minirt_data *minirt);

#endif