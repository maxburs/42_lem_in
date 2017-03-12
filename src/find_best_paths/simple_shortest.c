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
#include <limits.h>
#include <string.h>

static void		set_paths_to_distance(t_node *node, int distance)
{
	t_listm		*link;

	if (distance >= node->path)
		return ;
	node->path = distance;
	distance++;
	link = node->links;
	while (link)
	{
		set_paths_to_distance(link->content, distance);
		link = link->next;
	}
}

int				simple_shortest(t_node *graph, t_listm **paths_return)
{
	t_listm		*path;

	path = NULL;
	set_nodes_paths(graph, INT_MAX);
	set_paths_to_distance(node_with_property(graph, "end"), 0);
	*paths_return = path;
	return (0);
}