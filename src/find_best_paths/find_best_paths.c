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