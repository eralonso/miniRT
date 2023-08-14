/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:08:52 by omoreno-          #+#    #+#             */
/*   Updated: 2023/08/14 16:28:00 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "../../common.h"

double	ft_quadrat_eq(double coef[3]);
int		inter_plane_line(t_vector res, t_line line, void *figure);
int		inter_sphere_line(t_vector ret, t_line line, void *figure);
int		inter_cyl_line(t_vector ret, t_line line, void *figure);

#endif