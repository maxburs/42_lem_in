/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:34:28 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 19:34:29 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>

extern int		g_flags;

# define FLAG_VERBOSE 0x1
# define FLAG_VVERBOSE 0x2
# define BUFF_SIZE 64
# define ROOM_NAME_EXCLUDES " \n-"

# define UNUSED(x) (void)(x)

typedef struct	s_node
{
	char	*name;
	char	*property;
	t_listm	*links;
	int		distance;
	int		ant;
}				t_node;

void			print_line(char const *title, char const *line);
char const		*line_end(char const *line);
void			free_graph(t_node **graph_head);
void			print_graph(t_node *node);


/*
** ./build_graph/
*/

int				build_graph(char *graph_raw, t_node **graph);
char			*get_raw_graph(void);
int				validate_raw_graph(char *graph_raw);
_Bool			is_node(const char *spot);
int				add_node_links(char *graph_raw, t_node *node_arr);
_Bool			node_name_eql(char const *line, char const *str);

/*
** ./find_best_paths/
*/

int				find_best_paths(t_node *graph, int ants,
													t_listm **paths_return);
t_node			*node_with_property(t_node *graph, char const *property);
void			set_nodes_distances(t_node *graph, int path);
void			calc_node_distances(t_node *node, int distance);

#endif
