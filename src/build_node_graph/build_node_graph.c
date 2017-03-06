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

static void			get_node_names(char *graph_raw, t_node *node_arr)
{
	char		*property;

	property = NULL;
	while (true)
	{
		print_line("getting names: ", graph_raw);
		if (graph_raw[0] == '#' && graph_raw[1] == '#' && !property)
		{
			graph_raw += 2;
			property = ft_strndup(graph_raw, line_end(graph_raw) - graph_raw);
		}
		else if (is_node(graph_raw))
		{
			node_arr->name = ft_strndup(graph_raw,
											ft_strchri(graph_raw, ' '));
			if (property)
			{
				node_arr->property = property;
				property = NULL;
			}
			else
				node_arr->property = NULL;
			node_arr++;
		}
		if ((graph_raw = ft_strchr(graph_raw, '\n')) == NULL)
			break ;
		ft_printf("hello\n");
		graph_raw++;
	}
}

int					build_node_graph(char *graph_raw, t_node **graph)
{
	//char	*ptr;
	t_node		*node_arr;
	size_t		node_count;

	node_count = get_node_count(graph_raw);
	ft_printf("node count: %zu\n", node_count);
	if (!(node_arr = (t_node*)malloc(sizeof(t_node) * node_count)))
		return (1);
	ft_printf("test\n");
	*graph = node_arr;
	node_arr[node_count].name = NULL;
	ft_printf("test\n");
	get_node_names(graph_raw, node_arr);
	ft_printf("hello\n");
	return (0);
}
