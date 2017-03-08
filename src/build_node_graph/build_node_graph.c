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
#include <stdlib.h>
#include <stdbool.h>

#include <ft_printf.h>

static _Bool		is_node(const char *spot)
{
	int		space_count;

	space_count = 0;
	while (*spot++ != '\n' && *spot != '\0')
	{
		if (*spot == ' ')
			space_count++;
	}
	if (space_count != 2)
		return (false);
	return (true);
}

static size_t		get_node_count(const char *graph_raw)
{
	size_t		node_count;

	node_count = 0;
	if (is_node(graph_raw))
		node_count++;
	while ((graph_raw = ft_strchr(graph_raw, '\n')))
	{
		graph_raw++;
		if (is_node(graph_raw))
			node_count++;
	}
	return (node_count);
}

/*
** also inits links to null
*/

static void			get_node_names(char *graph_raw, t_node *node_arr)
{
	char		*property;

	property = NULL;
	while (true)
	{
		if (graph_raw[0] == '#' && graph_raw[1] == '#' && !property)
		{
			graph_raw += 2;
			property = ft_strndup(graph_raw, line_end(graph_raw) - graph_raw);
		}
		else if (is_node(graph_raw))
		{
			node_arr->name = ft_strndup(graph_raw, ft_strchri(graph_raw, ' '));
			node_arr->property = property;
			if (property)
				property = NULL;
			node_arr++;
		}
		if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL)
			break ;
		graph_raw++;
	}
}

/*
** do a string and a line match
*/

static _Bool		node_name_eql(char const *line, char const *str)
{
	while (*line != '\0' && *str != '\0' && *line == *str)
	{
		line++;
		str++;
	}
	if ((*line == '\0' || *line == '\n' || *line == '-') && *str == '\0')
		return (1);
	return (0);
}

/*
** given pointers to the names of two nodes on the graph link them together
*/

static int			add_link(t_node *node_arr, char *name1, char *name2)
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

static int			get_node_links(char *graph_raw, t_node *node_arr)
{
	if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL)
		return (0);
	graph_raw++;
	while (true)
	{
		if (*graph_raw != '#' && !is_node(graph_raw))
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

int					build_node_graph(char *graph_raw, t_node **graph)
{
	t_node		*node_arr;
	size_t		node_count;

	node_count = get_node_count(graph_raw);
	if (!(node_arr = (t_node*)malloc(sizeof(t_node) * (node_count + 1))))
		return (1);
	*graph = node_arr;
	node_arr[node_count].name = NULL;
	get_node_names(graph_raw, node_arr);
	if (get_node_links(graph_raw, node_arr))
		return (1);
	return (0);
}
