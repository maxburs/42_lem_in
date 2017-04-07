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

static size_t		get_node_count(char const *graph_raw)
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
** also checks to see if the name starts with 'L'
*/

static _Bool		is_name_duplicate(t_node *node_arr, char const *line)
{
	if (line[0] == 'L')
	{
		print_line("invalid name: ", line);
		return (true);
	}
	while (node_arr->name)
	{
		if (node_name_eql(line, node_arr->name))
		{
			print_line("duplicate name: ", line);
			return (true);
		}
		node_arr++;
	}
	return (false);
}

static int			bank_prop(char *graph_raw, char **property)
{
	if (*property != NULL)
	{
		if (g_flags && FLAG_VERBOSE)
		{
			ft_printf("cannot apply 2 properties too a node\n");
			print_line("line: ", graph_raw);
		}
		ft_strdel(property);
		return (-1);
	}
	graph_raw += 2;
	*property = ft_strndup(graph_raw, line_end(graph_raw) - graph_raw);
	if (false == is_prop_valid(*property))
		ft_strdel(property);
	return (0);
}

/*
** also inits links to null
** || !(graph_raw++) is an awful hack
*/

static int			add_node_names(char *graph_raw, t_node *node_arr)
{
	char		*property;
	t_node		*node;

	property = NULL;
	node = node_arr;
	while (true)
	{
		if (graph_raw[0] == '#' && graph_raw[1] == '#')
		{
			if (-1 == bank_prop(graph_raw, &property))
				return (1);
		}
		else if (is_node(graph_raw))
		{
			if (is_name_duplicate(node_arr, graph_raw))
				return (1);
			node->name = ft_strndup(graph_raw, ft_strchri(graph_raw, ' '));
			node->property = property;
			property = NULL;
			node++;
		}
		if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL || !(graph_raw++))
			break ;
	}
	return (0);
}

int					build_graph(char *graph_raw, t_node **graph)
{
	t_node		*node_arr;
	size_t		node_count;

	if (!(node_count = get_node_count(graph_raw)))
	{
		if (g_flags & FLAG_VERBOSE)
			ft_putstr("no rooms found\n");
		return (1);
	}
	if (!(node_arr = (t_node*)malloc(sizeof(t_node) * (node_count + 1))))
		return (1);
	ft_bzero(node_arr, sizeof(t_node) * (node_count + 1));
	*graph = node_arr;
	node_arr[node_count].name = NULL;
	if (add_node_names(graph_raw, node_arr)
		|| add_node_links(graph_raw, node_arr))
		return (1);
	return (0);
}
