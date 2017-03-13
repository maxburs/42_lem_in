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

_Bool				is_node(const char *spot)
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

static _Bool		is_name_duplicate(t_node *node_arr, char const *line)
{
	while (node_arr->name)
	{
		if (node_name_eql(line, node_arr->name))
		{
			print_line("duplicate name: ", line);
			return (true);
		}
	}
	return (false);
}

/*
** also inits links to null
*/

static int			add_node_names(char *graph_raw, t_node *node_arr)
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
			if (is_name_duplicate(node_arr, graph_raw))
				return (1);
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
