/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:55:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/01 19:22:20 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include "../common.h"

float		ft_inv_sqrt(float value);
double		*ft_scale_vector(t_vector res, t_vector a, double s);
double		*ft_substraction(t_vector res, t_vector a, t_vector b);
double		*ft_addition(t_vector res, t_vector a, t_vector b);
double		ft_distance_sq(t_vector a, t_vector b);
double		ft_distance(t_vector a, t_vector b);
double		ft_module(t_vector a);
double		*ft_normalize(t_vector res, t_vector a);
double		ft_dot_product(t_vector a, t_vector b);
double		*ft_cross_product(t_vector res, t_vector a, t_vector b);
double		**ft_matrix_add(t_matrix res, t_matrix a, t_matrix b);
double		*ft_vector_create(t_vector v);
double		*ft_vector_unitary(int axis);
double		*ft_vector_dispose(t_vector v);
double		**ft_matrix_create(t_matrix m);
double		**ft_matrix_identity(void);
double		**ft_matrix_rotation(int axis, double theta);
double		**ft_matrix_transpose(t_matrix m);
double		**ft_matrix_dispose(t_matrix m);
double		*ft_matrix_x_vector(t_matrix m, t_vector v);
double		**ft_matrix_x_matrix(t_matrix a, t_matrix b);

#endif