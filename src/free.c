/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <lem_in.h>
#include <libft.h>

static void		free_links(t_listm *link)
{
	if (!link)
		return ;
	free_links(link->next);
	free(link);
}

void			free_graph(t_node *graph)
{
	t_node	*graph_head;
	
	graph_head = graph;
	while (graph->name)
	{
		free(graph->name);
		free(graph->property);
		free_links(graph->links);
		graph++;
	}
	free(graph_head);
}