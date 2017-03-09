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

t_node	*node_with_property(t_node *graph, char const *property)
{
	while (graph->name)
	{
		if (graph->propety && ft_strcmp(graph->property, property) == 0)
			return (graph);
		graph++;
	}
	return (NULL);
}

int		find_best_paths(t_node *graph, t_listm **paths_return)
{
	t_listm	*paths;
	t_node	*start;
	t_node	*end;

	start = node_with_property(graph, "start");
	end = node_with_property(graph, "end");
	ft_printf("start: %s\n", start->name);
	ft_printf("end: %s\n", end->name);
	*paths_return = paths;
}