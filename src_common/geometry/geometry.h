/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:55:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/04 16:08:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "../common.h"

double				*ft_scale_vector(t_vector res, t_vector a, double s);
double				*ft_substraction(t_vector res, t_vector a, t_vector b);
double				*ft_addition(t_vector res, t_vector a, t_vector b);
double				ft_distance_sq(t_vector a, t_vector b);
double				ft_distance(t_vector a, t_vector b);
double				ft_module(t_vector a);
double				*ft_normalize(t_vector res, t_vector a);
double				ft_dot_product(t_vector a, t_vector b);
double				*ft_cross_product(t_vector res, t_vector a, t_vector b);
double				*ft_vector_create(t_vector v);
double				*ft_vector_fill_unitary(t_vector v, int axis);
double				*ft_vector_unitary(int axis);
double				*ft_vector_dispose(t_vector v);
double				*ft_copy_vector(t_vector dst, t_vector src);
void				camera_rays_v2(t_minirt_data *minirt, t_camera *cam, \
						t_img *img, int size[2]);
t_rgba				raytrace(t_minirt_data *minirt, t_line ray, int depth);
t_intersect_data	get_best_intersect(t_minirt_data *minirt, t_line ray, \
							int exclude);
double				ft_quadrat_eq(double coef[3], int sign);
double				*ft_quadrat_eq2(double coef[3], double roots[2]);
int					ft_take_min_pos_root(double *pos_root, double *roots);
int					ft_take_max_pos_root(double *pos_root, double *roots);
int					inter_plane_line(t_intersect_data *res, \
									t_line line, void *figure);
int					inter_sphere_line(t_intersect_data *ret, \
									t_line line, void *figure);
int					inter_cyl_line(t_intersect_data *ret, \
									t_line line, void *figure);
int					inter_cone_line(t_intersect_data *ret, \
									t_line line, void *figure);
t_line				gen_shadow_ray(t_light *light, \
					t_intersect_data *best, double *dis);
t_line				gen_reflect_ray(t_line ray, t_intersect_data *hit);
double				ft_residual(double num, double offset, double scale);
int					ft_tile(t_vector2d uv, t_chess_ext *chess_ext);
void				ft_rotate(t_vector2d uv, const t_vector2d xy, double angle);
void				ft_spherical_map(double *uv, t_vector point);
void				ft_planar_map(double *uv, t_vector point, t_vector origin, \
									t_vector orientation);
void				ft_cylindrical_map(double *uv, t_vector point, \
									t_vector origin, t_vector orientation);
void				ft_cyl_map(double *uv, t_vector point, \
								const t_cylinder *cyl);
void				ft_cone_map(double *uv, t_vector point, const t_cone *cone);
t_rgba				chess_plane_pick_color(t_vector point, t_vector origin, \
									t_vector orientation, t_material *mat);
t_rgba				chess_sphere_pick_color(t_vector orientation, \
									t_material *mat);
t_rgba				chess_cyl_pick_color(t_vector point, t_vector origin, \
									t_vector orientation, t_material *mat);
t_rgba				chess_cylin_pick_color(t_vector point, \
											const t_cylinder *cyl);
t_rgba				chess_cone_pick_color(t_vector point, const t_cone *cone);
double				ft_limit_cyl_height(double height, const t_cylinder *cyl);
double				ft_limit_cone_height(double height, const t_cone *cone);

#endif