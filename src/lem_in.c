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
	char	*graph_raw;
	t_node	*graph;
	size_t	node_count;

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
		ft_printf("ERROR\n");
		return (0);
	}
	build_node_graph(graph_raw, &graph, &node_count);
	free(graph_raw);
	//organize_node_graph(&graph);
	//move_ants(graph);
	free(graph);
	return (0);
}
