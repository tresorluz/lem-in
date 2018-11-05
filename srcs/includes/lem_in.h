/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:46:09 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 17:31:22 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_room
{
	char		*name;
	int			x_axis;
	int			y_axis;
	int			size;
}				t_room;

typedef struct	s_lem_in
{
	char		**info;
	int			ants;
	char		**links;
	int			**map;
	int			rooms;
	int			link;
	int			start;
	int			end;
	char		*list;
	int			len;
	t_room		*rm;
	int			*rmf;
}				t_lem_info;

t_lem_info		*initialize_struct(void);
void			ft_print_links(t_lem_info *lem);
void			ft_convert_links(t_lem_info *lem);
void			ft_check_match(t_lem_info *lem, char **str, int i, int j);
int				readstore_info(t_lem_info *lem);
int				ft_store(t_lem_info *lem);
void			order_rooms(t_lem_info *lem);
void			store_room(t_lem_info *lem, char *str);
void			store_ants(t_lem_info *lem, char *str);
int				ft_is_in_list(char *node, char *list);
int				get_list_len(t_lem_info *lem);
char			*add_room(t_lem_info *lem, char *list, int rm);
int				count_moves(char *list);
void			move(t_lem_info *lem);
int				move_down (t_lem_info *lem, char *list, int y_axis, int x_axis);
int				move_up (t_lem_info *lem, char *list, int y_axis, int x_axis);
int				move_left (t_lem_info *lem, char *list, int y_axis, int x_axis);
int				move_right (t_lem_info *lem, char *list, int y_axis,
				int x_axis);
void			sort_rooms(t_lem_info *lem);
void			move_ants(t_lem_info *lem);
void			print_ants(t_lem_info *lem, int ant, int rm);
int				move_rec(t_lem_info *lem, int ant, int rm, int count);
int				is_error(t_lem_info *lem);
#endif
