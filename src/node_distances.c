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

void	set_nodes_distances(t_node *graph, int distance)
{
	while (graph->name)
	{
		graph->distance = distance;
		graph++;
	}
}

void	calc_node_distances(t_node *node, int distance)
{
	t_listm		*link;

	if (distance >= node->distance)
		return ;
	node->distance = distance;
	distance++;
	link = node->links;
	while (link)
	{
		calc_node_distances(link->content, distance);
		link = link->next;
	}
}