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
#include <stdlib.h>
#include <libft.h>

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

static int		init_state(t_node *graph, t_state *state)
{
	if (!(state->start = node_with_property(graph, "start"))
		|| !(state->end = node_with_property(graph, "end"))
		|| !(state->order = graph_order(graph)))
		return (1);
	state->ants_received = 0;
	state->ants_deployed = 1;
	state->start->ant = 1;
	return (0);
}

int				move_ants(t_node *graph, int ants)
{
	t_state		state;
	size_t		i;

	if (init_state(graph, &state))
		return (1);
	putverbose("\e[33;1mmoves:\n\n\e[0m");
	while (state.ants_received < ants)
	{
		i = 1;
		accept_ants_to_end(state.end, &state.ants_received);
		while (state.order[i] != -1)
		{
			accept_ant(graph + state.order[i]);
			if (state.start->ant == 0 && state.ants_deployed < ants)
			{
				state.ants_deployed++;
				state.start->ant = state.ants_deployed;
			}
			i++;
		}
		ft_putchar('\n');
	}
	free(state.order);
	return (0);
}
