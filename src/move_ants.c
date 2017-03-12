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
#include <libft.h>

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
			if (graph[order[i]].distance > graph[order[i + 1]].distance)
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

static void		accept_ant(t_node *node)
{
	t_listm		*link;

	if (node->ant)
		return ;
	link = node->links;
	while (link)
	{
		if (((t_node*)(link->content))->ant
			&& ((t_node*)(link->content))->distance > node->distance)
		{
			node->ant = ((t_node*)(link->content))->ant;
			((t_node*)(link->content))->ant = 0;
			ft_printf("L%d-%s ", node->ant, node->name);
			return ;
		}
		link = link->next;
	}
}

static void		accept_ants_to_end(t_node *node, int *ants_received)
{
	t_listm		*link;

	link = node->links;
	while (link)
	{
		if (((t_node*)(link->content))->ant)
		{
			ft_printf("L%d-%s ", ((t_node*)(link->content))->ant, node->name);
			((t_node*)(link->content))->ant = 0;
			*ants_received = *ants_received + 1;
		}
		link = link->next;
	}
}

int				move_ants(t_node *graph, int ants)
{
	int		*order;
	int		ants_deployed;
	int		ants_received;
	t_node	*start;
	t_node	*end;
	size_t	i;

	start = node_with_property(graph, "start");
	end = node_with_property(graph, "end");
	ants_received = 0;
	ants_deployed = 1;
	start->ant = ants_deployed;
	if (!(order = graph_order(graph)))
		return (1);
	while (ants_received < ants)
	{
		i = 1;
		accept_ants_to_end(end, &ants_received);
		while (order[i] != -1)
		{
			accept_ant(graph + order[i]);
			if (start->ant == 0 && ants_deployed < ants)
			{
				ants_deployed++;
				start->ant = ants_deployed;
			}
			i++;
		}
		ft_putchar('\n');
		//ft_printf("ants received: %d\n", ants_received);
	}
	return (0);
}