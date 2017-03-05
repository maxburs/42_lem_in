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
	char const	*ptr;

	node_count = 0;
	ptr = graph_raw;
	if (is_node(ptr))
		node_count++;
	while ((ptr = ft_strchr(ptr, '\n')))
	{
		ptr++;
		if (is_node(ptr))
			node_count++;
	}
	return (node_count);
}

int					build_node_graph(char *graph_raw,
							t_node **graph, size_t *node_count)
{
	//char	*ptr;
	t_node		*node_arr;

	*node_count = get_node_count(graph_raw);
	ft_printf("node count: %zu\n", *node_count);
	if (!(node_arr = (t_node*)malloc(sizeof(t_node) * *node_count)))
		return (1);
	*graph = node_arr;
	return (0);
}
