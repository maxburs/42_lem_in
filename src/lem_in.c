/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:31:34 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 19:31:35 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <lem_in.h>
#include <stdlib.h>
#include <limits.h>

int		g_flags;

void	error(char *graph_raw, t_node **graph)
{
	ft_printf("ERROR\n");
	if (graph_raw)
		free(graph_raw);
	free_graph(graph);
	exit(0);
}

int		set_flags(int argc, char **argv)
{
	g_flags = 0;
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		g_flags += FLAG_VERBOSE;
	else if (argc == 2 && ft_strcmp(argv[1], "-vv") == 0)
		g_flags += FLAG_VERBOSE + FLAG_VVERBOSE;
	else if (argc != 1)
	{
		ft_putstr_fd("Bad Argument\n", 2);
		return (1);
	}
	return (0);
}

int		graph_doesnt_connect(t_node *graph)
{
	if (node_with_property(graph, "start")->distance != INT_MAX)
		return (0);
	if (g_flags & FLAG_VERBOSE)
		ft_putstr("graph doesn't connect\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		ants;
	char	*graph_raw;
	t_node	*graph;

	graph_raw = NULL;
	graph = NULL;
	if (set_flags(argc, argv))
		error(graph_raw, &graph);
	graph_raw = get_raw_graph();
	putverbose("\n\e[33;1mraw input:\e[0m\n\n");
	ft_printf("%s\n\n", graph_raw);
	if (validate_raw_graph(graph_raw))
		error(graph_raw, &graph);
	ants = ft_atoi(graph_raw);
	if (build_graph(graph_raw, &graph))
		error(graph_raw, &graph);
	ft_strdel(&graph_raw);
	calc_node_distances(graph);
	if (graph_doesnt_connect(graph))
		error(graph_raw, &graph);
	print_graph(graph);
	if (move_ants(graph, ants))
		error(graph_raw, &graph);
	free_graph(&graph);
	return (0);
}
