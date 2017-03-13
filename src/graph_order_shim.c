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
#include <string.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <stdbool.h>

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

static void		print_shim(t_node *graph, int *shim)
{
	size_t	i;

	if (!(g_flags & FLAG_VERBOSE))
		return ;
	i = 0;
	ft_putstr("\e[33;1mnode order shim:\e[0m\n\n");
	while (shim[i] != -1)
	{
		ft_printf("   %d: %s\n", i, graph[shim[i]].name);
		i++;
	}
	ft_putchar('\n');
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
	print_shim(graph, order);
	return (order);
}