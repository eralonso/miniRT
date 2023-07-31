/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:17:34 by omoreno-          #+#    #+#             */
/*   Updated: 2023/07/25 17:18:18 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXTRA_H
# define LIBFT_EXTRA_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft.h"

int		ft_log_error(char *msg);
size_t	ft_linelen(const char *s);
int		ft_every_in_line(char *s, int (*f)(char, char), char arg);
void	*ft_strreduce(char *s, void (*f)(unsigned int, char*, void*), \
				void *acum);
t_list	*ft_lstreverse(t_list **lst);
int		ft_lstevery(t_list *lst, int (*f)(void *, void *), void *arg);
void	ft_lstreduce(t_list *lst, \
		void (*f)(unsigned int, void *, void *), void *arg);
t_list	*ft_lstfindfirst(t_list *lst, \
		int (*f)(unsigned int, void *, void *), void *arg);
void	ft_lstdeletewhere(t_list **lst, \
		int (*is)(unsigned int, t_list *, void *), \
		void (*del)(void *), void *arg);
void	ft_lstdeletenode(t_list **lst, t_list *node);
void	ft_copy_pos(int *dst, int *src);
int		*ft_dup_pos(int *src);
void	ft_set_pos(int *pos, int x, int y);
void	ft_add_pos(int *pos, int *displ);
t_list	*ft_findfirst_with_pos(t_list *lst, int *pos);
char	*ft_str_merge(char **s1, char **s2);
t_list	*ft_lstextract_front(t_list **lst);
void	ft_delete_str_arr(char **str_arr);
#endif