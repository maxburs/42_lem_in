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

int		main(int argc, char **argv)
{
	int		ants;
	char	*graph_raw;
	t_node	*graph;
	//t_node	***paths;

	g_flags = 0;
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		g_flags += FLAG_VERBOSE;
	else if (argc == 2 && ft_strcmp(argv[1], "-vv") == 0)
		g_flags += FLAG_VERBOSE + FLAG_VVERBOSE;
	else if (argc != 1)
	{
		ft_putstr_fd("Bad Argument\n", 2);
		return (0);
	}

	graph_raw = get_raw_graph();
	ft_putstr(graph_raw);
	ft_putstr("\n");
	if (validate_raw_graph(graph_raw))
	{
		free(graph_raw);
		ft_printf("ERROR\n");
		return (0);
	}
	ants = ft_atoi(graph_raw);
	ft_printf("ants: %d\n", ants);
	if (build_graph(graph_raw, &graph))
	{
		ft_printf("ERROR\n");
		free(graph_raw);
		free_graph(graph);
		return (0);
	}
	free(graph_raw);
	print_graph(graph);
	//paths = find_best_paths(&graph);
	//move_ants(paths, ants);
	free_graph(graph);
	return (0);
}
