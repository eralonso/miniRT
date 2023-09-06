/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:37:53 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/06 16:23:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "minirt_class/miniRT_data.h"
# include "graph_ctx/graph_decl.h"
# include "utils/utils.h"
# include "geometry/geometry.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

# define DISP_WIDTH		2000
# define DISP_HEIGHT	1090

// Position of width and height in arrays
# define H 0
# define W 1

char			*ft_take_argument(int argc, char const *argv[]);
t_list			*ft_read_map(char *filename);
int				ft_create_graph_ctx(t_minirt_data *minirt);
int				ft_dispose_graph_ctx(t_minirt_data *minirt);
t_minirt_data	*minirt_constructor(char *filename);
t_minirt_data	*minirt_dispose(t_minirt_data **minirt);
t_minirt_data	*ft_init_minirt_data(t_minirt_data *minirt);
t_minirt_type	ft_cast_line_object(t_list *node);
int				ft_draw(t_minirt_data *minirt);
int				ft_handle_no_event(void *data);
int				ft_close(void *param);
int				ft_key_input(int keycode, void *param);
void			ft_pixel_put(t_img *img, int x, int y, t_rgba rgba);
void			ft_print_line(t_vector a, t_vector b, t_rgba color, t_img *img);

#endif