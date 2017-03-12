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

#include <lem_in.h>
#include <libft.h>
#include <ft_printf.h>

t_node	*node_with_property(t_node *graph, char const *property)
{
	while (graph->name)
	{
		if (graph->property && ft_strcmp(graph->property, (char*)property) == 0)
			return (graph);
		graph++;
	}
	return (NULL);
}

void	set_nodes_distances(t_node *graph, int distance)
{
	while (graph->name)
	{
		graph->distance = distance;
		graph++;
	}
}

int		find_best_paths(t_node *graph, int ants,  t_listm **paths_return)
{
	t_listm	*paths;
	t_node	*start;
	t_node	*end;

	paths = NULL;
	start = node_with_property(graph, "start");
	end = node_with_property(graph, "end");
	ft_printf("start: %s\n", start->name);
	ft_printf("end: %s\n", end->name);
	*paths_return = paths;
	UNUSED(ants);
	return (0);
}