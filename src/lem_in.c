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

int		g_flags;

void	error(char *graph_raw, t_node **graph, t_listm *paths)
{
	ft_printf("ERROR\n");
	if (graph_raw)
		free(graph_raw);
	if (graph)
		free_graph(graph);
	//todo: make free paths
	//if (paths)
	//	free_paths(paths);
	UNUSED(&paths);
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

int		main(int argc, char **argv)
{
	int		ants;
	char	*graph_raw;
	t_node	*graph;
	t_listm	*paths;

	graph_raw = NULL;
	graph = NULL;
	paths = NULL;
	if (set_flags(argc, argv))
		error(graph_raw, &graph, paths);

	graph_raw = get_raw_graph();
	ft_putendl(graph_raw);
	if (validate_raw_graph(graph_raw))
		error(graph_raw, &graph, paths);
	ants = ft_atoi(graph_raw);
	if (build_graph(graph_raw, &graph))
		error(graph_raw, &graph, paths);
	ft_strdel(&graph_raw);
	print_graph(graph);
	if (find_best_paths(graph, &paths))
		error(graph_raw, &graph, paths);
	print_paths(paths);
	//move_ants(paths, ants);
	free_graph(&graph);
	return (0);
}
