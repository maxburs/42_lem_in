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

#include <libft.h>
#include <lem_in.h>
#include <string.h>
#include <ft_printf.h>

/*
** finds the first node with the specified property
*/

t_node			*node_with_property(t_node *graph, char const *property)
{
	while (graph->name)
	{
		if (graph->property && ft_strcmp(graph->property, (char*)property) == 0)
			return (graph);
		graph++;
	}
	if (g_flags & FLAG_VERBOSE)
		ft_printf("could not find node with property: %s\n", property);
	return (NULL);
}

/*
** finds the end of the line
*/

char const		*line_end(char const *line)
{
	while (*line != '\n' && *line != '\0')
		line++;
	return (line);
}
