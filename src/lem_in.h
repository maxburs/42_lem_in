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

typedef struct	s_node
{
	char	*name;
	char	*property;
	t_listm	*links;
	int		path;
}				t_node;

void			print_graph(t_node *node);
void			print_line(char const *title, char const *line);
char const		*line_end(char const *line);
void			free_graph(t_node *graph);

char			*get_raw_graph(void);
int				validate_raw_graph(char *graph_raw);
int				build_node_graph(char *graph_raw, t_node **graph);

#endif
