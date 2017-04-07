/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_node_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:52:37 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 20:52:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <lem_in.h>
#include <stdbool.h>
#include <ft_printf.h>

static _Bool	is_link(const char *spot)
{
	int		hyphen_count;

	if (*spot == '#')
		return (false);
	hyphen_count = 0;
	while (*spot++ != '\n' && *spot != '\0')
	{
		if (*spot == '-')
			hyphen_count++;
	}
	if (hyphen_count != 1)
		return (false);
	return (true);
}

/*
** do a string and a line match
*/

_Bool			node_name_eql(char const *line, char const *str)
{
	while (*line != '\0' && *str != '\0' && *line == *str)
	{
		line++;
		str++;
	}
	if ((*line == '\0' || *line == '\n' || *line == '-' || *line == ' ')
		&& *str == '\0')
	{
		return (true);
	}
	return (false);
}

/*
** given pointers to the names of two nodes on the graph link them together
*/

static int		add_link(t_node *node_arr, char *name1, char *name2)
{
	t_node	*node1;
	t_node	*node2;

	node1 = NULL;
	node2 = NULL;
	while ((!node1 || !node2) && node_arr->name)
	{
		if (node_name_eql(name1, node_arr->name))
		{
			node1 = node_arr;
		}
		if (node_name_eql(name2, node_arr->name))
		{
			node2 = node_arr;
		}
		node_arr++;
	}
	if (!node1 || !node2)
	{
		return (1);
	}
	ft_lstmadd_b(&(node1->links), node2);
	ft_lstmadd_b(&(node2->links), node1);
	return (0);
}

int				add_node_links(char *graph_raw, t_node *node_arr)
{
	if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL)
		return (0);
	graph_raw++;
	while (true)
	{
		if (*graph_raw != '#' && is_link(graph_raw))
		{
			if (add_link(node_arr, graph_raw, ft_strchr(graph_raw, '-') + 1))
			{
				print_line("error adding link: ", graph_raw);
				return (1);
			}
		}
		if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL)
			break ;
		graph_raw++;
	}
	return (0);
}
