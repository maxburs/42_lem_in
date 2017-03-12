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

#include <lem_in.h>
#include <ft_printf.h>
#include <stdbool.h>
#include <stdlib.h>

static size_t	get_node_count(t_node *graph)
{
	size_t	count;

	count = 0;
	while (graph->name)
	{
		count++;
		graph++;
	}
	return (count);
}

static int		*build_init_order(size_t size)
{
	int		*order;

	if (!(order = (int*)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	order[size] = -1;
	while (size)
	{
		size--;
		order[size] = size;
	}
	return (order);
}

int				*graph_order(t_node *graph)
{
	int		swap;
	_Bool	change_made;
	int		*order;
	size_t	i;

	if (!(order = build_init_order(get_node_count(graph))))
		return (NULL);
	change_made = true;
	while (change_made)
	{
		change_made = false;
		i = 0;
		while (order[i + 1] != -1)
		{
			if (graph[order[i]].distance < graph[order[i + 1]].distance)
			{
				swap = order[i];
				order[i] = order[i + 1];
				order[i + 1] = swap;
				change_made = true;
			}
			i++;
		}
	}
	i = 0;
	while (order[i] != -1)
	{
		ft_printf("%d: %s\n", i, graph[order[i]].name);
		i++;
	}
	return (order);
}

int				move_ants(t_node *graph, int ants)
{
	free(graph_order(graph));
	UNUSED(ants);
	return (0);
}